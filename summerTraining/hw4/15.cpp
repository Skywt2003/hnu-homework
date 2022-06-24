#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>

using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const string week[7]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

const int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool is_run(int x){
	return (x%4==0) && (!(x%100==0 && x%400!=0));
}

void print_answer(int n){
	int tmp=(n+5)%7;
	int y=2000,m=1,d=1;
	while (n >= (is_run(y)?366:365)){
		n -= (is_run(y)?366:365);
		y++;
	}
	while (n >= days[m] + (m==2&&is_run(y))){
		n -= days[m] + (m==2&&is_run(y));
		m++;
	}
	d+=n;
	// cout<<y<<"-"<<m<<"-"<<d<<" "<<week[tmp]<<endl;
	printf("%d-%02d-%02d ",y,m,d);
	cout<<week[tmp]<<endl;
}

signed main(){
	for (;;){
		int n=read();
		if (n==-1) break;
		print_answer(n);
	}
	return 0;
}