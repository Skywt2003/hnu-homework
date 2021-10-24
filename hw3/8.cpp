#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int m;

int num(int x,int y,int z){return x*100+y*10+z;}

signed main(){
	scanf("%d",&m);
	for (int i=1;i<=9;i++)
		for (int j=0;j<=9;j++)
			for (int k=0;k<=9;k++){
				int now=num(i,k,j) + num(j,i,k) + num(j,k,i) + num(k,i,j) + num(k,j,i);
				if (now==m) {printf("%d%d%d\n",i,j,k);return 0;}
			}
	return 0;
}