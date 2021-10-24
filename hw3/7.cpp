#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int n;

int x3(int x){return x*x*x;}

signed main(){
	scanf("%d",&n);
	int m=0,nn=n;
	while (nn) m+=x3(nn%10),nn/=10;
	printf((n==m)?"Yes\n":"No\n");
	return 0;
}