#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n;
vector<int> vec;

signed main(){
	n=read();
	for (int i=1;i<=n;i++) vec.push_back(read());
	sort(vec.begin(),vec.end());
	for (int i=0;i<(int)vec.size();i++) printf("%lld ",vec[i]);
	printf("\n");
	return 0;
}