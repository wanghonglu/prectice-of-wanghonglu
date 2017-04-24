#include<string.h>
#include<stdio.h>
#include<error.h>
#include<stdlib.h>
char * input_string();
typedef struct Dstring
{
	char   c;
	struct Dstring*   ptr;
}Dstring;
int main(  )
{
	const char  *str = NULL;   /* 指向输入的字符串 */
	int   len = 0;             /* 重复的字符串的最大长度 */
	int   idx = 0;             /* 最长重复串的下标 */
	char  *re_str = NULL; /* 指向重复的字符串 */

	char  *p1, *p2;
	int   i=0,j=0;

	if( NULL==( str =  input_string() ) )
	{
		perror( "input_string" );
		return -1;
	}
	p1 = ( char* )malloc( strlen( str )+1 );
	memset( p1, 0x00, strlen( str )+1 );

	re_str = ( char * )malloc( strlen( str ) +1 );
	memset( re_str, 0x00, strlen( str ) +1 );

	for( i=0;i<strlen( str );i++ )
		for( j=1;j<=strlen( str )-i;j++ )
		{
			memset( p1, 0x00, strlen( str+1 ) );
			strncpy( p1, str+i, j ); 
			p2 = strstr( str, p1 );
			if( p2!=NULL && NULL !=strstr( p2+1, p1 ) )
			{
				if( len< strlen( p1 ) && 0!= strcmp( p1,str )  )
				{
					len = strlen( p1 );
					idx = i;
					memset( re_str, 0x00, strlen( str )+1 );
					strcpy( re_str, p1 );
				}
			}

		}

	free( p1 );
	printf( "最长的重复串是:%s  所在字符串中的下标是:%d, 长度为:%d\n", re_str,idx, len );
	free( re_str );
	

    return 0;
}
char * input_string()
{
	Dstring *head= NULL,*p1,*p2;
	static char* _str=NULL;
	char temp;
	int  count = 0;
	int  i = 0;
	printf( "please input the string end with '#' \n" );
	while( 1 )
	{
		scanf( "%c", &temp );
		if( temp == '#' )
			break;
		/* 此处加判断提出非字幕串，如空格、标点符号等 */
		if( temp<'A' || temp>'z' || ( temp>'Z' && temp<'a' ))
			continue;
		p1 = ( Dstring* )malloc( sizeof( Dstring ) );
		memset( p1, 0x00, sizeof( Dstring ) );
		p1->c = temp;
		if( head == NULL )
			head = p1;
		else
			p2->ptr = p1;
		p2 = p1;
		count++;
	}
	p2->ptr = NULL;

	_str = ( char* )malloc( count+1 );
	memset( _str, 0x00, count+1 );
	i = 0;
	while( head != NULL )
	{
		_str[i]=head->c;
		i++;
		head = head->ptr;
	}
	_str[ i+1 ]='\0';

	return _str;

}








