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

const int maxn=40;

int n,n2;
int flg=1;

signed main(){
	n=read();
	if (n<0) flg=-1,n=-n;
	while (n) n2=n2*10+n%10,n/=10;
	if (flg*n2 < -2147483648 || flg*n2 > 2147483647) {printf("0\n"); return 0;}
	if (flg==-1) putchar('-');
	printf("%lld\n",n2);
	return 0;
}