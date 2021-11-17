#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

// #define int long long

const int maxn=1006;

int delta,n;
char s[maxn];

signed main(){
	delta=read();
	scanf("%s",s); n=strlen(s);
	for (int i=0;i<n;i++) if ('A'<=s[i] && s[i]<='Z'){
		s[i]+=delta;
		if (s[i]>'Z') s[i]-=26;
	}
	printf("%s\n",s);
	return 0;
}