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

int n;

signed main(){
	int cnt=0;
	n=read();
	while (n){
		cnt++;
		std::string s;
		std::vector<std::string> vec1,vec2;
		vec1.clear(); vec2.clear();
		for (int i=1;i<=n;i++){
			std::cin>>s;
			((i&1)?vec1:vec2).push_back(s);
		}
		std::cout<<"set-"<<cnt<<std::endl;
		for (int i=0;i<(int)vec1.size();i++) std::cout<<vec1[i]<<std::endl;
		for (int i=vec2.size()-1;i>=0;i--) std::cout<<vec2[i]<<std::endl;
		n=read();
	}
	return 0;
}