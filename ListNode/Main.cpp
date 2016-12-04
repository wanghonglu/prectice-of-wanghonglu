/************************************************************************* > 
 * File Name: Main.cpp > 
 * Author: zll >
 * Mail: zhnllion@126.com >
 * Created Time: Sat 03 Dec 2016 03:10:50
 * AM PST ************************************************************************/ 
#include "ListNode.h" 
int main( int argc, char *argv[])
{
	FILE  *fp = NULL;
	int i = 0; 
	int  m[10];
	int  n[10];
	char a[ 100 ];
	memset( m, 0x00, sizeof( m ) ); 
	memset( n, 0x00, sizeof( n ) );
	fp = fopen( "/home/wanghonglu/prectice/ListNode/test.txt", "r"); 
	fgets( a, 100, fp ); 
   	rewind( fp ); 
	cout<<a<<endl;
	 while( i<10 )
	 {
		 fscanf( fp, "%d", m+i );
		 i++;
	 }
	 //fgets( b, 100, fp );
	 //cout<<b<<endl;
	 i = 0 ;
	 while( i<10 )
	 {
		 fscanf( fp, "%d", n+i );
		 i++;
	 }
	 fclose( fp );
	 i = 0;
	 while( i<10 )
	 {
		 cout<<m[ i ]<<"  ";
         i++;
	 }
	 cout<<endl;
	 i = 0;
	 while( i<10 )
	 {
		 cout<<n[ i ]<<"  ";
         i++;
	 }
	 cout<<endl;

	 ListNode *p1 = NULL, *p2 = NULL;
	 p1 = p1->creat( m, 10 );
	 p2 = p2->creat( n, 1  );
	 cout<<"ListNode play"<<endl;
	 p1->display( p1 );
	 p2->display( p2 );

	 cout<<"reverse"<<endl;
	 p1 = p1->verse( p1 );
	 p2 = p2->verse( p2 );

	 cout<<"ListNode play"<<endl;
	 p1->display( p1 );
	 p2->display( p2 );

	 ListNode *p3 = NULL;
	 p3 = p3->add_listnode( p1, p2 );
	 p3->display( p3 );





	return 0;
}

