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
ll OO=1e10;
const int N=5e2 + 5;
char arr[N];
ll dp[N];

int n,m,k;


ll Solve(int idx){
	
	if(!arr[idx])
		return 0;
	
	ll &ret = dp[idx];
	if(~ret)
		return ret;
	ll val=0;
	ret=0;
	
	while(arr[idx] && val*10+(arr[idx]-'0') <= INT_MAX){
	
		val =val*10 + (arr[idx]-'0');
		ret=max(ret,val+Solve(idx+1));
		++idx;
	}
	
	return ret;

}


int main(){

	
	int T;
	scanf("%d",&T);
	while(T--){
		
		scanf("%s",arr);
		memset(dp,-1,sizeof dp);
		printf("%lld\n",Solve(0));
		
	}
	
	return 0;
}


