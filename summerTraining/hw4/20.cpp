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

const int maxn=105;

int n;
pair<int,int> a[maxn];
int rnk[maxn];

bool cmp(pair<int,int> aa,pair<int,int> bb){
	return aa > bb;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i].first=read(),a[i].second=i;
	sort(a+1,a+1+n,cmp);

	int cnt=0;
	for (int i=1;i<=n;i++){
		int j=i;
		while (j+1<=n && a[j+1].first==a[i].first) j++;
		cnt++;
		for (int k=i;k<=j;k++) rnk[a[k].second]=cnt;
		i=j;
	}
	for (int i=1;i<=n;i++) printf("%d ",rnk[i]);
	printf("\n");
	return 0;
}