#include "my_head.h"
template<typename T>
Queue<T>::Queue( int max_size )
{
    m_ptr = new T[max_size];
    m_length = 0;
    m_capacity = max_size;
    m_head = 0;
    m_tail = 0;
}
template<typename T>
Queue<T>::~Queue()
{
    delete []m_ptr;
    m_ptr = NULL;
}
template<typename T>
void Queue<T>::ClearQueue()
{
    m_length = 0;
    m_head =0;
    m_tail = 0;
}
template<typename T>
bool Queue<T>::QueueEmpty()const
{
    return m_length==0?true:false;
}
template<typename T>
bool Queue<T>::QueueFull()const
{
    return m_length == m_capacity?true:false;
}
template<typename T>
int Queue<T>::QueueLength()const
{
    return m_length;
}
template<typename T>
bool Queue<T>::EnQueue( T &element )
{
    if( QueueFull() )
        return false;
    m_ptr[m_tail] = element;
    m_tail++;
    m_tail%=m_capacity;         //环形队列，当对头往后移动时，队尾可以重新占用对头的位置，所以需要对队尾做取余操作
    m_length++;                 //比如对于容量为4的环形队列，当插入第4个元素的时候队列满了，此时在出去一个，就又能插入了
    return true;                //队尾为4,显然不对，所以要对队尾进行取余，也就是对尾为0
}
template<typename T>
bool Queue<T>::DeQueue( T &element )
{
    if( QueueEmpty() )
        return false;
    element = m_ptr[m_head];    //环形队列，最开始head和tail都为0，当每插入一个元素后，头不动，尾+1；
    m_head++;                   //当队列出去一个元素时，尾不动，头减一；
    m_head%=m_capacity;
    m_length--;
    return true;
}
template<typename T>
void Queue<T>::DisplayQueue()
{
    int i;
    for( i=m_head;i<m_length+m_head;i++ ) //当head往后移动的时候，比如此时是1，而长度为4 这样只能打印出3个元素打印不出第四个元素
       cout<<m_ptr[i%m_capacity]<<" ";  //环形队列，同一个位置可以不停的复用，所以如果m_head为3时，只会打印出一个元素，这样肯定是不对的，需要对i取余；       
    cout<<endl;
}
