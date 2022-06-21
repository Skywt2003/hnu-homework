#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

int n;

signed main(){
	n=read();
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n-i+1;j++) putchar(' ');
		putchar('*');
		for (int j=1;j<=2*i-3;j++) putchar(' ');
		if (i-1) putchar('*');
		putchar('\n');
	}
	putchar('*'); for (int i=1;i<=2*n-1;i++) putchar(' '); putchar('*'); putchar('\n');
	for (int i=n;i>=1;i--){
		for (int j=1;j<=n-i+1;j++) putchar(' ');
		putchar('*');
		for (int j=1;j<=2*i-3;j++) putchar(' ');
		if (i-1) putchar('*');
		putchar('\n');
	}
	return 0;
}