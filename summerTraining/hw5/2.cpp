#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int delta[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
const int INF=0x3f3f3f3f3f3f3f3f;

const int maxn=2005;
int n,m,w;
int a[maxn][maxn];
int dist[maxn][maxn];
bool vis[maxn][maxn];

int rdist[maxn][maxn];

bool can_go(int x,int y){
	return 1<=x && x<=n && 1<=y && y<=m;
}

void build_dist(){
	memset(vis,0,sizeof(vis));
	memset(dist,0x3f,sizeof(dist));
	queue<pair<int,int> > que;
	while (!que.empty()) que.pop();

	dist[1][1]=0;
	que.push(make_pair(1,1)); vis[1][1]=true;
	while (!que.empty()){
		pair<int,int> head=que.front(); que.pop();
		int xx=head.first,yy=head.second;
		for (int i=0;i<4;i++){
			int nx=xx+delta[i][0], ny=yy+delta[i][1];
			if (!can_go(nx,ny) || vis[nx][ny]) continue;
			if (a[nx][ny] == -1) continue;
			vis[nx][ny]=true;
			dist[nx][ny]=dist[xx][yy]+w;
			que.push(make_pair(nx,ny));
		}
	}
}

void build_rdist(){
	memset(vis,0,sizeof(vis));
	memset(rdist,0x3f,sizeof(rdist));
	queue<pair<int,int> > que;
	while (!que.empty()) que.pop();

	rdist[n][m]=0;
	que.push(make_pair(n,m)); vis[n][m]=true;
	while (!que.empty()){
		pair<int,int> head=que.front(); que.pop();
		int xx=head.first,yy=head.second;
		for (int i=0;i<4;i++){
			int nx=xx+delta[i][0], ny=yy+delta[i][1];
			if (!can_go(nx,ny) || vis[nx][ny]) continue;
			if (a[nx][ny] == -1) continue;
			vis[nx][ny]=true;
			rdist[nx][ny]=rdist[xx][yy]+w;
			que.push(make_pair(nx,ny));
		}
	}
}

signed main(){
	n=read(),m=read(),w=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			a[i][j]=read();
	build_dist();
	build_rdist();
	int xs=-1,ys=-1,xt=-1,yt=-1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) if (a[i][j]>0){
			if ((xs==-1 && ys==-1) || dist[i][j]+a[i][j]<dist[xs][ys]+a[xs][ys]) xs=i,ys=j;
			if ((xt==-1 && yt==-1) || rdist[i][j]+a[i][j]<rdist[xt][yt]+a[xt][yt]) xt=i,yt=j;
		}
	int ans=dist[n][m];
	if (xs!=-1 && ys!=-1 && xt!=-1 && yt!=-1) ans=min(ans, dist[xs][ys]+a[xs][ys]+a[xt][yt]+rdist[xt][yt]);
	if (ans>=INF) printf("-1\n"); else printf("%lld\n",ans);
	return 0;
}