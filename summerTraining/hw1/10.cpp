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

int t;

int pop_count(int x){
	int ret=0;
	while (x) ret+=x&1,x>>=1;
	return ret;
}

signed main(){
	t=read();
	while (t--){
		int ans=0;
		for (int i=1;i<=4;i++){
			int x=read();
			ans+=pop_count(x);
		}
		printf("%d\n",ans);
	}
	return 0;
}