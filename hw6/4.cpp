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

int exponent(int num,int k){
	int ret=0;
	while (num%k==0) ret++,num/=k;
	if (num>1) return 0;
	return ret;
}

signed main(){
	x=read(),y=read();
	printf("%lld\n",exponent(x,y));
	return 0;
}