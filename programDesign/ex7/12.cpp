#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=1e6+5;

#define int long long

int t;
int n;
char s[maxn];

int gcd(int x,int y){
	return (y==0)?x:gcd(y,x%y);
}

int lcm(int x,int y){
	return x/gcd(x,y)*y;
}

signed main(){
	scanf("%lld",&t);
	while (t--){
		scanf("%s",s+1); n=strlen(s+1);
		int num1=0,num2=1,loop1=0,loop2=1,i;
		for (i=3;i<=n;i++){
			if (s[i]!='(') num1=num1*10+s[i]-'0',num2*=10;
			else break;
		}
		for (i++;i<=n;i++){
			if (s[i]!=')') loop1=loop1*10+s[i]-'0',loop2*=10;
			else break;
		}
		loop2--; loop2*=num2;
		if (loop2){
			int now_lcm = lcm(num2,loop2);
			num1 *= now_lcm / num2;
			loop1 *= now_lcm / loop2;
			num2 = now_lcm;
			num1 += loop1;
		}
		int now_gcd = gcd(num1, num2);
		num1 /= now_gcd; num2 /= now_gcd;
		printf("%lld/%lld\n",num1,num2);
	}
	return 0;
}