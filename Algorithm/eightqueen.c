#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
/* 判断n行，m列是否可以放置 */
int  queen[ 8 ]={-99991};
int  time = 0;
int  judge_for_queen( int n, int m )
{
	int i = 0;
	for ( i=0;i<8;i++ )
	{
		if( m == queen[ i ] )
			return 0;
	    if( abs( i-n ) == abs( m-queen[ i ] ) )
			return 0;
	}
	return 1;
}
void print_queen()
{
   int i = 0, j = 0;
   for( i=0;i<8;i++ )
   {
   for ( j=0;j<8;j++ )
   {
       if( j == queen[ i ] )
	       printf( "#  " );
	   else
	       printf( "-  " );
   }
   printf("\n" );
   }
   time++;
   printf("----------------------------------------%d\n", time );

   sleep( 6  );
}
void find_queen()
{
	int i = 0,j=0;
	for( i=0;i<8;i++ )
	{
		for( j=0;j<8;j++ )
		{
			if( judge_for_queen( i, j ) == 1 )
			{
				queen[i] = j;
				j=9;
			}
			if( i== 7 )
				print_queen();
#if 0
			if( queen[0] == 7 )
				break;
			else 
			{
				i =queen[ 0 ]+1;
			    j =0;
				continue;
			}
#endif
		}
	}



}
int main( int argc, char **argv )
{
	find_queen();
	return 0;
}
