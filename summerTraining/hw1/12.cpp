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

const int maxn=505,maxm=1e5+5;

int t,m;
int ram[maxm];
int tmp[maxm];

struct block{
	bool removed;
	int start, end, len;
};

int n=0;
block a[maxn];

signed main(){
	t=read(), m=read();
	while (t--){
		string s; cin>>s;
		if (s=="alloc"){
			int len=read();
			int now_cnt=0,now_start=-1;
			for (int i=1;i<=m;i++){
				if (ram[i]) now_cnt=0; else now_cnt++;
				if (now_cnt==len){
					now_start=i-len+1;
					break;
				}
			}
			if (now_start == -1){
				printf("NULL\n");
				continue;
			}
			n++;
			a[n].start=now_start;
			a[n].end=now_start+len-1;
			a[n].len=len; a[n].removed=false;
			for (int i=a[n].start;i<=a[n].end;i++) ram[i]=n;
			printf("%d\n",n);
		} else if (s=="erase"){
			int x=read();
			if (x<=0 || x>n || a[x].removed){
				printf("ILLEGAL_ERASE_ARGUMENT\n");
				continue;
			}
			for (int i=a[x].start;i<=a[x].end;i++) ram[i]=0;
			a[x].removed=true;
		} else if (s=="defragment"){
			for (int i=1;i<=m;i++) tmp[i]=ram[i],ram[i]=0;
			int last=0;
			for (int i=1;i<=m;i++) if (tmp[i]){
				int now=tmp[i];
				int next_i=a[now].end;
				a[now].start=last+1;
				a[now].end=last+a[now].len;
				for (int j=a[now].start;j<=a[now].end;j++) ram[j]=now;
				last=a[now].end; i=next_i;
			}
		}
	}
	return 0;
}