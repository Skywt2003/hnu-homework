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

const int INF=0x3f3f3f3f3f3f3f3f;

const int maxn=1e5+5,maxm=1e5+5;

int n,m;

int tot=0;
int lnk[maxn],nxt[maxm*2],to[maxm*2],w[maxm*2];

int dist[maxn];
bool vis[maxn];
int from[maxn];

priority_queue<pair<int,int> > heap;

void add_edge(int x,int y,int z){
	tot++; to[tot]=y; w[tot]=z;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

void Dijkstra(int s){
	memset(dist,0x3f,sizeof(dist));
	while (!heap.empty()) heap.pop();
	dist[s]=0; heap.push(make_pair(0,s));
	while (!heap.empty()){
		int head=heap.top().second; heap.pop();
		if (head==n) break;
		vis[head]=true;
		for (int i=lnk[head];i;i=nxt[i])
			if (vis[to[i]]==false && dist[head]+w[i] < dist[to[i]]){
				dist[to[i]]=dist[head]+w[i];
				heap.push(make_pair(-dist[to[i]],to[i]));
			}
	}
}

vector<int> find_path(int x){
	vector<int> ret; ret.clear();
	ret.push_back(x);
	if (x==n) return ret;

	vector<int> vec; vec.clear();
	for (int i=lnk[x];i;i=nxt[i]) if (dist[x]+w[i] == dist[to[i]]) vec.push_back(to[i]);
	sort(vec.begin(),vec.end());
	for (int i=0;i<(int)vec.size();i++){
		vector<int> now = find_path(vec[i]);
		if (now[(int)now.size()-1] == n){
			for (int j=0;j<(int)now.size();j++) ret.push_back(now[j]);
			return ret;
		}
	}
	return ret;
}

signed main(){
	n=read(),m=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		add_edge(x,y,z);add_edge(y,x,z);
	}
	Dijkstra(1);
	if (dist[n] == INF){
		printf("-1\n");
		return 0;
	}
	vector<int> vec=find_path(1);
	for (int i=0;i<(int)vec.size();i++) printf("%lld ",vec[i]);
	printf("\n");
	return 0;
}