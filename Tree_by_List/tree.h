#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
template<typename T >
class Node{
	public:
		Node()
		{
			index = 0;
			left = right = parent = NULL;

		}
		Node( T& demo, int _index )
		{
			data = demo;
			index = _index;
			right = NULL;
			left = NULL;
			parent = NULL;
		}
		virtual ~Node()
		{
		}
		Node* SearchNode(  int _index );
		void DeleteNode()
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
			this->~Node();
		}
		void ProriDisplay()
		{
			if( this != NULL )
				cout<<this->index<<"  "<<this->data<<endl;
			if( this->left != NULL )
				this->left->ProriDisplay();
			if( this->right != NULL )
				this->right->ProriDisplay();
		}
		void MidDisplay()
		{
			if( this->left !=  NULL )
				this->left->MidDisplay();
			cout<<this->index<<"  "<<this->data<<endl;
			if( this->right != NULL )
				this->right->MidDisplay();
		}
		void PostDisplay()
		{
			if( this->left != NULL )
				this->left->PostDisplay();
			if( this->right != NULL )
				this->right->PostDisplay();
			cout<<this->index<<"   "<<this->data<<endl;
		}
	public:
		T       data;      //数据域
		int     index;     //索引下标  
		Node    *left;     //左子树
		Node    *right;    //右子树
		Node    *parent;   //父节点
};
template<typename T>
Node<T>* Node<T>::SearchNode(  int _index )
{
	if( this->index == _index )
		return this;
	if( this->left != NULL )
		return this->left->SearchNode( _index );
	if( this->right != NULL )
		return this->left->SearchNode( _index );
	return NULL;  //感觉这里有问题，找不到的话指针返回什么呢？
}

template <typename T >
class Tree{
	public:
	Tree();
	~Tree();
	Node<T>* SearchNode( int nodeIndex );                           //寻找节点
	bool AddNode( int nodeIndex, int flag, Node<T>* pNode );        //增加节点
	bool DeleteNode( int index, Node<T>* pNode );                   //删除节点
	void ProriDisplay();                                            //前序遍历
	void MidDisplay();                                              //中序遍历
	void PostDisplay();                                             //后序遍历

	void PrintRoot()
	{
		cout<<m_root->index<<"====="<<m_root->data<<endl;
	}

	private:
	Node<T>*  m_root;	

};
template<class T >
Tree<T>::Tree()
{
	m_root = new Node<T>;
}
template<class T >
Tree<T>::~Tree()
{
	delete m_root;
//	m_root->DeleteNode();
}
template<typename T >
Node<T>* Tree<T>::SearchNode( int nodeIndex )
{
	return m_root->SearchNode( nodeIndex );
}
template<typename T >
bool Tree<T>::AddNode( int nodeIndex, int flag,Node<T>* pNode ) 
{
	Node<T>* ptr = SearchNode( nodeIndex );
	if( ptr == NULL )
		return false;

	cout<<"search end"<<endl;
	Node<T>* current = new Node<T>;
	if( current == NULL )
		return false;

//	memcpy( current, pNode, sizeof( Node<T> ) );
	current->data = pNode->data;
	cout<<pNode->data<<endl;
	current->index = pNode->index;
	current->parent = ptr;
    if( flag == 0 )
	{
		ptr->left = current;
	}
	else if( flag == 1 )
	{
		ptr->right = current;
	}

	return true;
}
template<typename T >
bool Tree<T>::DeleteNode( int indexNode, Node<T>* pNode )
{
	Node<T>* ptr = SearchNode( indexNode );
	if( ptr == NULL )
		return false;

//	memcpy( pNode, ptr );
	pNode->data = ptr->data;
	pNode->index = ptr->index;
//	ptr->DeleteNode();
	return true;
}
template<typename T >
void Tree<T>::ProriDisplay()
{
	m_root->ProriDisplay();
}
template<typename T >
void Tree<T>::MidDisplay()
{
	m_root->MidDisplay();
}
template<typename T >
void Tree<T>::PostDisplay()
{
	m_root->PostDisplay();
}

