#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int x,y;

const int days[12]={31,-1,31,30,31,30,31,31,30,31,30,31};

signed main(){
	scanf("%d%d",&x,&y);
	if (y==2){
		if ((x%4==0 && x%100!=0) || (x%400==0)) printf("29\n");
		else printf("28\n");
	} else printf("%d\n",days[y-1]);
	return 0;
}