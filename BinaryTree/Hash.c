#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#define Max_len 255
typedef struct{
	int   date;
	int   IsNull;   /*0--没有， 1--有 */
}Hash_tab;
Hash_tab  my_table[Max_len];
int function_for_hash( int key )
{
	return key%29;
}
int inite_hashble()
{
	memset( my_table, 0x00, sizeof( my_table ) );
	return 0;
}
int insert_into_table( int key )
{
	int addr = function_for_hash( key );
	if( my_table[addr].IsNull == 0 )
    {
        my_table[addr].date = key;
		my_table[addr].IsNull = 1;
		return 0;
	}
	while( my_table[addr].IsNull ==1 && addr<Max_len )
		addr++;
    if( addr == Max_len )
	{
		fprintf( stdout, "the hash table is full \n" );
		return -1;
	}

	my_table[addr].date = key;
	my_table[addr].IsNull = 1;

	return 0;
	
}
int find_key( int key )
{
	int addr = function_for_hash( key );
	while( !( my_table[addr].date == key && my_table[addr].IsNull == 1 ) && addr<Max_len  ) 
		addr++;
	if( addr == Max_len )
    {
		fprintf( stdout, "the key:%d is not found\n", key  );
		return -1;
	}

	return addr;
}
int main( int argc, char** argv )
{
    int  num[]={129,234,111,200,4,39,5,28,198,12,23};
	inite_hashble();
	int  i = 0;
	for( i=0;i<sizeof( num )/sizeof( int );i++ )
	{
		insert_into_table( num[i] );
	}
    int  date=atoi( argv[1] );
	fprintf( stdout, "ok\n" );
	fprintf( stdout, "the %s in hash_table is %d\n", argv[1], find_key( date ) );

	return 0;
	
}
