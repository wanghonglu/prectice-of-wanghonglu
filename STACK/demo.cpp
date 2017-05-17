#include "demo.h"
///#include "my_head.h"
//extern error;
void DEMO::display()
{
	cout<<"("<<x<<","<<y<<")"<<endl;
}
ostream &operator <<( ostream& os, DEMO& t )
{
	os<<"("<<t.x<<","<<t.y<<")";
	return os;
}
