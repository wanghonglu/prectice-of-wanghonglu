#include "Au.h"
int main()
{
   Son a;
/*
   a.fun1();
   a.fun2();
   a.fun3();
*/
  Father *p = new Son;
  p->fun2();
   

  return 0;
}
