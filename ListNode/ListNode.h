/*************************************************************************
    > File Name: ListNode.h
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: Sat 03 Dec 2016 12:21:04 AM PST
 ************************************************************************/
#ifndef LISTNODE_H
#define LISTNODE_H
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
class ListNode
{
    public:
		ListNode *creat( int a[] ,int );
		ListNode *verse( ListNode *head );
		int display( ListNode *head );
		ListNode *add_listnode( ListNode *h1, ListNode *h2 );
		ListNode ( int x ): val( x ), next( NULL ){};
		~ListNode(){};
	private:
		int val;
		ListNode *next;
};
#endif
