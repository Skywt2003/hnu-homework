#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>

// using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=105;
int n;
bool gym[maxn],acm[maxn];
int f[maxn][3]; // 0 rest; 1 gym; 2 acm

int min3(int x,int y,int z){return std::min(x,std::min(y,z));}

signed main(){
	n=read();
	for (int i=1;i<=n;i++){
		int x=read();
		gym[i]=x/2,acm[i]=x&1;
	}
	memset(f,0x3f,sizeof(f));
	f[0][0]=f[0][1]=f[0][2]=0;
	for (int i=1;i<=n;i++){
		f[i][0]=min3(f[i-1][0],f[i-1][1],f[i-1][2])+1;
		if (gym[i]) f[i][1]=std::min(f[i-1][0],f[i-1][2]);
		if (acm[i]) f[i][2]=std::min(f[i-1][0],f[i-1][1]);
	}
	printf("%d\n",min3(f[n][0],f[n][1],f[n][2]));
	return 0;
}