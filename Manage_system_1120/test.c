#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define LEN sizeof(struct student)
#define FILE_DATA_PATH "student.txt"
struct student
{
	long int num;
	char name[20];
	int age;
	char sex[4];
	char birthday[10];
	char address[30];
	long int tele_num;
	struct student*next;
};
int TOTAL_NUM=0;
struct student*head=NULL;
void welcome();
void mainmenu();
void record();
void insertLink(struct student*stu);

void insertLinkl();

void instrtLinkl();
void display(struct student *stu);
void displayAll();
void query();
void Locate_num();
void Locate_name();
void readData();
void writeData();
void DelLink();
void change();
void devise(struct student*p);
int main()
{
	char userName[9];
	char userPWD[7];
	int i;
	welcome();
	for(i=0;i<3;i++)
	{
		printf("\n 管理员初始用户名或密码均为 123\n");
		printf("请输入您的用户名:");
		scanf(" %s",userName);
        printf("\n请输入您的密码:");
        scanf(" %s",userPWD);
		if((strcmp(userName,"123")==0)&&(strcmp(userPWD,"123")==0))
		{
			mainmenu();
			break;
		}
		else
		{
			if(i<2)
			{
				printf("用户名或密码错误，请重新输入!");
			}
			else
			{
				printf("您已连续3次将用户名或密码输错，系统将退出!");
			}
		}
	}
	return 0;
}
void welcome()
{
	printf("\t\t\t+-------------+\n");
    printf("\t\t\t||\n");
    printf("\t\t\t| 欢迎使用学生信息管理系统　|\n");
    printf("\t\t\t||\n");
    printf("\t\t\t+-------------+\n");
    printf("\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t+--------本程序为线性表");
}
void mainmenu()
{
	int choice;
	choice=-1;
	readData();
	printf("\n温馨提示：为保证您的操作得到保存，请按正常系统退出*_*\n");
	do
	{
		printf("\n\n\n");
        printf("\t\t\t-----------------\n");
        printf("\t\t\t|　学生信息管理系统　|");
        printf("\t\t\t-----------------\n");
        printf("\t\t\t|[1]----录入学生信息|\n");
        printf("\t\t\t|[2]----浏览学生信息|\n");
        printf("\t\t\t|[3]----查询学生信息|\n");
        printf("\t\t\t|[4]----删除学生信息|\n");
        printf("\t\t\t|[5]----修改学生信息|\n");
        printf("\t\t\t|[6]----插入学生信息|\n");
        printf("\t\t\t|[0]----退出系统|\n");
        printf("\t\t\t|*'*'*'*'*'*'*'*'*'*'*'*'*|\n");
        printf("\t\t\t+--------------\n");
        printf("请输入您的选择:");
		scanf(" %d",&choice);
		switch(choice)
		{
		case 0:
				writeData();
				exit(0);
		case 1:
				record();
				break;
		case 2:
				displayAll();
				break;
        case 3:
 		    	query();
				break;
	    case 4:
				DelLink();
				break;
		case 5:
 		    	change();
				break;
		case 6:
		    	insertLinkl();
				break;
		default:
			printf("\n无效选择!");
			break;
		}
	}
	while(choice!=0);
}
void record()
{
	struct student *p0;
	p0=(struct student * )malloc(LEN);
	printf("请输入学生的学号:");
	scanf("%ld",&p0->num);
	printf("请输入学生的姓名:");
	scanf("%s",p0->name);
	printf("请输入学生的年龄:");
	scanf("%d",&p0->age);
    printf("请输入学生的性别:");
	scanf("%s",p0->sex);
    printf("请输入学生的出生年月:");
	scanf("%s",p0->birthday);
    printf("请输入学生的地址:");
	scanf("%s",p0->address);
    printf("请输入学生的电话:");
    scanf("%ld",&p0->tele_num);
	insertLink(p0);
    printf("该学生信息为:\n");
    printf("---------------------------------");
    printf("学号\t姓名\t年龄\t性别\t出生年月\t\t地址\t电话\n");
	display(p0);
}
void insertLink(struct student*stu)
{
	struct student *p0,*p1,*p2;
	p1=head;
	p0=stu;
	if(head==NULL)
	{
		head=p0;
		p0->next=NULL;
	}
	else
	{
		while((p0->num>p1->num)&&(p1->next!=NULL))
		{
			P2=P1;
			P1=P1->next;
		}
		if(p0->num<=p1->num)
		{
			if(head==p1)
				head=p0;
			else
				p2->next=p0;
			p0->next=p1;
		}
		else
			p1->next=p0;
		p0->next=NULL;
	}
}
TOTAL_NUM++;
}
void insertLinkl()
{
	record();
}
void display(struct student*p)
{
	printf("%ld\t%s\t%d\t%s\t%s\t%s\t%ld\n",p->num,p->name,p->age,p->sex,p->birthday,p->address,p->tele_num);
}
void displayAll()
{
	struct student*p;
	printf("学生总数:%d\n",TOTAL_NUM);
	p=head;
	if(head!=NULL)
	{
		printf("\n学号\t姓名\t年龄\t性别\t出生年月\t地址\t电话\n");
		printf("----------------------------------------");
		do
		{
			display(p);
			p=p->next;
		}
		while(p!=NULL);
	}
	printf("\n");
}
void query()
{
	int choice;
	choice=-1;
	do
	{
		printf("\n");
		printf("+------------+\n");
		printf("|[1]---按学号查询|\n");
     	printf("|[2]---按姓名查询|\n");
	    printf("|[0]---取消|\n");
        printf("+------------+\n");
        printf("请输入您的选择:");
		scanf(" %d",&choice);
		switch(choice)
		{
		case 0:
			return;
		case 1:
			Locate_num();
			break;
        case 2:
			Locate_name();
			break;
        default:
			printf("\n无效选项!");
			break;
		}
	}
	while(choice!=0);
}
void Locate_num()
{
	int num;
	struct student*p1;
	printf("请输入学生的学号:");
	scanf(" %ld",&num);
	if(head==NULL)
	{
		printf("无学生记录!　\n");
		return;
	}
	p1=head;
	while(num!=p1->num&&p1->next!-NULL)
		P1=P1->next;
	if(num==p1->num)
	{
		printf("\n学号\t姓名\t年龄\t性别\t出生年月\t地址\t电话\n");
		printf("-----------------------------------");
		display(p1);
	}
	else
		printf("没有该学生记录，请核对!");
}



void Locate_name()
{
char name[20];
struct student *p1;
printf("请输入学生的姓名:\n");
scanf("%s",name);

if(head==NULLL)
{
printf("无学生记录!\n");
return ;
}
p1=head;
while(strcmp(name,p1->name)&&p1->next=NULL)
P1=P1->next;
if(!strcmp(name,p1->name))
{
printf("\n学号 \t姓名\t年龄\t性别\t出生年月\t地址\t电话\n");
display(p1);

}
else
printf("没有该学生记录，请核对!\n");

}
void writeData()
{
FILE *fp;

struct student *p;
fp=fopen(FILE_DATH,"w");
if(!fp)
{
printf("文件打开有错误!");
return ;



}
fprintf(fp,"%d\n",TOTAL_NUM);
for(p=head;p!=NULL;p=p->next)
{
	fprintf(fp,"%ld\t%s\t%d\t%s\t%s\t%s\t%ld\n",p->num,p->name,p->age,p->sex,p->birthday,p->address,p->tele_num);





}

fclose(fp);

}
void readData()
{
FILE *fp;
struct student *p1,*p2;
fp=fopen(FILE_DATA_PATH,"r")

if(!fp)
{
printf("文件打开错误!\n")
return;
}
fscanf(fp,"%d\n",&TOTAL_NUM);
head=p1=p2=(struct student*)malloc(LEN);
fscanf(fp,"%ld\t%s\t%d\t%s\t%s\t%s\tld\n",&p1->num,p1->name,&p1->age,p1->sex,p1->birthdag,p1->address,&p1->tele_num);
while(!feof(fp))
{
p1=(struct student*)malloc(LEM);

fscanf(fp,"%ld\t%s\t%d\t%s\t%s\t%s\tld\n",&p1->num,p1->name,&p1->age,p1->sex,p1->birthdag,p1->address,&p1->tele_num);
P2->next=p1;
p2=p1;


}
p2->next=NULL;
fclose(fp);



}
void DelLink()
{
struct student *p1,*p2;
long int num;
if(head==NULL)

{
printf("无学生记录!\n");
return;
}
printf("请输入你要删除的学生的学号:\n");
scanf("%ld",&num);
p1=head;
while(num!=p1->num&&p1->next!=NULL)
{
P2=P1;
P1=P1->next;


}
if(num==p1->num)
{
if(p1==head)
head=p1->next;
else
p2->next=p1->next;
free(p1);
TOTAL_NUM--

}
else
printf("没有该学生的记录，请核对!\n");

}
void chang()
{
struct student *p1,*p2;
long int num;
if(head==NULL)
{
printf("无学生记录!\n");
return;
}
printf("请输入你要修改的学生的学号:\n");

scanf("%ld",&num);
p1=head;
while(num!=p1->num&&p1->next!=NULL)
{
P2=P1;
P1=P1->next;


}
if(num==p1->num)

devise(p1);
else
printf("没有该学生的记录，请核对!\n");


}
void devise(struct student *p)
{
int choice;
choice=-1;
do
{
printf("请选择你需要修改的学生的信息内容:\n");

printf("+-----------------------+\n");
printf("|姓名  请按1|\n");

printf("|年龄  请按2|\n");

printf("|性别 请按3|\n");
printf("|出生年月  请按4|\n");

printf("|地址  请按5|\n");

printf("|电话  请按6|\n");

printf("|取消  请按0|\n");

printf("+-----------------------+\n");
printf("请输入你的选择:\n");
scanf("%d",&choice);

switch(choice)
{
case 0:
	return;

case 1:
	printf("请输入新姓名:");
	scanf("%s",p->name);
	break;
case 2:printf("请输入新年龄:");
	scanf("%s",p->name);
	break;

case 3:
printf("请输入新性别:");
	scanf("%s",p->name);
	break;
case 4:
	printf("请输入新出生年月:");
	scanf("%s",p->name);
	break;

case 5:
printf("请输入新地址:");
	scanf("%s",p->name);
	break;
case 6:
printf("请输入新电话:");
	scanf("%s",p->name);
	break;
	default;
		printf("\n无效选择");
		break;



}


}
while(choice!=0);



}

