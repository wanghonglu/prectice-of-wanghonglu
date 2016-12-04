#ifndef Cu_class_H
#define Cu_class_H
#include<iostream>
//using namespace std;
class Cu
{
public :
        int    b;
        char   name[ 30 ];
public:
friend  std::istream & operator >> ( std::istream &is, Cu &a );
friend  std::ostream & operator << ( std::ostream &os, Cu &a );  
};
#endif
