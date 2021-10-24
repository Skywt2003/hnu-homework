#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int a,b,c,d,e,f;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	a=read(),b=read(),c=read(),d=read(),e=read(),f=read();
	printf("[%d,%d]\n[%d,%d]\n[%d,%d]\n",a,b,c,d,e,f);
	return 0;
}