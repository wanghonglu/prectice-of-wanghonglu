#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include "array_tree.h"
#include<string>
using namespace std;
int main( int argc, char** argv )
{
    string  s1("abc");
    ArrayTree<string> *m_ptr = new ArrayTree<string>( 10,s1 );

    string s2( "ccc" ), s3( "ddd" );
    m_ptr->Add_tree( 0, 0, s2 ); 
    m_ptr->Add_tree( 0, 1, s3 ); 
    
    string s4( "eee" ), s5( "fff" );
    m_ptr->Add_tree( 1, 0, s4 ); 
    m_ptr->Add_tree( 1, 1, s5 ); 

    string s6( "ggg" ), s7( "hhh" );
    m_ptr->Add_tree( 2, 0, s6 ); 
    m_ptr->Add_tree( 2, 1, s7 ); 

    m_ptr->Display();

    string s8;
    m_ptr->Delete_tree( 4, s8 );
    cout<<s8<<endl;
    m_ptr->Display();

    string s9;
    m_ptr->Search( 3,s9 );
    cout<<s9<<endl;


    delete m_ptr;
    m_ptr = NULL;
    return 0;
}
