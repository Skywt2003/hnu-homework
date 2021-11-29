#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=1e6+5;

int n1,n2;
char s1[maxn],s2[maxn];

signed main(){
	scanf("%s",s1+1); n1=strlen(s1+1);
	scanf("%s",s2+1); n2=strlen(s2+1);
	int cnt=0;
	for (int i=n1,j=n2;i>=1&&j>=1;i--,j--,cnt++)
		if (s1[i]!=s2[j]) break;
	printf("%d\n",n1+n2-cnt-cnt);
	return 0;
}