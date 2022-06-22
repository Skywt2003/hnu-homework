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

const int maxn=105;

int n,m;

struct obj {
	std::string s;
	int mess,id;
};

obj a[maxn];

int get_mess(std::string s){
	int len=s.length();
	int ret=0;
	for (int i=0;i<len;i++)
		for (int j=i+1;j<len;j++)
			ret+=(s[j]<s[i]);
	return ret;
}

bool cmp(obj aa,obj bb){
	return (aa.mess<bb.mess) || (aa.mess==bb.mess && aa.id<bb.id);
}

signed main(){
	std::cin>>n>>m;
	for (int i=1;i<=m;i++){
		std::cin>>a[i].s;
		a[i].mess=get_mess(a[i].s);
		a[i].id=i;
	}
	std::sort(a+1,a+1+m,cmp);
	for (int i=1;i<=m;i++) std::cout<<a[i].s<<std::endl;
	return 0;
}