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

const int maxn=105,maxA=10005;

int n,m;
int a[maxn*maxn];
int cnt[maxA];

signed main(){
	for (;;){
		n=read(); if (!n) break;
		m=n*(n-1)/2;
		for (int i=1;i<=m;i++) a[i]=read();
		for (int i=1;i<=a[1]/2;i++){
			// printf("checking %d\n",i);
			memset(cnt,0,sizeof(cnt));
			for (int j=1;j<=m;j++) cnt[a[j]]++;
			bool flg=true;
			vector<int> vec; vec.clear();
			vec.push_back(i);
			vec.push_back(a[1]-i); cnt[a[1]]--;
			vec.push_back(a[2]-i); cnt[a[2]]--;
			if (!cnt[vec[1]+vec[2]]) continue;
			cnt[vec[1]+vec[2]]--;
			int now_min=a[2]; while (!cnt[now_min]) now_min++;
			for (int j=4;j<=n;j++){
				vec.push_back(now_min-i);
				for (int k=0;k<(int)vec.size()-1;k++){
					if (!cnt[vec[k]+now_min-i]) {flg=false;break;}
					cnt[vec[k]+now_min-i]--;
				}
				if (!flg) break;
				if (j==n) break;
				while (!cnt[now_min]) now_min++;
			}
			if (flg){
				for (int i=0;i<(int)vec.size();i++) printf("%d ",vec[i]);
				break;
			}
		}
		printf("\n");
	}
}