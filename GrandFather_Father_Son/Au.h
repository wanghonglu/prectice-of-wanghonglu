#ifndef AU_H
#define AU_H
#include<iostream>
using namespace std;
class Grand_father
{
public : 
       int a;
       void fun1();
#if 0
       Grand_father( int b )
       {
           a = b;
           cout<<"Grand_father"<<a<<endl;
       }
#endif 
};
class Father : public Grand_father
{
public:
      int b;
      virtual void fun2();
#if 0
      Father( int c ):Grand_father( c ) 
      {
          b = c;
          cout<<"Father"<<b<<endl;
      }
#endif
};
class Son : public Father
{
public:
      int c;
      virtual void fun2();
#if 0
      Son( int m ):Father(9)
      {
          c = m;
          cout<<"Son"<<endl;
      }
#endif 
};
#endif
