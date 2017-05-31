#include "tree.h"
int main( int argc, char** argv )
{
	string ss1( "aaaaa1" );
	string ss2( "aaaaa2" );
	string ss3( "aaaaa3" );
	string ss4( "aaaaa4" );
	string ss5( "aaaaa5" );
	Node<string>s1( ss1, 1 );
	Node<string>s2( ss2, 2 );
	Node<string>s3( ss3, 3 );
	Node<string>s4( ss4, 4 );
	Node<string>s5( ss5, 5 );

	Tree<string> demo;

	cout<<demo.AddNode( 0, 0, &s1 )<<endl;
	cout<<demo.AddNode( 0, 1, &s2 )<<endl;;
	demo.AddNode( 1, 0, &s3 );
	demo.AddNode( 1, 1, &s4 );
	demo.AddNode( 2, 0, &s5 );

	demo.PrintRoot();

	cout<<"add end"<<endl;
	demo.ProriDisplay();
	cout<<endl;
	demo.MidDisplay();
	cout<<endl;
//	demo.PostDisplay();

	return 0;
}
