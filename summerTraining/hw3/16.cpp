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

const int maxn=3000005;

double q;
int n,allw;
bool f[maxn];

vector<int> vec;

signed main(){
	cin>>q>>n; allw=q*100;
	while (n){
		vec.clear(); memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++){
			int x=read();
			int sum_now=0;  double now;
			bool flg=true;
			for (int j=1;j<=x;j++){
				char ch=getchar(); while (ch<'A' || ch>'Z') ch=getchar();
				if (ch!='A' && ch!='B' && ch!='C') flg=false;
				ch=getchar();
				cin>>now; sum_now+=now*100;
				if (now*100 > 60000) flg=false;
			}
			if (sum_now > 100000) flg=false;
			if (flg) vec.push_back(sum_now);
		}
		f[0]=true;
		for (int i=0;i<vec.size();i++)
			for (int j=allw;j>=vec[i];j--)
				f[j]|=f[j-vec[i]];
		for (int i=allw;i>=0;i--) if (f[i]){
			printf("%d.%02d\n",i/100,i%100);
			break;
		}
		cin>>q>>n; allw=q*100;
	}
	return 0;
}