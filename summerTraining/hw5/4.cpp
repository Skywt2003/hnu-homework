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

int tot=0,lnk[maxn],nxt[maxn*2],to[maxn*2]; // 用邻接表存图
int fa[maxn],depth[maxn];

vector<int> level[maxn]; // 存储每一层包含的节点
vector<int> son[maxn]; // son[i] 表示 i 的儿子节点组成的集合

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
		// 此处排序是为了方便比较两个 vector 中的元素是否相同，相当于把两个 vector 看成集合
		// 下面的排序同理
	vector<int> last; last.clear();
	for (int i=1;i<=n;i++){ // BFS 必然是一层一层处理
		vector<int> vec; vec.clear();
		for (int j=0;j<(int)level[i].size();j++) vec.push_back(read());
		int ptr = 0;
		for (int j=0;j<(int)last.size();j++){
			vector<int> now; now.clear();
			for (int k=0;k<(int)son[last[j]].size();k++) now.push_back(vec[ptr++]);
			sort(now.begin(),now.end());
			if (now != son[last[j]]){ // 第一个检测：当前层按顺序是上一层各个节点的儿子组成
				printf("No\n");
				return 0;
			}
			// 关于这个检测，考虑一个简单的反例：
			//    1
			//  2   3
			//  4   5
			// BFS 序：1 2 3 5 4 是错误的
			// 也就是新的一层必须「按顺序」是上面一层各个节点的儿子
		}
		last=vec;
		sort(vec.begin(),vec.end());
		if (vec != level[i]){ // 第二个检测：树的每一层节点集合
		// 这个比较容易想到，如果只写这个检测能拿到 95 分 =_=
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}