#include<stdio.h>
int main( int argc, char ** argv )
{
    int a[2][3]={0},(*p)[3] = a,i, j;

	for ( i = 0;i<2;i++ )
		for ( j=0;j<3;j++ )
			scanf( "%d", *(p+i)+j);

	for ( i = 0;i<2;i++ )
	{
		for ( j=0;j<3;j++ )
		{
            printf( "%d ", a[i][j]);
		}
		printf( "\n");
	}
	printf( "\n" );
	return 0;

}
