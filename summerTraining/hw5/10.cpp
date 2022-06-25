#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>

using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5;

int n;
int a[maxn];

int tot=0,lnk[maxn],nxt[maxn*2],to[maxn*2],w[maxn*2];

bool should_delete[maxn];

void add_edge(int x,int y,int z){
	tot++; w[tot]=z; to[tot]=y;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

void scan_tree(int x,int fa,int dist){ // 返回 dist(x,y) 的最大值
	if (fa!=-1 && should_delete[fa]) should_delete[x]=true;
	if (dist > a[x]) should_delete[x]=true;
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa){
		scan_tree(to[i],x,std::max(0,dist+w[i]));
	}
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=2;i<=n;i++){
		int x=read(),z=read();
		add_edge(i,x,z);
		add_edge(x,i,z);
	}
	scan_tree(1,-1,0);
	int ans=0;
	for (int i=1;i<=n;i++){
		ans+=should_delete[i];
		// if (should_delete[i]) printf("%d ",i);
	}
	// printf("\n");
	printf("%d\n",ans);
	return 0;
}