#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<map>

std::stack<char> s;

int failed(){
	printf("no\n");
	return 0;
}

signed main(){
	char ch=getchar();
	while (ch!=10 && ch!=13 && ch!=-1){
		if (ch==')'){
			if (s.empty() || s.top() != '(')  return failed(); else s.pop(); 
		} else if (ch==']'){
			if (s.empty() || s.top() != '[')  return failed(); else s.pop(); 
		} else if (ch=='}'){
			if (s.empty() || s.top() != '{')  return failed(); else s.pop(); 
		} else if (ch=='>'){
			if (s.empty() || s.top() != '<')  return failed(); else s.pop(); 
		} else s.push(ch);
		ch=getchar();
	}
	printf(s.empty()?"yes\n":"no\n");
	return 0;
}