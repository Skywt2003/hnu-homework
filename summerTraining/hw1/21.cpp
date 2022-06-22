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

const int maxn=1e4+4;

int t;
int b,n;
char s[maxn];
int a[maxn];

int to_number(char ch){
	if ('0'<=ch && ch<='9') return ch-'0'; else
	return ch-'a'+10;
}

char to_char(int x){
	// printf("x=%d\n",x);
	if (x<10) return '0'+x; else
	return 'a'+x-10;
}

signed main(){
	t=read();
	while (t--){
		b=read();
		scanf("%s",s+1);
		int n=strlen(s+1);
		for (int i=1;i<=n;i++) a[i]=to_number(s[i]);
		int w=1,tot=0;
		for (int i=n;i>=1;i--){
			tot = (tot + a[i]%(b-1) * w)%(b-1);
			w = w*b%(b-1);
		}
		// printf("tot=%d\n",tot);
		putchar(to_char((b-1-tot)%(b-1))); putchar('\n');
	}
	return 0;
}