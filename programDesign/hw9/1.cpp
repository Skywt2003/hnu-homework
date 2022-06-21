#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;

class rectangle{
	public:
		double height, width;
		
		rectangle():height(0), width(0){};
		rectangle(double x,double y):height(x), width(y){};

		double getPerimeter(){return height*2 + width*2;}
		double getArea(){return height*width;}
		double getDiagonalLength(){return sqrt(height*height + width*width);};
		bool isSquare(){return height==width;}
};

rectangle a;

int main(){
	cin>>a.height>>a.width;
	cout<<"length = "<<a.height<<",width = "<<a.width<<endl;
	cout<<"C = "<<a.getPerimeter()<<endl;
	cout<<"S = "<<a.getArea()<<endl;
	cout<<"The diagonal length = "<<a.getDiagonalLength()<<endl;
	cout<<((a.isSquare())?"Is square ? Yes":"Is square ? No")<<endl;
	return 0;
}