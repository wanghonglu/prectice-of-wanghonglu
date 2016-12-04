/*************************************************************************
    > File Name: Man_sys.cpp
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: Sun 20 Nov 2016 03:45:17 AM PST
 ************************************************************************/

#include "man_sys.h"

man_sys * man_sys::creat_node( man_sys *_head )
{
    man_sys *p1 = NULL ;
    man_sys *p2 = NULL ;
    man_sys *Head = NULL ;
	int  _num = 0;
    p1 = new man_sys;
	memset( p1, 0x00, sizeof( p1 ) );
	cout<<"please input name and score(end with score = -1 )"<<endl;
	cin>>p1->name>>p1->score;
	p1->ptr = NULL;
	p1->num = 1;
	_num = 1;
	while( p1->score != -1 )
	{
		if( Head ==  NULL )
		{
			Head = p1 ;
		}
		else
		{
			p2->ptr = p1;
		}
		p2 = p1;
		p1 = new man_sys;
		memset( p1, 0x00, sizeof( p1 ) );
		cout<<"please input name and score(end with score = -1 )"<<endl;
		cin>>p1->name>>p1->score;
		_num++;
		p1->num = _num;
	}
	cout<<"creat completely1"<<endl;
	p2 ->ptr = NULL;
	delete p1;
	p1 = NULL;
	_head = Head;

	return _head;
}
int  man_sys ::  display_node( man_sys *head )
{
	man_sys *p1 = NULL;
	if( head == NULL )
	{
		cout<<"this is an empty node"<<endl;
		return 0;
	}
	p1 = head;
	do 
	{
		cout<<p1->num<<"    "<<"Name :"<<p1->name<<"         "<<"Score :"<<p1->score<<endl;
		p1 = p1->ptr;
	}
	while( p1 != NULL );

	return 0;
}
man_sys * man_sys :: delete_node( man_sys * _head )
{
	int _num = 0;
	man_sys *p1,*p2;
	cout<<"please input the serial you want delete!"<<endl;
	cin>>_num;
	p1 = _head;
	if( _head->num == _num )
	{
		_head =_head->ptr;
		p1 = _head;
		while( p1 != NULL )
		{
			p1->num = p1->num-1;
			p1 = p1->ptr;
		}
		return _head;
	}
	while( p1->ptr != NULL )
	{ 
		p2 = p1->ptr;
		if( p2->num == _num )
		{
			p1->ptr = p2->ptr;
		    p1 = p1->ptr;
            while( p1 != NULL )
			{
				p1->num = p1->num-1;
				p1 = p1->ptr;
			}
			return _head;
		}
		p1 = p1->ptr;
	}

    cout<<"not fount the serial you want delete in node"<<endl;
	return _head;
}
man_sys * man_sys :: increase_node( man_sys * _head )
{
	int  _num = 0;
	man_sys *p1 = NULL;
	man_sys *p2 = NULL;
	p2 = new man_sys;
	memset( p2, 0x00, sizeof( man_sys ) );
	p1 = _head;
	cout<<"please input serial you want incream( after your number )"<<endl;
	cin>>_num;
	if( _num == 0 )
	{
		cout<<"please input name and score for new node"<<endl;
		cin>>p2->name>>p2->score;
		p2->num = 1;
		p2->ptr = p1;
		while( p1 != NULL )
		{
			p1->num = p1->num +1;
			p1 = p1->ptr;
		}
		_head = p2;
		return _head;
	}
	while( p1 != NULL )
	{
		if( p1->num == _num )
		{
		    cout<<"please input name and score for new node"<<endl;
		    cin>>p2->name>>p2->score;
			p2->num = _num+1;
			p2->ptr = p1->ptr;
			p1->ptr = p2;
			p1 = p2->ptr;
			while( p1 != NULL )
			{
				p1->num = p1->num +1;
				p1 = p1->ptr;
		    }
			return _head;
		}
		p1 = p1->ptr;
	}
	cout<<"can not found serial you want incream"<<endl;
	return _head;
}
man_sys * man_sys :: reverse( man_sys * node )
{

	man_sys *p1,*p2 = NULL,*head,*temp;
	temp = node;
	while( temp->ptr != NULL ) temp = temp->ptr; //find last node for reverse
	p1 = node;
	while( p1 != temp )
	{
		head = p1->ptr;
		temp ->ptr = p1;
#if 0
		if( p2 == NULL )
			p1->ptr = NULL;
		else
			p1->ptr = p2;
#endif
		p1->ptr = p2;
		p2 = p1;
		p1 = head;
	}

	return head;

}
int display()
{ 
	cout<<setw( 15 )<<" 1 : create system of stdudent management"<<endl;
	cout<<setw( 15 )<<" 2 : delete one of them"<<endl;
	cout<<setw( 15 )<<" 3 : display all of them"<<endl;
	cout<<setw( 15)<<" 4 : increase one record"<<endl;
	cout<<setw( 15)<<" 5 : reverse node"<<endl;
	cout<<right<<"pleaset input one number to deal!"<<endl;

	return 0;

}
