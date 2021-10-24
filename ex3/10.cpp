#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int x,y;
int ans;

signed main(){
	scanf("%d%d",&x,&y);
	ans=x*y;
	if (250<=y && y<500) ans*=0.98; else
	if (500<=y && y<1000) ans*=0.95; else
	if (1000<=y && y<2000) ans*=0.92; else
	if (2000<=y && y<3000) ans*=0.9; else
	if (3000<=y) ans*=0.85;
	printf("%d\n",ans);
	return 0;
}