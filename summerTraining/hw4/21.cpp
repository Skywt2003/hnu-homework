// 题目描述也太恶心人了。

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

int t;

int get_points(char ch){
	if (ch=='r') return 1; else
	if (ch=='y') return 2; else
	if (ch=='g') return 3; else
	if (ch=='c') return 4; else 
	if (ch=='b') return 5; else
	if (ch=='p') return 6; else
	if (ch=='B') return 7; else
	cout<<"No such ball: "<<ch<<endl;
	return 0;
}

bool have_extra(string s, char ch){
	for (int i=0;i<(int)s.length();i++) if (s[i]!=ch) return true;
	return false;
}

bool have(string s, char ch){
	for (int i=0;i<(int)s.length();i++) if (s[i]==ch) return true;
	return false;
}

int count(string s, char ch){
	int ret=0;
	for (int i=0;i<(int)s.length();i++) ret+=s[i]==ch;
	return ret;
}

bool is_digit(char ch){
	return '0'<=ch && ch<='9';
}

string to_plain_string(string s){ // 将诸如 r4 转为 rrrr
	string ret="";
	for (int i=0;i<(int)s.length();i++) if (!is_digit(s[i])){
		if (s[i]==' ') continue;
		ret+=s[i];
		if (i+1<(int)s.length() && is_digit(s[i+1])){
			int redo = ((i+2<(int)s.length() && is_digit(s[i+2])) ? ((s[i+1]-'0')*10+(s[i+2]-'0')) : (s[i+1]-'0')) -1;
			for (int j=1;j<=redo;j++) ret+=s[i];
		}
	}
	return ret;
}

#define player (hitting?B:A)
#define aplayer (hitting?A:B)

char fix_color[7] = {'-', 'y', 'g', 'c', 'b', 'p', 'B'};

signed main(){
	cin>>t;
	int a100 = 0, b100 = 0;
	while (t--){
		bool hitting = false; // the one hitting. false: A; true: B;
		char should_hit = 'r'; // 'x' means any color
		int A = 0, B = 0, now_score = 0;
		int left_red_ball = 15;
		int now_color_ball = 0;
		for (;;){
			string s1,s2; cin>>s1;
			if (s1=="-1") break;
			getline(cin,s2);
			s1 = to_plain_string(s1);
			s2 = to_plain_string(s2);

			if (should_hit == 'x') should_hit=s1[0];
			if (s1=="NULL" || have_extra(s1,should_hit) || have_extra(s2,should_hit)){ // 犯规
				// printf("> Against the law\n");
				int max_point = ((s1=="NULL")?4:max(get_points(should_hit),4));
				if (s1!="NULL") for (int i=0;i<(int)s1.length();i++) max_point=max(max_point,get_points(s1[i]));
				for (int i=0;i<(int)s2.length();i++) max_point=max(max_point,get_points(s2[i]));
				aplayer += max_point;
				// printf("> anone + %d\n",max_point);
				left_red_ball -= count(s2,'r');

				if (now_score >= 100) (hitting?b100:a100)++; now_score=0;
				if (left_red_ball) should_hit = 'r'; else { // 不小心打进红球，提前开启 fix color 阶段
					if (!now_color_ball) now_color_ball++;
					should_hit = fix_color[now_color_ball];
				}
				hitting = 1-hitting;
			} else if (!have(s1,should_hit) || !have(s2,should_hit)){ // 未打进不得分
				// printf("> No hitting into\n");
				if (now_score >= 100) (hitting?b100:a100)++; now_score=0;
				if (left_red_ball) should_hit = 'r'; else {
					if (!now_color_ball) now_color_ball++;
					should_hit = fix_color[now_color_ball];
				}
				hitting = 1-hitting;
			} else if (should_hit == 'r'){ // 打进红球
				// printf("> Red into\n");
				left_red_ball -= s2.length();
				player += s2.length(); now_score += s2.length();
				// printf("> one + %d\n",(int)s2.length());
				should_hit = 'x';
			} else { // 打进颜色球
				// printf("> Color into into\n");
				player += get_points(should_hit); now_score += get_points(should_hit);
				// printf("> one + %d\n",get_points(should_hit));
				if (left_red_ball == 0){ // 已经开始打固定颜色球
					now_color_ball++;
					should_hit = fix_color[now_color_ball];
				} else { // 继续打红球
					should_hit = 'r';
				}
			}
		}
		if (now_score >= 100) (hitting?b100:a100)++; now_score=0;
		cout<<A<<":"<<B<<endl;
	}
	cout<<a100<<":"<<b100<<endl;
	return 0;
}