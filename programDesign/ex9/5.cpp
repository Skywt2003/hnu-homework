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

const int maxn=200005,maxm=200005,maxx=1005;

int n,m;

int cnt[maxx];

struct movie{
	int a,b,id;
};

movie a[maxm];

bool cmp(movie aa, movie bb){
	return aa.a>bb.a || (aa.a==bb.a && aa.b>bb.b) || (aa.a==bb.a && aa.b==bb.b && aa.id<bb.id);
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) cnt[read()]++;
	m=read();
	for (int i=1;i<=m;i++) a[i].a=cnt[read()];
	for (int i=1;i<=m;i++) a[i].b=cnt[read()],a[i].id=i;
	sort(a+1,a+1+m,cmp);
	
	if (a[1].a == 0 && a[1].b == 0) printf("unsatisfied\n");
	else {
		printf("%d ",a[1].id);
		int j=1;
		while (j+1<=m && a[j+1].a==a[1].a && a[j+1].b==a[1].b) j++,printf("%d ",a[j].id);
	}
	return 0;
}