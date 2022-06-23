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

map<int,int> score;

signed main(){
	int n=read();
	for (int i=1;i<=n;i++){
		int x=read(),y=read();
		score[x]+=y;
	}
	map<int,int>::iterator it,ans=score.begin();
	for (it=score.begin();it!=score.end();it++)
		if (it->second > ans->second) ans=it;
	printf("%d %d\n",ans->first,ans->second);
	return 0;
}