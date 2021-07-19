//       Author: Mostafa Mounir Shehab
 
#include <bits/stdc++.h>
using namespace std;
 
#define PI  acos(-1)
#define EPS (1e-10)
#define endl "\n"
#define SZ(v) (int)(v.size())
#define IO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL);
typedef long long ll;
typedef long double ld;
 

 
ll MOD=1e9 + 7;
ll OO=1e15;
const int N=1e2 + 5;
ll dp[N][N][3];


int n,m,k;


ll Solve(int idx,int rem,bool last){
	
	if(idx >= n)
		return rem == m;
	
	ll &ret = dp[idx][rem][last];
	if(~ret)
		return ret;
	
	ret = Solve(idx+1,rem+ (!last),0);
	ret += Solve(idx+1,rem,1);
	
	return ret;
}



int main(){
	
	while(scanf("%d%d",&n,&m) && n>-1 && m>-1){
		memset(dp,-1,sizeof dp);
		
		printf("%lld\n",Solve(0,0,0));
	}	

	
}

