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
	int nn=0,now=1,ret=0;
	for (;;){
		if (nn+now > n){
			ret+=(n-nn)*now;
			break;
		}
		ret+=now*now;
		nn+=now; now++;
	}
	return ret;
}

signed main(){
	int n;
	while (std::cin>>n) std::cout<<n<<" "<<get_answer(n)<<std::endl;
	return 0;
}