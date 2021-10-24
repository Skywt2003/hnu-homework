#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

int t;
double WBC,RBC,HGB,HCT,PLT;
char sex;

signed main(){
	t=read();
	while (t--){
		char ch=getchar(); while (ch!='f' && ch!='m') ch=getchar(); sex=ch;
		while (ch!=' ') ch=getchar();
		scanf("%lf%lf%lf%lf%lf",&WBC,&RBC,&HGB,&HCT,&PLT);
		int cnt=0;
		cnt += 1-(4.0<=WBC && WBC<=10.0);
		cnt += 1-(3.5<=RBC && RBC<=5.5);
		cnt += 1-((sex=='m' && 120.0<=HGB && HGB<=160.0) || (sex=='f' && 110.0<=HGB && HGB<=150.0));
		cnt += 1-((sex=='m' && 42.0<=HCT && HCT<=48.0) || (sex=='f' && 36.0<=HCT && HCT<=40.0));
		cnt += 1-(100.0<=PLT && PLT<=300.0);
		if (!cnt) printf("normal\n"); else printf("%lld\n",cnt);
	}
	return 0;
}

