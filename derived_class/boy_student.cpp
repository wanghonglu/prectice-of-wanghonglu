#include "boy_student.h"
void boy_student::show_fun2()
{
   cout<<"boy_student"<<endl;
}
int main()
{
    student A;
    boy_student B;
    A.show_fun1();
    B.show_fun1();
    B.show_fun2();

    return 0;
}
