#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=1005;

int n=0;
char s[maxn];

signed main(){
	char ch=getchar();
	while (ch!=10 && ch!=13 && ch!=-1) s[n++]=ch,ch=getchar();
	s[n]=0;
	for (int i=2;i<=n;i++) if (n%i==0) reverse(s,s+i);
	printf("%s\n",s);
	return 0;
}