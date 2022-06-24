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

int n;

signed main(){
	n=read();
	int ans=n/100; n%=100;
	ans+=n/20; n%=20;
	ans+=n/10; n%=10;
	ans+=n/5; n%=5;
	ans+=n;
	printf("%d\n",ans);
	return 0;
}