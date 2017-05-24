#include "my_head.h"
class SortInfo{
    public:
    SortInfo( string _name="", int _age=0 ):name(_name),age( _age ){}
    ~SortInfo(){}
    friend ostream& operator<< ( ostream& os,  const SortInfo& demo );
    private:
        string name;
        int    age; 
};
ostream& operator<<( ostream&os,  const SortInfo& demo )
{
    os<<"姓名："<<demo.name<<"\t"<<"年龄:"<<demo.age<<endl;
    return os;
}
int main( int argc, char**argv )
{
    Queue<int> demo(10);
    demo.EnQueue( 1 );
    demo.EnQueue( 2 );
    demo.EnQueue( 3 );
    demo.EnQueue( 4 );
    demo.EnQueue( 5 );
    demo.EnQueue( 6 );
    demo.EnQueue( 7 );
    demo.DisplayQueue();
    cout<<demo.QueueLength()<<endl;
    int  test = 0;
    demo.DeQueue( test );
    demo.DisplayQueue();
    cout<<demo.QueueLength()<<endl;
    cout<<test<<endl;

    Queue<string> *mptr = new Queue<string>(8);
    string s1("aaaaa");
    string s2( 10, 'b' );
    string s3=s1+s2;
    string s4=s3+"fff";
    string s5=s1.substr( 0, 2 );
    char  a[]="abcdefg";
    string s6( a, a+7 );
    string s7( s6.begin(), s6.end() );
    string::size_type pos2 = s6.find( "e" );
    string s8 = s6.substr( 0, pos2 );
    mptr->EnQueue( s1 );
    mptr->EnQueue( s2 );
    mptr->EnQueue( s3 );
    mptr->EnQueue( s4 );
    mptr->EnQueue( s5 );
    mptr->EnQueue( s6 );
    mptr->EnQueue( s7 );
    mptr->EnQueue( s8 );
    mptr->DisplayQueue();
    cout<<mptr->QueueLength()<<endl;
    string t1;
    mptr->DeQueue( t1 );
    mptr->DisplayQueue();
    cout<<mptr->QueueLength()<<endl;
    cout<<t1<<endl;

    Queue<SortInfo> *sort_ptr = new Queue<SortInfo>( 5 );
    SortInfo a1( "zhangsan", 18 );
    SortInfo a2( "wangwu", 18 );
    SortInfo a3( "lisi", 18 );
    SortInfo a4( "zhaoliu", 18 );
    SortInfo a5( "zhuqi", 18 );
    SortInfo a6( "fuckkk", 18 );
   
    sort_ptr->EnQueue( a1 );
    sort_ptr->EnQueue( a2 );
    sort_ptr->EnQueue( a3 );
    sort_ptr->EnQueue( a4 );
    sort_ptr->EnQueue( a5 );
    sort_ptr->EnQueue( a6 );
   
    sort_ptr->DisplayQueue();
     
    SortInfo a7;
    sort_ptr->DeQueue( a7 );

    sort_ptr->DisplayQueue();

    cout<<a7<<endl;

    delete sort_ptr; 
    delete mptr; 

    return 0;
}
