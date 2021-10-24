#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int n,a[4];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	for (int i=0;i<4;i++) a[i]=read();
	sort(a,a+4);
	for (int i=3;i>=0;i--) printf("%d ",a[i]);printf("\n");
	return 0;
}