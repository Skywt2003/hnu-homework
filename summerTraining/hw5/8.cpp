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
int fa[maxn];
bool unrespect[maxn];

vector<int> sons[maxn];

signed main(){
	n=read();
	for (int i=1;i<=n;i++){
		fa[i]=read();
		if (fa[i]!=-1) sons[fa[i]].push_back(i);
		unrespect[i]=read();
	}
	bool printed=false;
	for (int i=1;i<=n;i++) if (unrespect[i]){
		bool can_delete=true;
		for (int j=0;j<(int)sons[i].size();j++) if (!unrespect[sons[i][j]]){
			can_delete=false;
			break;
		}
		if (can_delete) printf("%d ",i),printed=true;
	}
	if (!printed) printf("-1");
	printf("\n");
}