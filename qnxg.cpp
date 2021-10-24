#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1000005; // Actually maxm

int n,m,cnt=0,now_cnt=0; // cnt：总计数，累计所有出现过的人  now_cnt：当前计数，累计当前的人
string name[maxn];
int rat[maxn],id[maxn];

int lst[maxn]; // 上次打卡时间
int rcd[maxn],prt=1; // rcd[i]: 第 i 条指令指定的对象，为 -1 则表示这条是查询指令

map<int,int> lnk; // 学号 -> 存储的编号

signed main(){
	n=read(),m=read();
	while (m--){
		char opt=getchar(); while (opt!='I' && opt!='O' && opt!='L') opt=getchar();
		if (opt=='I'){ // IN
			int x=read();
			string s; cin>>s;
			if (lnk[x]){
				int now=lnk[x];
				rat[now]++; name[now]=s;
				rcd[++rcd[0]]=now; lst[now]=rcd[0];
			} else {
				int now=lnk[x]=++cnt; id[now]=x; now_cnt++;
				rat[now]++; name[now]=s;
				rcd[++rcd[0]]=now; lst[now]=rcd[0];
				if (now_cnt>n){
					// 去寻找最前面的 prt == lst[rcd[prt]] 即该记录之后没有更新过的同学，说明这是最长时间未更新的同学
					while (rcd[prt]==-1 || lst[rcd[prt]]==0 || prt < lst[rcd[prt]]) prt++;
					rat[rcd[prt]]=0; lst[rcd[prt]]=0; lnk[rcd[prt]]=0;
					now_cnt--;
				}
			}
		} else if (opt=='O'){ // OUT
			int x=read();
			int now=lnk[x];
			rat[now]=0; lst[now]=0; now_cnt--;
			lnk[x]=0;
		} else if (opt=='L'){ // LOOK
			int x=read();
			if (lnk[x] && lst[lnk[x]]) cout<<name[lnk[x]]<<endl;
			else printf("ERROR\n");
		}
	}
	for (int i=1;i<=rcd[0];i++) if (lst[rcd[i]] == i) cout<<id[rcd[i]]<<","<<name[rcd[i]]<<" ";
	printf("\n");
	return 0;
}