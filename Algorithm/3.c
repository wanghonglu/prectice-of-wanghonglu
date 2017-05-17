#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct LNode
{
DataType data;
struct LNode *next;


}LNode,*LinkList;
 LNode *creatList(void)
{
LNode *head,*s;
LNode *p;
int c;
head=(LNode*)malloc(sizeof(LNode));
p=head;
p->next=NULL;
scanf("%d",&c);
while(c>0)
{
s=(LNode*)malloc(sizeof(LNode));
s->data=c;
s->next=p->next;
p->next=s;
scanf("%d",&c);

}

return head;

}
void main()
{
LNode *head = NULL;
head = creatList();
head = head->next;
while( head != NULL )
{
    printf( "%d\t", head->data );
    head = head->next;
    }


}

