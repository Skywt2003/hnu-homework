#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int n,m;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int xx,sl,kc;

signed main(){
	n=read(),m=read();
	xx=n-5000-m;
	if (xx<=3000) sl=3,kc=0; else
	if (xx<=12000) sl=10,kc=210; else
	if (xx<=25000) sl=20,kc=1410; else
	if (xx<=35000) sl=25,kc=2660; else
	if (xx<=55000) sl=30,kc=4410; else
	if (xx<=80000) sl=35,kc=7160; else
	sl=45,kc=15160;
	printf("%d\n",max(0,xx*sl/100 - kc));
	return 0;
}