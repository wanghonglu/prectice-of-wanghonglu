#include<iostream>
using namespace std;
int a()
{
    cout<<"aaaaa"<<endl;
    return 9;
}
int main( int avgc, char * avgv[] )
{
    int (*f)();
    f = a;
    (*f)();
    return 0;

}
