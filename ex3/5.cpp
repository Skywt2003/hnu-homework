#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int n;
int upc=0,lowc=0,num=0,other=0,sum=0;

signed main(){
	scanf("%d",&n);
	while (n--){
		char ch=getchar();
		while (ch==10 || ch==13) ch=getchar();
		if (ch>='a' && ch<='z') lowc++; else
		if (ch>='A' && ch<='Z') upc++; else
		if (ch>='0' && ch<='9') num++,sum+=ch-'0'; else
		other++;
	}
	if (num) printf("%d %d %d %d\n%d\n",upc,lowc,num,other,sum);
	else printf("%d %d %d %d\n",upc,lowc,num,other);
	return 0;
}