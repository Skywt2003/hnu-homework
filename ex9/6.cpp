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

const int maxn=2e5+5;

int n,m;

struct frog{
	int x,y,id,cnt;
};

struct fly{
	int x,y;
	bool eated;
};

frog a[maxn];

bool cmp_x(frog aa,frog bb){return aa.x<bb.x;}
bool cmp_id(frog aa,frog bb){return aa.id<bb.id;}

fly b[maxn];

signed main(){
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i].x=read(),a[i].y=read(),a[i].id=i;
	sort(a+1,a+1+n,cmp_x);
	for (int i=1;i<=m;i++) b[i].x=read(),b[i].y=read(),b[i].eated=false;
	for (int tt=0;tt<m;tt++){
		for (int i=1;i<=m;i++) if (!b[i].eated){
			for (int j=1;j<=n;j++) if (a[j].x<=b[i].x && a[j].x+a[j].y>=b[i].x){
				a[j].cnt++; a[j].y+=b[i].y;
				b[i].eated=true;
				break;
			}
			if (b[i].eated) break;
		}
	}
	sort(a+1,a+1+n,cmp_id);
	for (int i=1;i<=n;i++) printf("%d %d\n",a[i].cnt,a[i].y);
	return 0;
}