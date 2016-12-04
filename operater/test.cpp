#include<iostream>
#pragma warning(disable:4996)
//using namespace std;
class Au {
public:
        int num;
        char str[300]; 
public:
        friend std::istream& operator >> (std::istream &is, const Au & a);
        friend std::ostream& operator << (std::ostream &os, const Au & a);
        
};
std::ostream& operator << (std::ostream &os,const  Au & a)
{
        os << a.num << "  " << a.str << std::endl;
        return os;
}
std::istream& operator >> (std::istream& is, Au & a)
{
        is >> a.num >> a.str;
        if (is.fail())
        {
               std::cout << "input fail!" << std::endl;
        }
        return is;
}
int main()
{
        Au a2, a3;
        std::cin >> a2;
        std::cin >> a3;
        std::cout << a2<<a3;
        return 0;
}

