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

const int maxn=5005;

int n;
char s[maxn];
int fa[maxn];

signed main(){
	scanf("%s",s+1); n=strlen(s+1);
	for (int i=1;i<=n;i++) fa[i]=fa[i-1]+(s[i]=='a');
	int ans=fa[n];
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			ans=std::max(ans, fa[i-1] + (fa[n]-fa[j]) + (j-i+1 - (fa[j]-fa[i-1])));
	printf("%d\n",ans);
	return 0;
}