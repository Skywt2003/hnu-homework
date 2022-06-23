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

int get_answer(int n){
	int ret=0;
	while (n-1) n=(n&1)?((3*n+1)/2):(n/2),ret++;
	return ret;
}

signed main(){
	int n=read();
	while (n){
		std::cout<<get_answer(n)<<std::endl;
		n=read();
	}
	return 0;
}