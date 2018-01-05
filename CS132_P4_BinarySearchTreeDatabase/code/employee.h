// FileName  : employee.h
// programmer : J. Marron
// definition of the employee struct
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct employee {
public:
	string firstName, lastName, ssn;
	int age, dependents, ol;
	char eCode;
	double salary, hours, pay;

	////// overloaded operators //////
	friend ostream& operator<<(ostream& os, const employee& temp);

	friend ifstream& operator>>(ifstream& is, const employee& temp);

	//each comparison operator has a check to ol (overload) which acts like a switch
	//allows the tree to evaluate different members of the employee struct
	bool operator < (const employee& rhs) {
		if (ol == 666){return lastName < rhs.lastName; }
		else return ssn < rhs.ssn;}

	bool operator > (employee& rhs){
		if (ol == 666) { return lastName > rhs.lastName; }
		else return ssn > rhs.ssn;}

	bool operator >= (const employee& rhs){
		if (ol == 666) { return lastName >= rhs.lastName; }
		else return ssn >= rhs.ssn;
	}

	bool operator == (const employee& rhs){
		if (ol == 666) { return lastName == rhs.lastName; }
		else return ssn == rhs.ssn;
	}

	bool operator != (const employee& rhs){
		if (ol == 666) { return lastName != rhs.lastName; }
		else return ssn != rhs.ssn;
	}

	employee & employee::operator = (const employee& rhs){
		if (this == &rhs)
			return *this;
		lastName = rhs.lastName; firstName = rhs.firstName; ssn = rhs.ssn; age = rhs.age;
		dependents = rhs.dependents; eCode = rhs.eCode; salary = rhs.salary; hours = rhs.hours;
			return *this;}};

ostream& operator<<(ostream& os, const employee& temp) {
os.width(10); os << left << temp.firstName << ' '; os.width(15); os << left << temp.lastName << ' ';
os.width(13); os << left << temp.ssn << ' '; os.width(4); os << left << temp.age << ' ';
os.width(4); os << left << temp.dependents << ' '; os.width(4); os << left << temp.eCode << ' ';
os.width(6); os << left << fixed << setprecision(2) << temp.salary << ' ';
os.width(6); os << left << fixed << setprecision(2) << temp.hours << ' ' << 
temp.salary * temp.hours << endl; //outputs calculated pay
		return os;}
////// END overloaded operators  //////
#endif
