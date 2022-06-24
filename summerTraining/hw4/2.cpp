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

int a[10];

signed main(){
	int x;
	while (cin>>x) a[x]++;

	for (int i=1;i<=9;i++) if (a[i]) {cout<<i,a[i]--;break;}
	for (int i=0;i<=9;i++)
		for (int j=0;j<a[i];j++)
			cout<<i;
	cout<<endl;
	return 0;
}