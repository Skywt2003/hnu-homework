#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int a,da,b,db;

signed main(){
	a=read(),da=read(),b=read(),db=read();
	int xx=0,yy=0;
	while (a){
		if (a%10 == da) xx=xx*10+da;
		a/=10;
	}
	while (b){
		if (b%10 == db) yy=yy*10+db;
		b/=10;
	}
	printf("%lld\n",xx+yy);
	return 0;
}