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

int x,ans;

signed main(){
	x=read();
	for (int i=0;i*5<=x;i++){
		int lft=x-i*5;
		ans+=lft/3+1;
	}
	printf("%lld\n",ans);
	return 0;
}