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

const int maxn=15;

int t;

int get_num(string s){
	if (s=="monday") return 0; else
	if (s=="tuesday") return 1; else
	if (s=="wednesday") return 2; else
	if (s=="thursday") return 3; else
	if (s=="friday") return 4; else
	if (s=="saturday") return 5; else
	if (s=="sunday") return 6;
	return -1;
}

signed main(){
	t=read();
	while (t--){
		string s,t;
		int l,r,dest;
		cin>>s>>t>>l>>r;
		dest=(get_num(t)-get_num(s)+7)%7;
		int ansn=0,ans=0;
		for (int i=l;i<=r;i++) if ((i+6)%7==dest) ansn++,ans=i;
		if (ansn==0) cout<<"impossible"<<endl; else
		if (ansn>1) cout<<"many"<<endl; else
		cout<<ans<<endl;
	}
	return 0;
}