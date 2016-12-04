#include <iostream>
using namespace std; 
typedef void(*Fun)(void);
class B
{
  public :
         virtual void funa(){ cout<<"funa"<<endl ;}
         virtual void funb(){ cout<<"funb"<<endl ;}
         virtual void func(){ cout<<"func"<<endl ;}

};
int main()
{
    B b;
    cout<<&b<<endl;
    cout<<*(&b)<<endl;
    void (*f)();

    f =(f)* (&b);
    (*f)();
    return 0;
}
