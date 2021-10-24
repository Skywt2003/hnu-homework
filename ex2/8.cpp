#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int n,x,y;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	n=read(),x=read(),y=read();
	printf("%d\n",max(0,n-y/x-(y%x!=0)));
	return 0;
}