#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> test;
	cout<<"capacity"<<test.capacity()<<endl;
	int         num = 0;
	while( cin>>num )
		test.push_back( num );

	cout<<"capacity"<<test.capacity()<<endl;

    vector<int>::iterator  it;
	for( it = test.begin();it != test.end();it++ )
		cout<<*it<<" ";
	cout<<endl;
	/*出现偶数则重复输入，出现奇数则删除当前奇数*/
	it = test.begin();
	while( it != test.end() )
	{
		if( *it%2 )
			it = test.erase( it );
		else
		{
			it = test.insert( it, *it );
			it+=2;
		}
	}
	test.reserve( 100 );
	cout<<"capacity"<<test.capacity()<<endl;

	for( it = test.begin();it != test.end();it++ )
		cout<<*it<<" ";
	cout<<endl;
	cout<<test.size()<<endl;
	cout<<"v2 "<<endl;
	vector<int> v2( test.begin(), test.end()  );
	cout<<v2.size()<<endl;
	for ( it = v2.begin();it!= v2.end();it++ )
		cout<<*it<<"";
	cout<<endl;

	int   a[]={1,2,3,4,5,6,7,8,9,0};
	vector<int> v1( a, a+9 );
	auto it1 = v1.begin();
	while( it1 != v1.end() )
	{
		cout<<*it1<<"  ";
		it1++;
	}
	cout<<endl;
	return 0;
}

