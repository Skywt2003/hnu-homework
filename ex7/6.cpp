#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=1e6+5;

int t,n,mid;
char s[maxn];

bool isDigit(char ch){return '0'<=ch && ch<='9';}

signed main(){
	scanf("%d",&t);
	while (t--){
		scanf("%s",s+1); n=strlen(s+1);
		int lsum=0,rsum=0;
		for (int i=1;i<=n;i++) if (s[i]=='^') {mid=i; break;}
		for (int i=1;i<=n;i++) if (isDigit(s[i])){
			if (i<mid) lsum+=(s[i]-'0')*(mid-i);
			else rsum+=(s[i]-'0')*(i-mid);
		}
		if (lsum==rsum) printf("balance\n"); else
		if (lsum>rsum) printf("left\n"); else
		printf("right\n");
	}
	return 0;
}