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

const int maxn=10;

int n,m;
char s1[maxn],s2[maxn];
int cnt1=0,cnt2=0;

void n_to_s1(){
	int nn=n;
	while (nn) s1[++cnt1]=nn%10+'0', nn/=10;
}

bool have_n(int x){
	int xx=x; cnt2=0;
	while (xx) s2[++cnt2]=xx%10+'0', xx/=10;
	for (int i=1;i<=cnt2-cnt1+1;i++){
		bool flg=true;
		for (int j=i;j<=i+cnt1-1;j++) if (s1[j-i+1]!=s2[j]) {flg=false;break;}
		if (flg) return true;
	}
	return false;
}

signed main(){
	m=read(),n=read();
	n_to_s1();
	for (int i=1;i<=m;i++) if (i%n==0 || have_n(i)) printf("%d ",i);
	printf("\n");
	return 0;
}