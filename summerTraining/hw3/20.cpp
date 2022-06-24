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

const int maxn=10005;

int n,m,q;

pair<int,int> a[maxn];
bool vis[maxn];

signed main(){
	n=read(),m=read(); n=n*n;
	q=read();
	while (q--){
		string opt; cin>>opt;
		if (opt=="in"){
			int id=read(),x=read();
			if (a[id] != make_pair(0,0)) {cout<<"no"<<endl;continue;}
			int cnt=0,start=-1;
			for (int i=1;i<=n;i++){
				if (vis[i]) cnt=0; else cnt++;
				if (cnt==x) {start=i-x+1;break;}
			}
			if (start==-1) cout<<"no"<<endl; else {
				for (int i=start;i<=start+x-1;i++) vis[i]=true;
				a[id]=make_pair(start,start+x-1);
				cout<<"yes"<<endl;
			}
		} else if (opt=="out"){
			int id=read();
			if (a[id] == make_pair(0,0)) {cout<<"no"<<endl;continue;}
			for (int i=a[id].first;i<=a[id].second;i++) vis[i]=false;
			a[id]=make_pair(0,0);
			cout<<"yes"<<endl;
		} else cout<<"Invalid OPT"<<endl;
	}
	return 0;
}