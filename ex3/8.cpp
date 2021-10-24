#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int y[3],m[3],d[3],id[3];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

void chang(int i,int j){
	swap(y[i],y[j]);
	swap(m[i],m[j]);
	swap(d[i],d[j]);
	swap(id[i],id[j]);
}

signed main(){
	for (int i=0;i<3;i++) y[i]=read(),m[i]=read(),d[i]=read(),id[i]=i+'A';
	for (int i=0;i<2;i++)
		for (int j=i+1;j<3;j++)
			if (y[i]>y[j] || (y[i]==y[j]&&m[i]>m[j]) || (y[i]==y[j]&&m[i]==m[j]&&d[i]>d[j])) chang(i,j);
	printf("%c%c%c\n",id[0],id[1],id[2]);
	return 0;
}