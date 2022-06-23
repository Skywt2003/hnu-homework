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

std::vector<std::string> dict;

bool check(std::string s1,std::string s2){
	if (s1.length()==s2.length()){
		int cnt=0;
		for (int i=0;i<(int)s1.length();i++) cnt+=(s1[i]!=s2[i]);
		return cnt<=1;
	} else if (s1.length()-s2.length() == 1){
		int j=0,cnt=0;
		for (int i=0;i<(int)s2.length();i++,j++){
			while (cnt+1<=1 && s2[i]!=s1[j]) j++,cnt++;
			if (cnt>1 || s2[i]!=s1[j]) return false;
		}
		return cnt<=1;
	} else if (s2.length()-s1.length() == 1){
		int j=0,cnt=0;
		for (int i=0;i<(int)s1.length();i++,j++){
			while (cnt+1<=1 && s1[i]!=s2[j]) j++,cnt++;
			if (cnt>1 || s1[i]!=s2[j]) return false;
		}
		return cnt<=1;
	}return false;
}

signed main(){
	for (;;){
		std::string s; std::cin>>s;
		if (s=="#") break;
		dict.push_back(s);
	}
	for (;;){
		std::string s; std::cin>>s;
		if (s=="#") break;
		bool have=false;
		for (int i=0;i<(int)dict.size();i++)
			if (dict[i]==s) {have=true; break;}
		if (have){
			std::cout<<s<<" is correct"<<std::endl;
			continue;
		}
		std::cout<<s<<": ";
		for (int i=0;i<(int)dict.size();i++)
			if (check(dict[i],s)) std::cout<<dict[i]<<" ";
		std::cout<<std::endl;
	}
}