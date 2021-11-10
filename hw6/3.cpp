#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

int x,y;

int gcd(int x,int y){
	return (y==0)?x:gcd(y,x%y);
}

int lcm(int x,int y){
	return x/gcd(x,y)*y;
}

signed main(){
	x=read(),y=read();
	printf("%lld %lld\n",gcd(x,y),lcm(x,y));
	return 0;
}