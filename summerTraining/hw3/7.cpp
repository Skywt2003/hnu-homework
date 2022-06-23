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

string get_pinyin(int x){
	if (x==0) return "ling";
	if (x==1) return "yi";
	if (x==2) return "er";
	if (x==3) return "san";
	if (x==4) return "si";
	if (x==5) return "wu";
	if (x==6) return "liu";
	if (x==7) return "qi";
	if (x==8) return "ba";
	if (x==9) return "jiu";
	return "meiyou";
}

signed main(){
	int ans=0;
	char ch=getchar();
	while ('0'<=ch && ch<='9') ans+=ch-'0',ch=getchar();
	vector<int> vec; vec.clear();
	while (ans) vec.push_back(ans%10),ans/=10;
	for (int i=(int)vec.size()-1;i>=0;i--) cout<<get_pinyin(vec[i])<<" ";
	if ((int)vec.size() == 0) cout<<"ling";
	cout<<endl;
}