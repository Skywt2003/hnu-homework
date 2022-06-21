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

#define int long long

int ans=0;

signed main(){
	char ch=getchar();
	while (ch!=10 && ch!=13 && ch!=-1) ans++,ch=getchar();
	printf("%lld\n",ans);
	return 0;
}