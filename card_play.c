#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

typedef struct{
	int   card;
	char  character;
	int   num;
}ONE_CARD;
typedef struct
{
	int       suit;  /* 用整形的3,4,5,6分别代表 红心、方块、梅花、黑桃 */
	ONE_CARD  one_card; /* 点数、花色映射 */
	int       flag;  /* 0表示未发放， 1表示该牌以发出 */
}CARD;
ONE_CARD signal_card[] ={ {1,'A',11 },{2,'2',2 },{3,'3',3 },{4,'4',4 },{5,'5',5 },{6,'6',6 },{7,'7',7 },{8,'8',8 },{9,'9',9 },{10,'10',10 },{11,'J',10 },{12,'Q',10 },{13,'K',10 } };

//typedef int (*fun)(CARD*per, int num );
typedef struct{
	CARD  all[13];
	int   total;
}HAND;

/* 计算手里有的所有牌的点数  */
/* 超过21为1 不超过为0, 等于21为2 */
/* 对于A 当A为11时总和超过21则记为1 */

int calculate_all( HAND * _all ,int num )
{
	static int total, i=0;
	for( i=0;i<num;i++ )
	{
		total = total+_all->all[i].one_card.num;
		if( total>21 && _all->all[i].one_card.card == 1 )
			total=total-10;
	}
	_all->total = total;

	if( total<21 )
		return 0;
	return total==21?2:1;
}
CARD card[52];
int creat_card()
{
	int i=0,j=0, suit = 3;
	memset( card, 0x00, sizeof( card ) );
	for( i=0;i<4;i++ )
		for( j=0;j<13;j++ )
		{
            card[j+13*i].one_card = signal_card[i];
		    card[j+13*i].suit =suit+i ;
			card[j+13*i].flag = 0;
		}

	return 0;
}
int  display( HAND *per, int _num, int flag ) /* flag 0-AI  1-玩家 */
{
	char  a[20]={0};
	int   i = 0;
	if( flag == 0 )
	    strcpy( a, "AI" );
	else
		strcpy( a, "玩家" );
	printf( "\t%s手里的牌：", a );
    for( i=0;i<_num;i++ )
		printf( "%c%c  ", (char) per->all[i].suit, per->all[i].one_card.character ); 

	per->total = calculate_all( per, _num );
	printf( "\n%s的总点数:%d\n ",a, per->total );


    return 0;		
}
int main()
{
	HAND   AI, player;
	char   tmp;
	int    rand,count=0,j;
	memset( &AI, 0x00, sizeof( AI ) );
	memset( &player, 0x00, sizeof( player ) );

	srand( (int)time(0) );

	creat_card();
	while(1)
	{
		printf( "\t\t\t\t-------------------------------------\n" );
		printf( "\t\t\t\t-------是否要牌（y-是 n-否 ）--------\n" );
		printf( "\t\t\t\t-------------------------------------\n" );
		fscanf( stdin, "%c", &tmp );
		switch( tmp )
		{
			case 'y':
		    {
				rand = rand%52;
				printf( "%d", rand );
			    if( card[rand].flag == 0 )
				{
					AI.all[count]=card[rand];
					card[rand].flag =1;
				}
				else
			    {
				    j = rand;
					while( j<52  )
					{
						j++;
						if( card[j].flag == 0 )
						{
							AI.all[count] = card[j];
							card[j].flag = 1;
						}
				        if(j==51 )
						j=0;
					}
				}
                rand = rand%52;
                if( card[rand].flag == 0 )
                {   
                    player.all[count]=card[rand];
                    card[rand].flag =1;
                }
                else
                {   
                    j = rand;
                    while( j<52  )
                    {   
                        j++;
                        if( card[j].flag == 0 )
                        {   
                            player.all[count] = card[j];
                            card[j].flag = 1;
                        }
                        if(j==51 )
                        j=0;
                    }
                }
                count++;
			}break;
        case 'n':
        {

        }break;
        default:
            printf( "input error\n" ); 

		}break;
        display( &AI, count,0 );
        display( &player,count,1 );
        if( AI.total>= 21 || player.total>=21 )
            break;
	}

	if( AI.total>21 )
		printf( "玩家获胜\n");
	else if( AI.total == 21 )
		printf( "AI获胜\n");

	if( player.total>21 )
		printf( "AI获胜\n");
	else if( player.total == 21 )
		printf( "玩家获胜\n");

	return 0;

}


