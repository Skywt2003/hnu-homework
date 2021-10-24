#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n;

signed main(){
	scanf("%d",&n);
	int cnt=0;
	while (n) cnt++,n=n/10;
	printf("%d\n",cnt);
	return 0;
}