#include<iostream>
using namespace std;
class Ca
{
    public:
        int a;
};
class Cb : virtual public Ca
{
};
class Cc : virtual public Ca
{
};
class Cd : public Cc , public Cb
{
};
int main()
{
    /*
    Cd d;
    cout<<d.a<<endl;
*/
    cout<<sizeof( Ca )<<endl;
    cout<<sizeof( Cb )<<endl;
    cout<<sizeof( Cc )<<endl;
    cout<<sizeof( Cd )<<endl;



    return 0;
}
