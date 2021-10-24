#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int n,m;
double ans;

bool is_sp_au(int x){return ((3<=x && x<=5) || (9<=x && x<=11));}

signed main(){
	scanf("%d%d",&n,&m);
	if (m <= 180) ans=0.588*m;
	else if ((is_sp_au(n) && m<=350) || ((!is_sp_au(n)) && m<=450)) ans=0.588*180 + (0.588+0.05)*(m-180);
	else if (is_sp_au(n)) ans=0.588*180 + (0.588+0.05)*(350-180) + (0.588+0.3)*(m-350);
	else ans=0.588*180 + (0.588+0.05)*(450-180) + (0.588+0.3)*(m-450);
	cout<<ans<<endl;
	return 0;
}