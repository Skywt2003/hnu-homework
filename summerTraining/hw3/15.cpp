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

int a[10];

signed main(){
	char ch=getchar();
	while (ch!=10 && ch!=13) a[ch-'0']++,ch=getchar();
	string s;
	while (cin>>s){
		if (s.length() == 1){
			bool yes=false;
			for (int i=s[0]-'0'+1;i<=9;i++) if (a[i]){yes=true;break;}
			printf(yes?"YES ":"NO");
			for (int i=s[0]-'0'+1;i<=9;i++) if (a[i]) printf("%d ",i);
			printf("\n");
		} else if (s.length() == 2){
			bool yes=false;
			for (int i=s[0]-'0'+1;i<=9;i++) if (a[i]>=2){yes=true;break;}
			printf(yes?"YES ":"NO");
			for (int i=s[0]-'0'+1;i<=9;i++) if (a[i]>=2) printf("%d%d ",i,i);
			printf("\n");
		} else if (s.length() == 3){
			bool yes=false;
			for (int i=s[0]-'0'+1;i<=9;i++) if (a[i]>=3){yes=true;break;}
			printf(yes?"YES ":"NO");
			for (int i=s[0]-'0'+1;i<=9;i++) if (a[i]>=3) printf("%d%d%d ",i,i,i);
			printf("\n");
		} else if (s.length() == 4){
			bool yes=false;
			for (int i=s[0]-'0'+1;i<=9;i++) if (a[i]>=4){yes=true;break;}
			printf(yes?"YES ":"NO");
			for (int i=s[0]-'0'+1;i<=9;i++) if (a[i]>=4) printf("%d%d%d%d ",i,i,i,i);
			printf("\n");
		} else if (s.length() == 5){
			bool yes=false;
			for (int i=s[0]-'0'+1;i<=5;i++)
				if (a[i] && a[i+1] && a[i+2] && a[i+3] && a[i+4]){yes=true;break;}
			printf(yes?"YES ":"NO");
			for (int i=s[0]-'0'+1;i<=5;i++)
				if (a[i] && a[i+1] && a[i+2] && a[i+3] && a[i+4])
					printf("%d%d%d%d%d ",i,i+1,i+2,i+3,i+4);
			printf("\n");
		}
	}
}