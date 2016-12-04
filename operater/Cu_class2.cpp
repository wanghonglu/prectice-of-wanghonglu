#include "Cu_class.h"
std::istream& operator >> ( std::istream &is, Cu& a )
{
    is>>a.b>>a.name;
    if( is.fail() )
    {
       std:: cout<<"input fail"<<std::endl;
    }
    return is;
}
std::ostream& operator << ( std::ostream &os, Cu& a )
{
    os<<a.b<<a.name;
    return os;
}
