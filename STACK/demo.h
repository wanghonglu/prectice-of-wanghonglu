#ifndef DEMO_H
#define DEMO_H
#include "my_head.h"
//extern error;
class DEMO
{
    private:
        int x;
        int y;
    public:
        DEMO(int a=0, int b=0 ):x(a), y(b){};
        void display();
	friend ostream &operator <<( ostream& os, DEMO& t );
};
#endif
