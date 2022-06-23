#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>

// using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

/*
-----0-----
|         |
5         1
|         |
-----6-----
|         |
4         2
|         |
-----3-----
*/

const bool flg[10][7]={
	{1,1,1,1,1,1,0}, // 0
	{0,1,1,0,0,0,0}, // 1
	{1,1,0,1,1,0,1}, // 2
	{1,1,1,1,0,0,1}, // 3
	{0,1,1,0,0,1,1}, // 4
	{1,0,1,1,0,1,1}, // 5
	{1,0,1,1,1,1,1}, // 6
	{1,1,1,0,0,0,0}, // 7
	{1,1,1,1,1,1,1}, // 8
	{1,1,1,1,0,1,1} // 9
};

bool can_change(int x,int y){
	bool add=false,sub=false;
	for (int i=0;i<7;i++)
		if (flg[x][i] && !flg[y][i]) sub=true; else
		if (!flg[x][i] && flg[y][i]) add=true;
	return !(add&&sub);
}

signed main(){
	int x=read();
	while (x!=-1){
		bool ans=true;
		for (int i=1;i<=9;i++){
			int y=read();
			if (!can_change(x,y)) ans=false;
			x=y;
		}
		printf(ans?"YES\n":"NO\n");
		x=read();
	}
}