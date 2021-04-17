//       Author: Mostafa Mounir Shehab
 
#include <bits/stdc++.h>
using namespace std;
 
#define PI  3.14159265  // PI = acos(-1)
#define EPS (1e-10)
#define endl "\n"
#define SZ(v) (int)(v.size())
typedef long long ll;
typedef long double ld;
//template <class Type>

inline int D(){
	int t;
	scanf("%d",&t);
	return t;
}
inline ll llD(){
	ll t;
	scanf("%lld",&t);
	return t;
}
 
 
ll MOD=1e9 + 7;
ll OO=1e13;  
const int N=8e3 + 5,M=6;
ll dp[N][M];

vector<int> vec;

ll n,m,k;


ll Solve(int val,int idx){
	
	if(val <= 0)
		return val == 0;
	
	ll &ret=dp[val][idx];
	
	if(~ret)
		return ret;
		
	ret = 0;
	while(idx < SZ(vec)){
		ret+= Solve(val-vec[idx],idx);
		++idx;
	}

		
	return  ret;

}
 
 
int main(){
	
	vec={1,5,10,25,50};
	
	memset(dp,-1,sizeof dp);
	Solve(N-5,0);
		
	while(scanf("%d",&n) != EOF)
		
		printf("%lld\n",dp[n][0]);
		
	
		

	
	
		
}
 
 

