#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int T;
int n,k;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	T=read();
	while (T--){
		n=read();k=read();
		int tot=0,ans=0;
		for (int i=1;i<=n;i++){
			int ti=read(),di=read();
			if (tot >= k) ans+=ti*di; else
			if (tot <= k && tot+ti > k) ans+=(tot+ti-k)*di;
			tot+=ti;
		}
		cout<<ans<<endl;
	}
	return 0;
}
