#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
// #include<cmath>
#include<map>

using namespace std;

const int INF=0x3f3f3f3f;

struct stdpeople {
    char id [19];                  /* 身份证号码 */
    int social;                     /* 社保缴纳月数 */
    int area;                       /* 现有住房面积 */
    char date [11];              /* 申报日期 */
};

struct people {
    char id [19];                  /* 身份证号码 */
	string ids;
    int social;                     /* 社保缴纳月数 */
    int area;                       /* 现有住房面积 */
    char date [11];              /* 申报日期 */
	int equal_num;
	int have_house;
};

map<string, int> num;

stdpeople* getMess(int &n);

int m,T;

int get_y(char* s){
	return (s[6]-'0')*1000+(s[7]-'0')*100+(s[8]-'0')*10+(s[9]-'0');
}
int get_d(char* s){
	return (s[3]-'0')*10+(s[4]-'0');
}
int get_m(char* s){
	return (s[0]-'0')*10+(s[1]-'0');
}

bool earlier(people aa, people bb){
	int m1=get_m(aa.date),d1=get_d(aa.date),y1=get_y(aa.date);
	int m2=get_m(bb.date),d2=get_d(bb.date),y2=get_y(bb.date);
	if (y1 < y2) return true;
	if (y1 > y2) return false;
	if (m1 < m2) return true;
	if (m1 > m2) return false;
	if (d1 < d2) return true;
	if (d1 > d2) return false;
	return false;
}

bool later(people aa, people bb){
	int m1=get_m(aa.date),d1=get_d(aa.date),y1=get_y(aa.date);
	int m2=get_m(bb.date),d2=get_d(bb.date),y2=get_y(bb.date);
	if (y1 > y2) return true;
	if (y1 < y2) return false;
	if (m1 > m2) return true;
	if (m1 < m2) return false;
	if (d1 > d2) return true;
	if (d1 < d2) return false;
	return false;
}

bool cmp_for_sort(people aa, people bb){
	if (aa.area==0 && bb.area!=0) return true;
	if (aa.area!=0 && bb.area==0) return false;
	if (aa.area==0 && bb.area==0){
		if (aa.social > bb.social) return true;
		if (aa.social < bb.social) return false;
		if (earlier(aa,bb)) return true;
		if (later(aa,bb)) return false;
		// return -1; // absolutely equal
		return false;
	}
	if (aa.area!=0 && bb.area!=0){
		if (aa.area < bb.area) return true;
		if (aa.area > bb.area) return false;
		if (earlier(aa,bb)) return true;
		if (later(aa,bb)) return false;
		// return -1; // absolutely equal
		return false;
	}
	return false;
}
// 虽然这么些很 WET =_= 但是 int 函数传入 sort 会 Segment Fault……
int cmp(people aa, people bb){
	if (aa.area==0 && bb.area!=0) return true;
	if (aa.area!=0 && bb.area==0) return false;
	if (aa.area==0 && bb.area==0){
		if (aa.social > bb.social) return true;
		if (aa.social < bb.social) return false;
		if (earlier(aa,bb)) return true;
		if (later(aa,bb)) return false;
		return -1; // absolutely equal
	}
	if (aa.area!=0 && bb.area!=0){
		if (aa.area < bb.area) return true;
		if (aa.area > bb.area) return false;
		if (earlier(aa,bb)) return true;
		if (later(aa,bb)) return false;
		return -1; // absolutely equal
	}
	return false;
}

const int maxn=1e5+5;

people person[maxn];

int main(){
	stdpeople *datain;
    //people *person;          /* 指向所有报名人的基本资料首地址，通过调用函数 getMess 获取 */     
    int n;                            /* n 为报名人数，通过调用函数 getMess 获取 */
    datain=getMess(n);
	for (int i=0;i<n;i++){
		person[i].area=datain[i].area;
		for (int j=0;j<19;j++) person[i].id[j]=datain[i].id[j];
		person[i].social=datain[i].social;
		for (int j=0;j<11;j++) person[i].date[j]=datain[i].date[j];
	}

	for (int i=0;i<n;i++){
		person[i].ids="";
		for (int j=0;j<18;j++) person[i].ids+=person[i].id[j]; // 注意最后一位不用了！
		// cout<<"!! "<<person[i].ids<<endl;
		// printf("!!!%s\n",person[i].id);
		// for (int j=0;j<18;j++) putchar(person[i].id[j]); putchar('\n');
		if (person[i].area==0 && person[i].social <= 24) person[i].area = INF;
		// 没交满社保的强制排到最后
	}

	sort(person,person+n,cmp_for_sort);

	cin>>m>>T;

	int sent_house=0;
	for (int i=0;i<n;i++){
		int j=i;
		while (j+1<n && cmp(person[j+1],person[i]) == -1) j++;

		for (int k=i;k<=j;k++) num[person[k].ids]=k;
		for (int k=i;k<=j;k++) person[k].equal_num = j-i+1;
		if (sent_house >= m){
			for (int k=i;k<=j;k++) person[k].have_house=0;
		} else if (sent_house + (j-i+1) <= m){
			for (int k=i;k<=j;k++) person[k].have_house=-1;
			sent_house+=j-i+1;
		} else {
			int left_house = m-sent_house;
			for (int k=i;k<=j;k++) person[k].have_house=left_house;
			sent_house=m;
		}
		// have_house =0 无房，=-1 肯定有，=k 则可能有
		i=j;
	}

	// for (int i=0;i<n;i++){
	// 	cout<<person[i].ids<<" "<<person[i].equal_num<<endl;
	// }

	while (T--){
		string s; cin>>s;
		int sid=num[s];
		if (person[sid].have_house == 0 || person[sid].area==INF){
			printf("Sorry\n");
		} else if (person[sid].have_house == -1){
			if (person[sid].equal_num == 1){
				printf("%d\n",sid+1); // 存储从 0 开始，要 +1！！！
			} else {
				int left=sid,right=sid;
				while (left-1>=0 && cmp(person[left-1],person[sid])==-1) left--;
				while (right+1<n && cmp(person[right+1],person[sid])==-1) right++;
				printf("%d %d\n",left+1,right+1);
			}
		} else {
			printf("%d/%d\n",person[sid].have_house,person[sid].equal_num);
		}
	}
    return 0;
}

stdpeople* getMess (int &n){            /* 将文件数据读入内存 */
    FILE *fp;
    fp=fopen("house.bin","rb");
    fseek(fp,-1*(long)sizeof(int), 2);
    fread(&n, sizeof(int), 1, fp);
    rewind(fp);
    stdpeople *tmp=new stdpeople[n];
    fread(tmp, sizeof(stdpeople), n, fp);
    fclose(fp);
    return tmp;
}