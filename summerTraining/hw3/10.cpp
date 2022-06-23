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

map<int,int> ans;

signed main(){
	// int x=read(),y=read();
	// while (x||y){
	// 	ans[x]+=y;
	// 	x=read(),y=read();
	// }
	int x,y;
	while (cin>>x>>y) ans[x]+=y;
	map<int,int>::iterator it=ans.end(); it--;
	for (;;it--){
		if (it->second) printf("%d %d\n",it->first,it->second);
		if (it == ans.begin()) break;
	}
}