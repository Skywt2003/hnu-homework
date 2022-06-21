#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,m;
int a[4];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int max_num=-1,max_id=0;
vector<int> vec;

signed main(){
	a[0]=read(),a[1]=read(),a[2]=read(),a[3]=read();
	for (int i=0;i<4;i++) if (a[i]>max_num) max_num=a[i],max_id=i;

	vec.clear();
	for (int i=0;i<4;i++) if (i!=max_id) vec.push_back(max_num-a[i]);
	sort(vec.begin(),vec.end());
	for (int i=0;i<3;i++) printf("%d ",vec[i]);
	printf("\n");
	return 0;
}