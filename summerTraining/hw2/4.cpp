#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>

// using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=600005;

int x,y;

int get_factor_sum(int x){
	int ret=1;
	for (int i=2;i<x;i++) if (x%i == 0) ret+=i;
	return ret;
}

signed main(){
	while (std::cin>>x>>y)
		printf((get_factor_sum(x)==y && get_factor_sum(y)==x)?"YES\n":"NO\n");
	return 0;
}