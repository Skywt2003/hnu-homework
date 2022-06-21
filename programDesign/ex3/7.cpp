#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int x;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

double t1,t2;

signed main(){
	x=read();
	t1 = 50.0 + 1.0*x/3.0;
	t2 = 1.0*x/1.2;
	if (t1==t2) printf("All\n");
	else printf((t1<t2)?"Bike\n":"Walk\n");
	return 0;
}