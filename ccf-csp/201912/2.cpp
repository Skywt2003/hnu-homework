#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005;

int n;
pair<int,int> a[maxn];
int ans[5];

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i].first=read(),a[i].second=read();

	for (int i=1;i<=n;i++){
		int now=0;
		for (int j=1;j<=n;j++) if (i!=j)
			if (abs(a[j].second-a[i].second) + abs(a[j].first-a[i].first) == 1) now++;
		if (now!=4) continue;
		now=0;
		for (int j=1;j<=n;j++) if (i!=j)
			if (abs(a[j].second-a[i].second)==1 && abs(a[j].first-a[i].first)==1) now++;
		ans[now]++;
	}
	
	for (int i=0;i<=4;i++) printf("%d\n",ans[i]);
	return 0;
}