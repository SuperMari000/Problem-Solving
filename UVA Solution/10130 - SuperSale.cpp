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
const int N=1e3 + 3 , M=2e2 + 5;
int arr[N];
int pre[N];
ll dp[N][M];
ll OO=1e12; 
 
ll n,m,k,cnt,idx;
int a,b;



ll Solve(int idx,int rem){

	if(idx == n)
		return 0;
	
	ll &ret = dp[idx][rem];
	
	if(~ret)
		return ret;
	
	ll x = Solve(idx+1,rem);
	
	ll y = (rem >= arr[idx]) ? pre[idx] + Solve(idx+1,rem-arr[idx]) : 0;
	
	return ret = max(x,y);
	
	
}




 
int main(){

	int T=D();
	while(T--){
		memset(dp,-1,sizeof dp);
		cnt=0;
		
		scanf("%lld",&n);
		for(int i=0;i<n;++i)
			scanf("%d%d",pre+i,arr+i);


		scanf("%lld",&m);
		while(m--){
			scanf("%lld",&idx);
			cnt+=Solve(0,idx);
		}
		
		printf("%lld\n",cnt);
		
	}
 
	
	

}




