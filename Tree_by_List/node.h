#ifndef NODE_H
#define NODE_H
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
template <typename T>
class Node{
public:
    Node();
    Node( T& demo, int _index );
    ~Node();
    Node* Search( Node*ptr, int _index );
	void DeleteNode();
	void ProriDisplay();
	void MidDisplay();
	void PostDisplay();

    public:
    T       data;      //数据域
    int     index;     //索引下标  
    Node    *left;     //左子树
    Node    *right;    //右子树
    Node    *parent;   //父节点
    
};
template<typename T>
Node<T>::Node()
{
    //memset( this, 0x00, sizeof( Node<T>) );
	index = 0;
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
Node<T>* Node<T>::Search( Node<T>* ptr, int _index )
{
    if( ptr->index == _index )
        return ptr;
    if( ptr->left != NULL )
        return Search( ptr->left );
    if( ptr->right != NULL )
        return Search( ptr->right );
     
    //return NULL;  //感觉这里有问题，找不到的话指针返回什么呢？
}
template<typename T>
void Node<T>::DeleteNode()
{
	if( this->left != NULL )
		return this->left->DeleteNode();

	if( this->right != NULL )
		return this->right->DeleteNode();

	if( this->parent != NULL )
	{
		if( this->parent->left == this )
			this->parent->left = NULL;
		if( this->parent->right == this )
			this->parent->right = NULL;
	}
	delete this;
}
template<typename T>
void Node<T>::ProriDisplay()
{
	if( this != NULL )
	cout<<this->index<<"  "<<this->Data<<endl;

	if( this->left != NULL )
	    this->left->ProriDisplay();
    if( this->right != NULL )
	    this->right->ProriDisplay();

}
template<typename T>
void Node<T>::MidDisplay()
{
	if( this->left !=  NULL )
		this->left->MidDisplay();
	
	cout<<this->index<<"  "<<this->Data<<endl;

	if( this->right != NULL )
		this->right->MidDisplay();
}
template<typename T>
void Node<T>::PostDisplay()
{
	if( this->left != NULL )
		this->left->PostDisplay();

	if( this->right != NULL )
		this->right->PostDisplay();

	cout<<this->index<<"   "<<this->Data<<endl;
}










#endif
