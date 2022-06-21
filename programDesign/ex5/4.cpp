#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

struct student{
	int l,r,id,ans;
};

bool cmp(student aa,student bb){
	return (aa.l < bb.l) || (aa.l==bb.l && aa.id < bb.id);
}

bool cmp_by_id(student aa,student bb){
	return (aa.id < bb.id);
}

const int maxn=10005; // 又没给数据范围！！！
int t,n,maxt;
student a[maxn];

signed main(){
	t=read();
	while (t--){
		n=read(); maxt=0;
		for (int i=1;i<=n;i++)
			a[i].l=read(),a[i].r=read(),a[i].id=i,a[i].ans=0,
			maxt=max(maxt,a[i].l);
		maxt+=n;
		sort(a+1,a+1+n,cmp);
		int j=0,s=0;
		for (int i=1;i<=maxt;i++){
			while (j+1<=n && a[j+1].l==i) j++;
			for (;;){
				if (s+1 > j) break;
				if (i <= a[s+1].r) {a[s+1].ans=i,s++;break;}
				else s++;
			}
		}
		sort(a+1,a+1+n,cmp_by_id);
		for (int i=1;i<=n;i++) printf("%lld ",a[i].ans);
		printf("\n");
	}
	return 0;
}