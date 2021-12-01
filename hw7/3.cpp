#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=15;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

struct student{
	string a,c,d;
	int b;
};

student a[maxn];

bool cmp(student aa,student bb){
	return aa.b < bb.b;
}

signed main(){
	for (int i=1;i<=10;i++) cin>>a[i].a>>a[i].b>>a[i].c>>a[i].d;
	printf("Before ordering(id|age|name|sex)\n");
	for (int i=1;i<=10;i++) cout<<"("<<a[i].b<<"|"<<a[i].d<<"|"<<a[i].a<<"|"<<a[i].c<<")"<<endl;
	sort(a+1,a+11,cmp);
	printf("After ordering(id|age|name|sex)\n");
	for (int i=1;i<=10;i++) cout<<"("<<a[i].b<<"|"<<a[i].d<<"|"<<a[i].a<<"|"<<a[i].c<<")"<<endl;
	return 0;
}