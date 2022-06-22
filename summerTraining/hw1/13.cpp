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

const int maxn=15;

int t;
char s[maxn];

signed main(){
	t=read();
	while (t--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		for (int i=1;i<=n;i++)
			if (s[i]>'8') s[i]-=2; else
			if (s[i]>'3') s[i]-=1;
		int ans=0,w=1;
		for (int i=n;i>=1;i--) ans+=(s[i]-'0')*w,w*=8;
		printf("%d\n",ans);
	}
	return 0;
}