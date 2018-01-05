#ifndef PAIR_H
#define PAIR_H

// more or less from STL library
// found in <utility> and <pair>

template< class T1, class T2, class T3>
class Pair
  {
  public:

    T1 first;
    T2 second;
	T3 third;

    // default constructor
    Pair(): first( T1() ), second( T2() ), third(T3()){ }

    // constructor that initializes first and second
    Pair(  const T1 v1,  const T2 v2, const T3 v3):
        first(v1), second(v2), third(v3){ }

    //copy constructor
    template< typename U1, typename U2, typename U3 >
    Pair ( const Pair<U1,U2, U3>& X)
        : first( X.first ),  second( X.second ), third( X.third ){}

    // overload <=
    template< typename U1, typename U2, typename U3 >
    Pair& operator= ( const  Pair<U1,U2,U3>& init ){
      return *this = Pair(init);}

    // overload <
    friend bool operator< ( const Pair<T1,T2,T3>& lhs, const Pair<T1,T2,T3>& rhs ){
      return lhs.first < rhs.first || !( rhs.first < lhs.first  && lhs.second < rhs.second   );}

    // overload ==
    friend bool operator== ( const Pair<T1,T2,T3>& lhs, const Pair<T1,T2,T3>& rhs ){
      return lhs.first == rhs.first && lhs.second == rhs.second ;}};

template< class T1, class T2, class T3 >
Pair<T1,T2,T3> makePair(  const T1& v1,  const T2& v2, const T3& v3){
  return  Pair< T1, T2, T3>(v1,v2,v3);}

#endif