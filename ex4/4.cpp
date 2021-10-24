#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

int n;

int get_num(int x){
	int ret=1;
	while (x){
		if (x%10) ret*=x%10;
		x/=10;
	}
	return ret;
}

signed main(){
	n=read();
	while (n>=10){
		printf("%lld ",n);
		n=get_num(n);
	}
	printf("%lld\n",n);
	return 0;
}