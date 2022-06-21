#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

signed main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%.3lf%%\n",100.0*b/a);
	return 0;
}