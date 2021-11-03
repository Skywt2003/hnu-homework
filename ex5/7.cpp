#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

const int maxn=10005;
const int INF=1LL<<30;

int n,m,cnt=0;
pair<int,int> bus[maxn];

signed main(){
	n=read(); m=read();
	for (int i=1;i<=n;i++) bus[i].first=read(),bus[i].second=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) if (i!=j && bus[i].first!=INF && bus[j].first!=INF)
			if (bus[i].first <= bus[j].first && bus[j].second <= bus[i].second)
		 		bus[j]=make_pair(INF,INF),cnt++;
	sort(bus+1,bus+1+n);

	if (bus[1].first > 0 || bus[n-cnt].second < m){printf("No\n");return 0;}
	for (int i=2;i<=n-cnt;i++)
		if (bus[i].first > bus[i-1].second){printf("No\n");return 0;}
	printf("Yes\n");
	return 0;
}