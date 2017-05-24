#include "node.h"
template <typename T>
class Tree{
	public:
	Tree();
	~Tree();
	Node<T>* SearchNode( int nodeIndex );                           //寻找节点
	bool AddNode( int nodeIndex, int flag, Node<T>* pNode );        //增加节点
	bool DeleteNode( int index, Node<T>* pNode );                      //删除节点
	void ProriDisplay();                                            //前序遍历
	void MidDisplay();                                              //中序遍历

	private:
	Node<T>  m_root;	




};
template<typename T>

