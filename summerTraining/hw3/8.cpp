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

const int maxn=1005;

char s1[maxn],s2[maxn];
int len1,len2;
bool vis1[maxn],vis2[maxn];

signed main(){
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	len1=strlen(s1+1); len2=strlen(s2+1);
	bool can_get=true;
	for (int i=1;i<=len2;i++){
		for (int j=1;j<=len1;j++) if (s1[j]==s2[i] && !vis1[j]){
			vis1[j]=vis2[i]=true;
			break;
		}
		if (!vis2[i]) can_get=false;
	}
	if (can_get){
		int delta=0;
		for (int i=1;i<=len1;i++) delta+=1-vis1[i];
		printf("Yes %d\n",delta);
	} else {
		int left=0;
		for (int i=1;i<=len2;i++) left+=1-vis2[i];
		printf("No %d\n",left);
	}
	return 0;
}