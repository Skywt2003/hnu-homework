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

int n;

const int maxn=256;

char left_son[maxn],right_son[maxn];

char front[maxn],mid[maxn];

char build_tree(int l1,int r1,int l2,int r2){
	// printf("Doing %d %d, %d %d\n",l1,r1,l2,r2);
	if (l1==r1) return front[l1];
	int root_pos=-1;
	for (int i=l2;i<=r2;i++) if (mid[i]==front[l1]) {root_pos=i;break;}
	// if (root_pos==-1) {printf("weird\n");return '-';}
	if (root_pos!=l2) left_son[front[l1]] = build_tree(l1+1,l1+(root_pos-l2),l2,root_pos-1);
	if (root_pos!=r2) right_son[front[l1]] = build_tree(l1+(root_pos-l2)+1,r1,root_pos+1,r2);
	return front[l1];
}

void print_end(char x){
	if (left_son[x]) print_end(left_son[x]);
	if (right_son[x]) print_end(right_son[x]);
	putchar(x);
}

signed main(){
	n=read();
	while (n){
		scanf("%s",front+1);
		scanf("%s",mid+1);
		memset(left_son,0,sizeof(left_son));
		memset(right_son,0,sizeof(right_son));
		build_tree(1,n,1,n);
		print_end(front[1]); putchar('\n');
		n=read();
	}
}