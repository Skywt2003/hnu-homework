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

const int maxn=105;

int n;
int tot=0,lnk[maxn],nxt[maxn*2],to[maxn*2],w[maxn*2];
int dist[maxn];

void add_edge(int x,int y,int z){
	tot++; to[tot]=y; w[tot]=z;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

void build_dist(int x,int fa){
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa)
		dist[to[i]]=dist[x]+w[i],
		build_dist(to[i],x);
}

signed main(){
	n=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read(),z=read();
		add_edge(x+1,y+1,z);
		add_edge(y+1,x+1,z);
	}
	build_dist(1,-1);
	int ans=0;
	for (int i=1;i<=n;i++) ans=std::max(ans,dist[i]);
	printf("%d\n",ans);
	return 0;
}