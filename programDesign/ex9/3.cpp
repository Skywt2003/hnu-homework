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

const int maxn=500005;

int n;
struct obj{
	int x,y,z;
};

obj a[maxn];

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i].x=read();
	for (int i=1;i<=n;i++) a[i].y=read();
	for (int i=1;i<=n;i++) a[i].z=read();

	int ans=0;
	for (int i=1;i<=n;i++){
		bool flg=true;
		for (int j=1;j<=n&&flg;j++)
			if (a[j].x>a[i].x && a[j].y>a[i].y && a[j].z>a[i].z) {flg=false;break;}
		ans+=1-flg;
	}
	printf("%d\n",ans);
	return 0;
}