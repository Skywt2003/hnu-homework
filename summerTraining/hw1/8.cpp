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

const int maxn=65;

int n;
char tmp[maxn];
int s[maxn],ss[maxn];

signed main(){
	scanf("%s",tmp+1);
	n=strlen(tmp+1);
	for (int i=1;i<=n;i++) s[i]=tmp[i]-'0';
	for (int i=2;i<=n;i++){
		for (int j=0;j<=n;j++) ss[j]=s[j]*i;
		for (int j=n;j>=1;j--){
			ss[j-1]+=ss[j]/10;
			ss[j]%=10;
		}
		if (ss[0]){printf("No\n"); return 0;}
		// for (int j=1;j<=n;j++) putchar(ss[j]+'0'); putchar('\n');
		bool now=false;
		for (int j=0;j<n;j++){
			bool flg=true;
			for (int k=1;k<=n;k++) if (s[(k+n-1)%n+1]!=ss[(k+j+n-1)%n+1]) {flg=false;break;}
			now|=flg;
		}
		if (!now){printf("No\n"); return 0;}
	}
	printf("Yes\n");
	return 0;
}