#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

signed main(){
	int t;
	scanf("%d",&t);
	printf("(%d,%.1lf)\n",t*200,3000.0-9.8*t*t/2.0);
	return 0;
}