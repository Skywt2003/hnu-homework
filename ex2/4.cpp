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
	int aa=d-a,bb=e-b,cc=f-c;
	if (cc<0) bb--,cc+=60;
	if (bb<0) aa--,bb+=60;
	printf("%d:%02d:%02d\n",aa,bb,cc);
	return 0;
}