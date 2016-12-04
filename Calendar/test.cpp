#include<iostream>
#include<iomanip>
using namespace std;
class Calendar
{
public:
	Calendar(int _year, int _month ) :year(_year), month(_month)
	{}
	~Calendar()
	{}
	int total_days()
	{
		int day = 0;
		for (int i = 1900; i < year; i++)
		{
			if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
				day = day + 366;
			else
				day = day + 365;	 //day计算该年距离1900年的天数 
		}
		for (int i = 1; i < this->month; i++)
		{
			day = yue(i) + day;
		}
		return day-1 ;

	}
	int yue( int month)
	{
		bool isleapyear;
		isleapyear = ((this->year % 4 == 0 && this->year % 100 != 0) || (this->year % 400 == 0));
		switch (month % 12)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
			break;
		case 2:
			if (isleapyear)
				return 29;
			else
				return 28;
			break;
		default:
			return 30;
			break;
		}
	}
	

	void display(  )
	{
		    int num = total_days()+1;
			switch ( num % 7 )
			{

			case 0:
				cout<<right<<setw(16)<<1;break;
			case 1:
				cout<<right<<setw(24)<<1;break;
			case 2:
				cout<<right<<setw(32)<<1;break;
			case 3:
				cout<<right<<setw(40)<<1;break;
			case 4:
				cout<<right<<setw(48)<<1;break;
			case 5:
				cout<<right<<setw(56)<<1<<endl;break;
			case 6:
				cout<<right<<setw(8)<<1;break;
			}
			for (int i = 2; i <= this->yue( this->month ); i++)
			{
		        cout<<right<<setw(8)<<i;	
				if (( num+i-1 ) % 7 == 5 )
                    cout<<endl;
			}
            cout<<endl;
		}
private :
	int   year;
    int   month;
};
int main()
{
	while (1)
	{
		int  year = 0, month = 0;
		cout << "please input year and month(YYYYmm)" << endl;
		cin >> year >> month;
		Calendar test(year, month);
        cout<<right<<setw(9)<<"日"<<right<<setw(9)<<"一"<<right<<setw(9)<<"二"<<right<<setw(9)<<"三"<<right<<setw(9)<<"四"<<right<<setw(9)<<"五"<<right<<setw(9)<<"六"<<endl;
		test.display( );
	}



	return 0;
}
