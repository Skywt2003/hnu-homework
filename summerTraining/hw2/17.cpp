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

const int maxn=205;

int n,A,B,C;
int a[maxn];

signed main(){
	while (cin>>n>>A>>B>>C){
		char ch=getchar(); while (ch!='N' && ch!='G') ch=getchar();
		for (int i=0;i<n;i++){
			a[i]=(ch=='N')?-1:read();
			if (i==n-1) continue;
			ch=getchar(); while (ch!='N' && ch!='G') ch=getchar();
		}
		int x[2],f=(A*C+B)%6+1,now=0;
		x[0]=x[1]=0;
		for (;;){
			x[now]=x[now]+f;
			if (x[now]>(n-1)) x[now]=(n-1)-(x[now]-(n-1));
			if (x[now]==x[1-now] && x[now]!=0) x[now]=0;
			while (a[x[now]]!=-1){
				x[now]=a[x[now]];
				if (x[now]==x[1-now] && x[now]!=0) x[now]=0;
			}
			if (x[now]==n-1){
				cout<<(now?"Yueyue":"Lele")<<endl;
				break;
			}
			f=(A*f+B)%6+1; now=1-now;
		}
	}
}