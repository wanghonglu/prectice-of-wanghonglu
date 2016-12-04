/*************************************************************************
    > File Name: ListNode.cpp
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: Sat 03 Dec 2016 12:27:03 AM PST
 ************************************************************************/
#include "ListNode.h"
ListNode * ListNode :: creat( int a[], int num )
{
	ListNode *head= NULL , *p1=NULL, *p2=NULL;
	int  k = 0;
    while( k<num )
	{
	    p1 = ( ListNode* )new ListNode( 0 );
		p1->val = *a;
		if( head == NULL )
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		a++;
		k++;
	}
	p2->next = NULL;
	return head;
}
int ListNode :: display( ListNode *head )
{
	if( head == NULL )
		cout<<"this is a empty Listnode"<<endl;
	ListNode *p1 = head;
    while( p1 )
	{
		cout<<p1->val<<"->";
//		cout<<p1->next<<endl;
		p1 = p1->next;
	}
	cout<<endl;

    return 0;
}
ListNode * ListNode :: verse( ListNode *_head )  
{
    ListNode *head=NULL,*p1=NULL, *p2=NULL,*temp=NULL;
	temp = _head;
	while( temp->next ) temp = temp->next;
	p1 = _head;
	while( p1 != temp )
	{
		//head = p1;
		head = p1->next;
		temp->next = p1;
		p1->next = p2;
		p2 = p1;
		//p1 = head->next;
		p1 = head;
	}
//    p1->next = NULL;
	return temp; 
}
ListNode * ListNode :: add_listnode( ListNode *h1, ListNode *h2 )
{
	ListNode *head = NULL, *p1 = NULL, *p2;
	int  num = 0;
	if( h1 == NULL && h2 == NULL )
		return p1;
	else if( h1 == NULL )
	    return h2;
	else if( h2 == NULL )
        return h1;
	while( h1!=NULL && h2!= NULL )
	{
	    p1 = ( ListNode * )new ListNode( 0 );
        p1->val = h1->val+h2->val;
		if( num == 1 )
		{
			p1->val +=1;
			num = 0;
		}
		if( p1->val>=10 )
		{
			p1->val = p1->val-10;
			num = 1;
		}
		if( head == NULL )
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		h1 = h1->next;
		h2 = h2->next;
	}
	if( h1 == NULL && h2 != NULL )
		p2->next = h2;
	else if( h1 != NULL && h2 == NULL )
		p2->next = h1;
	else 
	    p2 ->next = NULL;
	return head;
}










