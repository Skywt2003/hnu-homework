#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

int n;
vector<int> vec;

signed main(){
	n=read();
	int lst=0;
	for (int i=1;i<=n;i++){
		int now=read();
		if (now != lst+1) vec.push_back(lst);
		lst=now;
	}
	vec.push_back(lst);
	printf("%lld\n",(int)vec.size());
	for (int i=0;i<vec.size();i++) printf("%lld ",vec[i]);
	printf("\n");
	return 0;
}