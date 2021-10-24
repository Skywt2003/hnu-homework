#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

signed main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d+%d=%d\n",a,b,a+b);
	printf("%d-%d=%d\n",a,b,a-b);
	printf("%d*%d=%d\n",a,b,a*b);
	printf("%d/%d=%.2lf\n",a,b,1.0*a/b);
	printf("%d%%%d=%d\n",a,b,a%b);
	return 0;
}