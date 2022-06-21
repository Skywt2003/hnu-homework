#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=1e6+5;

int n;
char s[maxn];

bool isFu(char ch){
	return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
}

signed main(){
	scanf("%s",s+1); n=strlen(s+1);
	bool flg=true;
	for (int i=1;i<=n&&flg;i++) if (!isFu(s[i])){
		if (s[i]=='n') continue;
		if (i+1>n || !isFu(s[i+1])) flg=false;
	}
	printf(flg?"YES\n":"NO\n");
	return 0;
}