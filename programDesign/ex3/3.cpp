#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int x,y;
char ch;

signed main(){
	scanf("%d",&x);
	ch=getchar(); while (ch!='y' && ch!='n') ch=getchar();
	scanf("%d",&y);
	printf((((x >= 5000) + (ch=='y') + (y <= 2000)) >=2)?"Accept\n":"Refuse\n");
	return 0;
}