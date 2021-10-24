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
	scanf("%d",&n); n=max(n,1);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n-i;j++) putchar(' ');
		for (int j=1;j<=i;j++) putchar('*'),putchar(' ');
		putchar('\n');
	}
	return 0;
}