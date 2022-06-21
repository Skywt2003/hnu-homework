#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=1e7+5;

int n,k;
pair<int,int> a[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int ans=0;

signed main(){
	n=read(), k=read();
	for (int i=1;i<=n;i++) a[i].first=read();
	for (int i=1;i<=n;i++) a[i].second=read();

	int s_pos = a[k].first;
	for (int i=1;i<=n;i++) if (i!=k) a[i].second-=a[k].second;
	a[k].second=0;
	
	sort(a+1,a+1+n);
	int l_fast=0,r_fast=0;
	for (int i=1;i<=n;i++){
		if (a[i].first<=s_pos) l_fast = max(l_fast, a[i].second);
		if (a[i].first>=s_pos) r_fast = min(r_fast, a[i].second);
	}
	for (int i=1;i<=n;i++)
		ans += (a[i].first==s_pos) || (a[i].first<s_pos && a[i].second>r_fast) || (a[i].first>s_pos && a[i].second<l_fast);

	cout<<ans<<endl;
	return 0;
}

/*

3 9 8 5 7 5
6 6 5 4 6 3

3  5  5  7  8  9
6  3  4  6  5  6
1 -2 -1  1  0  1
            ^
*/