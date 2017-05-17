#include "my_head.h"
#include "demo.h"
#include<cstring>
#include<cstdlib>
bool judge( char* );
int main( int argc, char **argv )
{
#if 0
	Stack<int> a(5);
	cout<<"a 的地址:"<<static_cast<const void*>(&a)<<endl;
	int b=10,c=11,d=12,e=13;
    a.push( b  );
    a.push( c  );
    a.push( d );
    a.push( e );
	std::cout<<a.stacklength()<<std::endl;
	a.display_stack( 0 );
	a.display_stack( 1 );

	std::cout<<"begin"<<std::endl;
	Stack<int> t(5);
	cout<<"t 的地址:"<<static_cast<const void*>(&t)<<endl;
    t.push( c  );
    t.push( d  );
    t.push( b );
    t.push( e );
	std::cout<<t.stacklength()<<std::endl;
	t.display_stack( 0 );
	t.display_stack( 1 );

	Stack<DEMO> *ptr =new Stack<DEMO>( 5 );
	cout<<"*ptr 的地址:"<<static_cast<const void*>(ptr)<<endl;
	DEMO a1( 2,3 ),b1( 3,4),c1( 5,6 ), d1( 7,8 );
	ptr->push( a1 );
	ptr->push( b1 );
	ptr->push( c1 );
	ptr->push( d1 );
	std::cout<<ptr->stacklength()<<std::endl;
	ptr->display_stack( 0 );
	ptr->display_stack( 1 );
	DEMO e1;
	e1.display();
	ptr->pop( e1 );
	e1.display();
	delete ptr;

	cout<<"string"<<endl;
	Stack<string> *mptr = new Stack<string>( 3 );
	cout<<"*mptr 的地址:"<<static_cast<const void*>(mptr)<<endl;
	string s1( "ajfskfj" ), s2( 10,'g' ),s3=s1+s2;
	mptr->push( s1 );
	mptr->push( s2 );
	mptr->push( s3 );
	std::cout<<mptr->stacklength()<<std::endl;
	mptr->display_stack( 0 );
	mptr->display_stack( 1 );
	string s4;
	cout<<s4<<endl;
    mptr->pop( s4 );
	cout<<s4<<endl;

	delete mptr;
#endif
	/* 栈应用1  用栈计算十进制转二进制八进制16进制 */
	/* 用堆栈做10进制转八进制 十六进制 二进制的算法 */
#if 0
	int   num,tmp, mod, i ,elem = 0, j;
	int   ary[]={ 2,8,16 };
	char   str[]="0123456789ABCDEF";
	Stack<int> *ptr = new Stack<int>(30);
	cout<<"input a number "<<endl;
	cin>>num;
    tmp = num;
	for( i=0;i<3;i++ )
	{
		num = tmp;
		ptr->clearstack();
		while( num )
		{
            mod = num%ary[i];
			ptr->push( mod );
			num/=ary[i];
		}
        switch( i )		
		{
			case 0:
			cout<<"the number: "<<tmp<<" 2进制为:";
			ptr->display_stack(0);
			cout<<endl;
			break;
			case 1:
			cout<<"the number: "<<tmp<<" 8进制为:";
			ptr->display_stack(0);
			cout<<endl;
			break;

			default:
			cout<<"the number: "<<tmp<<" 16进制为:";
			while( !ptr->stackempty() )
			{
				ptr->pop( elem );
				cout<<str[elem];
			}
			cout<<endl;
			break;
		}
		}
#endif
	/* 利用栈来计算给出的字符中括号是否匹配 */
	if( judge( argv[1]  ) )
		cout<<argv[1]<<" 的括号是匹配的"<<endl;
	else
		cout<<argv[1]<<" 的括号是不匹配的"<<endl;

	char a[]="([])";
	judge(a) ==true?cout<<a<<" 的括号是匹配的"<<endl:cout<<a<<" 的括号是不匹配的"<<endl;

	return 0;
}
bool judge( char* str )
{
    if( str == NULL )
	    return false;
    Stack<char> *symple = new Stack<char>( strlen( str ) );	
	char left = 0;
	char right = 0;
	while( *str )
	{
	    switch( *str )
		{
		    case '[':
			case '{':
			case '(':
            symple->push( *str );
			break;
			case ']':
			case ')':
			case '}':
			if( symple->stackempty() )
			    return false;
			left = symple->get_stack_top();
            switch( left )
            {
				case '[':
                right = ']';
                break;
				case '(':
                right = ')';
                break;
				case '{':
                right = '}';
                break;
            }
			if( right == *str )
			    symple->pop( left );
			else
			    return false;
			break;
			default:
			cerr<<"input err!"<<endl;
			exit( 0 );
			break;
		}
		str++;
	}
	if( symple->stackempty() )
		return true;
	else
		return false;
}


