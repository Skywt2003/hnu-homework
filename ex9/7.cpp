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

int n,k;

int a[maxn];

struct opt{
	int t,id;
	bool flg; // 0 取 1 还
};

vector<opt> vec;

bool cmp(opt aa,opt bb){
	return (aa.t<bb.t) || (aa.t==bb.t && aa.flg>bb.flg) || (aa.t==bb.t && aa.flg==bb.flg && aa.id<bb.id);
}

signed main(){
	n=read(),k=read();
	for (int i=1;i<=n;i++) a[i]=i;
	for (int i=1;i<=k;i++){
		int id=read(),s=read(),t=read();
		vec.push_back((opt){s,id,false});
		vec.push_back((opt){s+t,id,true});
	}
	sort(vec.begin(),vec.end(),cmp);
	for (int i=0;i<(int)vec.size();i++){
		if (!vec[i].flg) {
			for (int j=1;j<=n;j++) if (a[j]==vec[i].id) {a[j]=0; break;}
		} else {
			for (int j=1;j<=n;j++) if (!a[j]) {a[j]=vec[i].id; break;}
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	printf("\n");
	return 0;
}