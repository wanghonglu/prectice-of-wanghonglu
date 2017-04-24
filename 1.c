#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
typedef struct 
{
	char day[ 20 ];
	char holiday[ 50 ];
}FESTIVAL;
FESTIVAL holyday_map[]=
{
	{ "11",    "元旦节" },
	{ "214",   "情人节" },
	{ "311",   "植树节" },
	{ "51",    "劳动节" },
	{ "61",    "儿童节" },
	{ "81",    "建军节" },
	{ "910",   "教师节" },
	{ "101",   "国庆节" },
	{ "1225",  "圣诞节" },
	{ "38",    "女生节" },
	{ "NULL",  "NULL" }
};
int check_days_for_festival( int, int );

char*
month_str[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
char*
week[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int leap (int year)//判断闰年
{
if(year%4==0&&year%100!=0||year%400==0)
return 1;
else return 0;
}
int month_day(int year,int month) //判断这一个月有多少天
{
int mon_day[]={31,28,31,30,31,30,31,31,30,31,30,31}; //初始化每个月的天数
 if(leap(year)&&month==2 )
return 29;
else
return(mon_day[month-1]);
}
int firstday(int year,int month,int day)//判断这一个月的第一天是星期几 
{
int c=0;
float s;
int m;
for(m=1;m<month;m++)
c=c+month_day(year,m);
c=c+day;
s=year-1+(float)(year-1)/4+(float)(year-1)/100+(float)(year-1)/400-40+c; return ((int)s%7);
}
int PrintAllYear(int year)/*print the all year*/
{
int a,b;
int i,j=1,n=1,k;
printf("\n\n**************%d年的挂历**************\n",year);
for(k=1;k<=12;k++)
{ 
j=1,n=1;
b=month_day(year,k);
a=firstday(year,k,1);
printf("\n\n%s(%d)\n",month_str[k-1],k);
printf("                Sun Mon Tue Wed Thu Fri Sat \n**************");
if(a==7)
{
for(i=1;i<=b;i++)
{
printf("%4d",i);
if(i%7==0)
{
printf("**************\n**************");
}
}
}
if(a!=7)
{
while (j<=4*a)
{
printf(" ");
j++;
}
for(i=1;i<=b;i++)
{
printf("%4d",i);
if(i==7*n-a)
{
printf("**************\n**************");
n++;
}
}
}
printf("**************\n");
check_days_for_festival( k, b );
}
return 1;
}
//****************************************************
int main()
{
int option,da;
char ch;
int year,month,day;

printf("Copyright @ 2005 TianQian All rights reserved!:):):)");
 printf("\n\nWelcome to use the WanNianLi system!\n");
//调用系统时间
time_t tval;
struct tm *now;
tval = time(NULL);
now = localtime(&tval);
printf("现在时间: %4d年 %d月 %02d日 %d:%02d:%02d\n",
now->tm_year+1900, now->tm_mon+1, now->tm_mday,now->tm_hour, now->tm_min, now->tm_sec);
//调用结束
int i,j=1,k=1;
int a,b;
b=month_day(now->tm_year+1900,now->tm_mon+1);
a=firstday (now->tm_year+1900,now->tm_mon+1,now->tm_mday); printf("\n%d\n%d\n",b,a);
printf(" Sun Mon Tue Wed Thu Fri Sat \n");
if(a==7)
{
for(i=1;i<=b;i++)
{
printf("%4d",i);
if(i%7==0)
{
printf("\n");
}
}
}
if(a!=7)
{
while (j<=4*a)
{
printf(" ");
j++;
}
for(i=1;i<=b;i++)
{
printf("%4d",i);
if(i==7*k-a)
{
printf("\n");
k++;
}
}
}
printf("\n");
//****************************************************************** while(1)
{
printf("\n请选择你所需要的服务:\n");
printf("\n输入1求某个日期对应的星期");
printf("\n输入2判断某年是否为闰年");
printf("\n输入3输出某年的日历");
printf("\n输入4结束程序\n");
scanf("%d",&option);
switch(option)
{
case 1:
while(1)
{
printf("\nPlease input the year,month and day(XXXX,XX,XX):"); scanf("%d,%d,%d",&year,&month,&day);
da=firstday(year,month,day);
printf("\n%d-%d-%d is %s,do you want to continue?(Y/N)",year,month,day,week[da]);
fflush(stdin);
scanf("%c",&ch);
if(ch=='N'||ch=='n')
break;
}
break;
case 2:
while(1)
{
printf("\nPlease input the year which needs searched?(XXXX)"); scanf("%d",&year);
if(leap(year))
printf("\n%d is Leap year,do you want to continue?(Y/N)",year); else
printf("\n%d is not Leap year,do you want to continue(Y/N)?",year); fflush(stdin);
scanf("%c",&ch);
if(ch=='N'||ch=='n')
break;
}

break;
case 3:
while(1)
{
printf("\nPlease input the year which needs printed(XXXX)"); scanf("%d",&year);
PrintAllYear(year);
printf("\nDo you want to continue to print(Y/N)?"); fflush(stdin);
scanf("%c",&ch);
if(ch=='N'||ch=='n')
break;
}
break;
case 4:
fflush(stdin);
printf("Are you sure?(Y/N)");
scanf("%c",&ch);
if(ch=='Y'||ch=='y')
exit(0);
break;
default:
printf("\nError:Sorry,there is no this service now!\n"); break;
}
}
return 0;
}
int check_days_for_festival( int _month, int _days )
{
	char  args[30];
	int   i = 0;
    int   idx = 0;
	for( i=1;i<=_days;i++ )
	{
	    memset( args, 0x00, sizeof( args ) );
        sprintf( args, "%d%d", _month, i );
		idx = 0;
		while( strcmp( holyday_map[idx].day, "NULL" ) !=0 )
		{
			if( strcmp( holyday_map[idx].day, args ) == 0 )
				printf( "\t\t%d月%d日是%s\n", _month, i, holyday_map[idx].holiday );
            idx++;
		}
	}

	return 0;
	
}

