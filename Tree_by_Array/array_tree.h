#ifndef ARRAY_TREE_H
#define ARRAY_TREE_H
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
template <typename T>
class ArrayTree{
    public:
        ArrayTree( int size, T& root );
        ~ArrayTree();
        bool Add_tree( int index, int director, T& node );  //0--左子树 1--右子树
        bool Delete_tree( int index, T& node );
        T& Search( int index, T& node  );
        void Display();
    private:
        T   *ptr;
        int max_size;
};
template<typename T>
ArrayTree<T>::ArrayTree( int size, T& root )
{
    max_size = size;
    ptr = new T[size];
    memset( ptr, 0x00, sizeof( T ) );
    ptr[0] = root;
}
template<typename T>
ArrayTree<T>::~ArrayTree()
{
    delete[]ptr;
}
template<typename T>
bool ArrayTree<T>::Add_tree( int index, int director, T& node )
{
    if( index<0 || index>max_size )
        return NULL;
    if( director == 0 )
    {
        if( index*2+1 >max_size )
        {
            cerr<<"out of range"<<endl;
            return NULL;
        }
        ptr[index*2+1]=node;
    }
    else if( director == 1 )
    {
        if( index*2+2 >max_size )
        {
            cerr<<"out of range"<<endl;
            return NULL;
        }
        ptr[index*2+2]=node;
    }
    else
    {
        cerr<<"input error "<<endl;
        return NULL; 
    }

    return true;
}
template<typename T>
bool ArrayTree<T>::Delete_tree( int index, T& node )
{
    if( index<0 || index>max_size )
        return NULL;
    
    node = ptr[index];
    memset( &ptr[index], 0x00, sizeof( ptr[index] ) );
}
template<typename T>
T& ArrayTree<T>::Search( int index, T& node  )
{
    if( index<0 || index>max_size )
        return node;
    node = ptr[index];
    return node;
}
template<typename T>
void ArrayTree<T>::Display()
{
   for( int i=0;i<max_size;i++ )
       cout<<ptr[i]<<"  ";
   cout<<endl;
}
#endif












