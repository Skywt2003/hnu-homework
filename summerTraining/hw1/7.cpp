// y2 变量会与 math 库冲突，即使不 using namespace std 也会。

#include<cstdio>
#include<cstring>
#include<iostream>
// #include<algorithm>
// #include<vector>
// #include<queue>
#include<cmath>
// #include<map>

// using namespace std;
// #define int long long

#define sqr(_) ((_)*(_))

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

double x_1,y_1,x_2,y_2,x_3,y_3;

bool is_stop(){
	return x_1==0 && y_1==0 && x_2==0 && y_2==0 && x_3==0 && y_3==0;
}

double get_dist(double x_1,double y_1,double x_2,double y_2){
	return std::sqrt(sqr(x_1-x_2)+sqr(y_1-y_2));
}

signed main(){
	// std::cin>>x_1>>y_1>>x_2>>y_2>>x_3>>y_3;
	scanf("%lf%lf%lf%lf%lf%lf",&x_1,&y_1,&x_2,&y_2,&x_3,&y_3);
	while (!is_stop()){
		double a=get_dist(x_1,y_1,x_2,y_2);
		double b=get_dist(x_1,y_1,x_3,y_3);
		double c=get_dist(x_2,y_2,x_3,y_3);
		double p=(a+b+c)/2.0;
		double s=std::sqrt(p*(p-a)*(p-b)*(p-c));
		// std::cout<<s<<std::endl;
		printf("%.6lf\n",s);
		// std::cin>>x_1>>y_1>>x_2>>y_2>>x_3>>y_3;
		scanf("%lf%lf%lf%lf%lf%lf",&x_1,&y_1,&x_2,&y_2,&x_3,&y_3);
	}
	return 0;
}