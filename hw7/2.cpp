#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=100005;

pair<int,int> aa,bb;
int n;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int ans=0;

signed main(){
	aa.first=read(), aa.second=read();
	bb.first=read(), bb.second=read();
	swap(aa.second, bb.second);

	n=read();
	while (n--){
		pair<int,int> now;
		now.first=read(),now.second=read();
		ans+= (aa.first<=now.first && now.first<=bb.first) && (aa.second<=now.second && now.second<=bb.second);
	}

	printf("%d\n",ans);
	return 0;
}