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

std::vector<std::string> vec;

bool is_goodchar(char ch){
	return ch!=' ' && ch!=10 && ch!=13 && ch!=-1;
}

signed main(){
	// freopen("test.in","r",stdin);
	char ch=getchar();
	for (;;){
		if (!is_goodchar(ch)){
			if (ch==10 || ch==13 || ch==-1){
				if ((int)vec.size()>0){
					for (int i=vec.size()-1;i>0;i--) std::cout<<vec[i]<<" ";
					std::cout<<vec[0]<<std::endl;
					vec.clear();
				}
				while (ch==10 || ch==13) ch=getchar();
			} else {
				while (!is_goodchar(ch)) ch=getchar();
			}
			if (ch==-1) return 0;
		}
		std::string now="";
		while (is_goodchar(ch)) now+=ch,ch=getchar();
		vec.push_back(now);
	}
	return 0;
}