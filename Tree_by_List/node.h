#ifndef NODE_H
#define NODE_H
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
template <typename T>
class Node{
public:
    Node();
    Node( T& demo, int _index );
    ~Node();
    Node* Search( Node*ptr, int _index );

private:
    T       data;      //数据域
    int     index;     //索引下标  
    Node    *left;     //左子树
    Node    *right;    //右子树
    Node    *parent;   //父节点
    
};
template<typename T>
Node<T>::Node()
{
    memset( this, 0x00, sizeof( Node<T> );
    left = right = parent = NULL;
}
template<typename T>
Node<T>::Node( T& demo, int _index )
{
    data = demo;
    index = _index; 
    right = NULL;
    left = NULL;
    parent = NULL;
}
template<typename T>
Node* Node<T>::Search( Node* ptr, int _index )
{
    if( ptr->index == _index )
        return ptr;
    if( ptr->left != NULL )
        return Search( ptr->left );
    if( ptr->right != NULL )
        return Search( ptr->right );
     
    //return NULL;  //感觉这里有问题，找不到的话指针返回什么呢？
}










#endif
