#pragma once

#include<iostream>
using namespace std;

class Date{
	private:
		int y,m,d;
	public:
		Date();
		Date(const Date&);
		~Date();
		friend istream& operator >>(istream&, Date &x);
		friend ostream& operator <<(ostream&, Date &x);
		friend int getStartDays(Date aa);
		friend int Deviation(Date aa, Date bb);
};

