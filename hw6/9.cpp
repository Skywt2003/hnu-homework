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

// #define int long long

const int maxn=1006;

int n;
char a[maxn];

signed main(){
	scanf("%s",a+1); n=strlen(a+1);
	for (int i=1;i<=n/2;i++) if (a[i]!=a[n-i+1]) {printf("false\n");return 0;}
	printf("true\n");return 0;
}