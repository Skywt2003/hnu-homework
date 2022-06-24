#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>

// using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2005;
const int INF=0x3f3f3f3f;

int n,allw;
int a[maxn];
int f[maxn];

signed main(){
	for (;;){
		memset(f,0x3f,sizeof(f));
		allw=read(); if (!allw) break;
		n=read(); for (int i=1;i<=n;i++) a[i]=read();

		f[0]=0;
		for (int i=1;i<=n;i++)
			for (int j=a[i];j<=allw;j++)
				f[j]=std::min(f[j],f[j-a[i]]+1);
		if (f[allw]==INF) printf("Impossible\n");
		else printf("%d\n",f[allw]);
	}
	return 0;
}