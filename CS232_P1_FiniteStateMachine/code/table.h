// FileName  : table.h
// programmer: Jeffrey Marron & B. Streller
// definition of the table class

#ifndef  TABLE_H
#define  TABLE_H

#include <stdexcept>
#include <string>
#include "pair.h"		// Pair class

template < class Key, typename T, typename J >
class Table{

  public:
    typedef Key key_type;

  private:
    // table implemented using a one dimensional array of key-value pairs
    int tableSize;
    Pair< key_type, T, J > the_table[7][5];
	string inFilename;
    int (*Mapping)( Key k);
	int temp;
	string str;
	char iTemp[10];
  public:
	string getFileName(ifstream&, string & inFilename);

    void   print();
	void   getAtInfo();
    Table(int (*map)( Key k)  );
	void   clear();

    bool insert(  Pair<  Key, T, J >  kvpair );

    bool remove(  const Key  aKey );

    int  lookUp(Pair<Key, T, J> kvpair, int & temp);
};

#include "table.t"


#endif
