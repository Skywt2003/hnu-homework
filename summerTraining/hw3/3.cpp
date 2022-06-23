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

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

bool is_digit(char ch){
	return '0'<=ch && ch<='9';
}

const int maxn=1005;

int a[maxn],ans[maxn],n=0,b;

signed main(){
	char ch=getchar();
	while (is_digit(ch)) a[++n]=ch-'0',ch=getchar();
	ch=getchar();
	b=ch-'0';

	int yu=0;
	for (int i=1;i<=n;i++){
		ans[i]=(a[i]+yu)/b;
		yu=(a[i]+yu - ans[i]*b)*10;
	}
	yu/=10;
	int head=1;
	while (ans[head]==0 && head+1<=n) head++;
	for (int i=head;i<=n;i++) putchar(ans[i]+'0');
	putchar(' ');
	printf("%d\n",yu);
	return 0;
}