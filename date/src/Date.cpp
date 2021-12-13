#include "Date.h"

using namespace std;

Date::Date(){
    y=1900;
    m=1;
    d=1;
}
Date::Date(const Date &r){
    y=r.y;
    m=r.m;
    d=r.d;
}
Date::~Date(){
    cout<<"object destructed"<<endl;
}

istream& operator >>(istream &input, Date &x)
{
	input>>x.y>>x.m>>x.d;
	return input;
}

ostream& operator <<(ostream &output, Date &x)
{
	output<<x.y<<" "<<x.m<<" "<<x.d;
	return output;
}