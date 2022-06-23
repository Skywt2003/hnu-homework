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

int to_int(char ch){
	return ch-'a';
}

char to_char(int x){
	return x+'a';
}

bool is_letter(char ch){
	return 'a'<=ch && ch<='z';
}

std::vector<int> add(std::vector<int> aa, std::vector<int> bb){
	std::vector<int> ret; ret.clear();
	int n=std::max(aa.size(),bb.size());
	for (int i=0;i<n;i++) ret.push_back(0);
	for (int i=aa.size();i<n;i++) aa.push_back(0); // 防止数组越界
	for (int i=bb.size();i<n;i++) bb.push_back(0);
	for (int i=0;i<n;i++){
		ret[i]=aa[i]+bb[i];
		if (ret[i]/26 && i+1>=n) ret.push_back(0);
		ret[i+1]+=ret[i]/26;
		ret[i]%=26;
	}
	return ret;
}

signed main(){
	t=read();
	while (t--){
		std::vector<int> aa,bb,cc; aa.clear(); bb.clear();
		char ch=getchar();
		while (!is_letter(ch)) ch=getchar();
		while (is_letter(ch)) aa.push_back(to_int(ch)),ch=getchar();
		while (!is_letter(ch)) ch=getchar();
		while (is_letter(ch)) bb.push_back(to_int(ch)),ch=getchar();
		reverse(aa.begin(),aa.end());
		reverse(bb.begin(),bb.end());
		cc=add(aa,bb);
		reverse(cc.begin(),cc.end());
		for (int i=0;i<(int)cc.size();i++) putchar(to_char(cc[i]));
		putchar('\n');
	}
	return 0;
}