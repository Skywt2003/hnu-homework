#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>

// using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n,k;

std::set<int> s;

signed main(){
	n=read(); k=read();
	while (n--) s.insert(read());
	std::set<int>::iterator it=s.begin();
	while (k-- && it!=s.end()) std::cout<<(*it)<<" ",it++;
	std::cout<<std::endl;
	return 0;
}