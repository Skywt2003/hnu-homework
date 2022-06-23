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

const int maxn=100005;

int n;
int point[maxn],score[maxn];
int sum1=0,sum2=0;

int get_gp(int x){
	if (90<=x && x<=100) return 40; else
	if (85<=x && x<=89) return 37; else
	if (82<=x && x<=84) return 33; else
	if (78<=x && x<=81) return 30; else
	if (75<=x && x<=77) return 27; else
	if (72<=x && x<=74) return 23; else
	if (68<=x && x<=71) return 20; else
	if (64<=x && x<=67) return 15; else
	if (60<=x && x<=63) return 10; else
	return 0;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) point[i]=read(),sum1+=point[i];
	for (int i=1;i<=n;i++) score[i]=read(),sum2+=point[i]*get_gp(score[i]);

	printf("%.2lf\n",(double)sum2/10.0/(double)sum1);
	return 0;
}