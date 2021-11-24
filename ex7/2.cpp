#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int n;

const int maxn=1e6+5;
char s[maxn];
int lst_dot[maxn],nxt_dot[maxn],nxt_spc[maxn];
int sum_abc[maxn];
int ans=0;

bool isDigit(char ch){return '0'<=ch && ch<='9';}
bool isABC(char ch){return ('A'<=ch && ch<='Z')||('a'<=ch && ch<='z');}

signed main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++)
		sum_abc[i]=sum_abc[i-1]+isABC(s[i]),
		lst_dot[i]=(s[i]=='.')?i:lst_dot[i-1];
	nxt_spc[n+1]=nxt_dot[n+1]=n+1;
	for (int i=n;i>=1;i--)
		nxt_dot[i]=(s[i]=='.')?i:nxt_dot[i+1],
		nxt_spc[i]=(s[i]=='.'||s[i]=='_'||s[i]=='@'||isDigit(s[i]))?i:nxt_spc[i+1];
	for (int i=1;i<=n;i++) if (s[i]=='@'){
		if (nxt_dot[i] == n+1) continue;
		ans += (sum_abc[i-1]-sum_abc[lst_dot[i-1]]) * (nxt_spc[nxt_dot[i]+1]-nxt_dot[i]-1);
		// printf("%d %d\n",(sum_abc[i-1]-sum_abc[lst_dot[i-1]]), (nxt_spc[nxt_dot[i]+1]-nxt_dot[i]-1));
	}
	printf("%d\n",ans);
	return 0;
}