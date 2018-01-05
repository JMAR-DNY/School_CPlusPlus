// FileName   : boat.h
// programmer : J. Marron
// definitions of the boat class

#ifndef BOAT_H
#define BOAT_H
#include <iostream>

using std::cout;
using std::endl;

class boat
  {
  public:
    boat();
    boat(double,double,double,int);
    ~boat();
    void speed(double);
    void display();
  private:
    double length,
    width,
    depth;
    int oars;
  };



#endif


