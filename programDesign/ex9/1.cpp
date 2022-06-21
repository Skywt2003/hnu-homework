#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=100005;

int n;
pair<string,int> a[maxn];
int tmp[7];

bool cmp(pair<string,int> aa,pair<string,int> bb){
	return aa.second > bb.second;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++){
		cin>>a[i].first;
		for (int j=0;j<7;j++) tmp[j]=read();
		sort(tmp,tmp+7);
		a[i].second = 0;
		for (int j=1;j<6;j++) a[i].second+=tmp[j];
	}
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++)
		cout<<a[i].first<<" "<<a[i].second<<endl;
	
	return 0;
}