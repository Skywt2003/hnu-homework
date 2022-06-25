// 数据比较弱，只检测分层的错误算法可以得到 95 分 =_=

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

const int maxn=2e5+5;

int n;

int tot=0,lnk[maxn],nxt[maxn*2],to[maxn*2];
int fa[maxn],depth[maxn];

vector<int> level[maxn];
vector<int> son[maxn];

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

void build_tree(int x){
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]){
		fa[to[i]]=x; depth[to[i]]=depth[x]+1;
		son[x].push_back(to[i]);
		build_tree(to[i]);
	}
}

signed main(){
	n=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y); add_edge(y,x);
	}
	build_tree(1);
	for (int i=1;i<=n;i++)
		level[depth[i]+1].push_back(i),
		sort(son[i].begin(),son[i].end());
	vector<int> last; last.clear();
	for (int i=1;i<=n;i++){
		vector<int> vec; vec.clear();
		for (int j=0;j<(int)level[i].size();j++) vec.push_back(read());
		int ptr = 0;
		for (int j=0;j<(int)last.size();j++){
			vector<int> now; now.clear();
			for (int k=0;k<(int)son[last[j]].size();k++) now.push_back(vec[ptr++]);
			sort(now.begin(),now.end());
			if (now != son[last[j]]){
				// for (int t=0;t<(int)now.size();t++) printf("%d ",now[t]); printf("\n");
				// for (int t=0;t<(int)son[last[j]].size();t++) printf("%d ",son[last[j]][t]);  printf("\n");
				printf("No\n");
				return 0;
			}
		}
		last=vec;
		sort(vec.begin(),vec.end());
		if (vec != level[i]){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}