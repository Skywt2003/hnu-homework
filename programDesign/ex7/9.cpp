#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=1e6+5;

int t,n;
char s[maxn];

bool isDigit(char ch){return '0'<=ch && ch<='9';}

signed main(){
	scanf("%d",&t);
	while (t--){
		scanf("%s",s+1); n=strlen(s+1);
		int lst=-1;
		bool flg=true;
		for (int i=1;i<=n&&flg;i++) if (isDigit(s[i])){
			if (lst!=-1 && lst+(s[lst]-'0') >= i-(s[i]-'0')) flg=false;
			lst=i;
		}
		// printf("%s\n",s+1);
		printf(flg?"safe\n":"unsafe\n");
	}
	return 0;
}