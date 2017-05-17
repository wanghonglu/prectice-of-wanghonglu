#ifndef MY_HEAD
#define MY_HEAD
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cerrno>
#include<cstdlib>
#include<ctime>
using namespace std;
static string error;

#include "demo.h"
template <typename T>
class Stack
{
    public:
		Stack( int size );    /* 构造函数 确定栈的大小、容量、栈顶 */
		~Stack();             /* 回收栈空间内存 */
		bool stackempty();    /* 判断栈是否为空 */
		bool stackfull();     /* 判断栈是否为满 */
		void clearstack();    /* 清空栈 */
		int  stacklength();   /* 统计已有元素的个数 */
		void push( T& elem ); /* 压入栈一个数据 栈顶压入 */
		void pop( T&  elem ); /* 弹出栈里一个数据，栈顶下降 */
		void display_stack( int flag ); /* 打印栈里的所有元素， 0 从栈顶到栈底 1 从栈底到栈顶 */
		T    get_stack_top();
    private:
		T    *m_ptr;   /* 指向栈空间 */
		int  m_size;  /* 栈的容量 */
		int  m_top;   /* 栈中已有元素，栈顶 */

};
template <typename T >
Stack<T>::Stack( int size )
{
    m_size = size;
    m_ptr = new T[size];
	m_top = 0;
}
template <typename T >
Stack<T>::~Stack()
{
	cout<<"desctruct"<<endl;
    delete []m_ptr;
}
template <typename T >
bool Stack<T>::stackempty()
{
    return m_top == 0?true:false;
}
template <typename T >
bool Stack<T>::stackfull()
{
    return m_top == m_size?true:false;
}
template <typename T >
void Stack<T>::clearstack()
{
    m_top = 0;
}
template <typename T >
int Stack<T>::stacklength()
{
    return m_top;
}
template <typename T >
void Stack<T>::push( T& elem )
{
    try
    {
        if( stackfull() )
        {
            error.insert(0, "the stack is full ,can not push anymore" );
            throw error;
        }
        m_ptr[m_top] = elem;
        m_top++;
    }
    catch( string &error )
    {
        std::cout<<error<<std::endl;
        return ;
    }
}
template <typename T >
void Stack<T>::pop( T& elem )
{
    try
    {
        if( stackempty() )
        {
            error.insert( 0,"the stack is empty ,can not pop " );
            throw error;
        }
        elem = m_ptr[m_top-1];
        m_top--;
    }
    catch( string &error )
    {
        std::cout<<error<<std::endl;
        return ;
    }
}
template <typename T >
void Stack<T>::display_stack( int flag )
{
    int i = 0;
    try{
    switch( flag)
    {
        case 0:
        {
            for( i=m_top-1;i>=0;i-- )
                //std::cout<<m_ptr[i]<<" ";
                //m_ptr[i].display();
                cout<<m_ptr[i];
        }break;
        case 1:
        {
            for( i=0;i<m_top;i++ )
            cout<<m_ptr[i]<<endl;
        }break;
        default:
           error.insert( 0, "display flag error" );
           throw error;
           break;
    }
    }
    catch( string &error )
    {
        std::cout<<error<<std::endl;
        return ;
    }
    printf( "\n" );

}
template<typename T>
T Stack<T>::get_stack_top()
{
	return m_ptr[m_top-1];
}

#endif
