#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

const int maxn=10005;
// 题目又不给数据范围 气死👴了

int n,m,a,d;
vector<int> vec;

signed main(){
	n=read(),m=read(),a=read(),d=read();
	for (int i=1;i<=m;i++) vec.push_back(read());
	for (int i=1;i<=n;i++) vec.push_back(i*a);
	sort(vec.begin(),vec.end());
	int ans=0,lst=-1;
	for (int i=0;i<vec.size();i++)
		if (lst==-1 || vec[i] > lst+d) ans++,lst=vec[i];
	printf("%lld\n",ans);
	return 0;
}