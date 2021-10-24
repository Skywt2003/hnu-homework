#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int x;

signed main(){
	scanf("%d",&x);
	if (90<=x) printf("A\n"); else
	if (80<=x && x<=89) printf("B\n"); else
	if (70<=x && x<=79) printf("C\n"); else
	if (60<=x && x<=69) printf("D\n"); else
	printf("E\n");
	return 0;
}