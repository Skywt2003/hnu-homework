#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;

int n;

bool check_prime(int x){
	for (int i=2;i<=sqrt(x);i++) if (x%i==0) return false;
	return true;
}

signed main(){
	scanf("%d",&n);
	if (n<=1) {printf("2\n");return 0;}
	for (;;){
		n++;
		if (!(n&1)) continue;
		if (check_prime(n)){printf("%d\n",n);return 0;}
	}
	return 0;
}