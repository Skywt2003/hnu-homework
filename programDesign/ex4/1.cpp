#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n;

signed main(){
	n=read();
	int ans=0,now=1;
	for (int i=1;i<=n;i++) ans+=now,now+=i+1;
	printf("%d\n",ans);
	return 0;
}