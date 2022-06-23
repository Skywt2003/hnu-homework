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

const int maxn=2005;

int n;
char a[maxn][maxn];
int down[maxn][maxn],right[maxn][maxn];

void build_sum(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			down[i][j] = down[i-1][j] + down[i][j-1] - down[i-1][j-1] + (a[i][j] == a[i+1][j]);
			right[i][j] = right[i-1][j] + right[i][j-1] - right[i-1][j-1] + (a[i][j] == a[i][j+1]);
		}
}

int get_down_count(int x1,int y1,int x2,int y2){
	// printf("down: %d %d %d %d %d\n",x1,y1,x2,y2,down[x2][y2] - down[x1-1][y2] - down[x2][y2-1] + down[x2-1][y2-1]);
	return down[x2][y2] - down[x1-1][y2] - down[x2][y1-1] + down[x1-1][y1-1];
}

int get_right_count(int x1,int y1,int x2,int y2){
	// printf("right: %d %d %d %d %d\n",x1,y1,x2,y2,right[x2][y2] - right[x1-1][y2] - right[x2][y2-1] + right[x2-1][y2-1]);
	return right[x2][y2] - right[x1-1][y2] - right[x2][y1-1] + right[x1-1][y1-1];
}

bool check(int x,int y,int k){
	if (k==1) return true;
	return (get_down_count(x,y,x+k-2,y+k-1)==0 && get_right_count(x,y,x+k-1,y+k-2)==0);
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) scanf("%s",a[i]+1);
	build_sum();

	int max_size=1,max_num=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) if (a[i][j]=='1'){
			int l=max_size,r=std::min(n-i+1,n-j+1),now_max=-1;
			while (l<=r){
				int mid=((r-l)>>1)+l;
				if (check(i,j,mid)) now_max=mid, l=mid+1;
				else r=mid-1;
			}
			if (now_max > max_size) max_size=now_max, max_num=1;
			else if (now_max==max_size) max_num++;
			// printf("(%d,%d): %d\n",i,j,now_max);
		}

	printf("%d %d\n",max_size,max_num);
	return 0;
}