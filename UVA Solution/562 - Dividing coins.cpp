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
const int N=1e2 + 3 , M=5e4 + 5;
int arr[N];
int dp[N][M];
ll OO=1e6; 
 
int n,m,k,cnt,idx;


int Solve(int idx,int rem){
	
	if(idx == n)
		return rem < 0 ? OO : rem;

	int &ret = dp[idx][rem];
	
	if(~ret)
		return ret;
	
	
	return  ret = min(Solve(idx+1,rem),Solve(idx+1,rem-arr[idx]));
	
	
}




 
int main(){

	int T=D();
	while(T--){
		cnt=0;
		memset(dp,-1,sizeof dp);
		
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",arr+i),cnt+=arr[i];

		idx = ((cnt+1)>>1) - Solve(0,((cnt+1)>>1));
		
		printf("%d\n",abs(cnt - (idx<<1)));
		
	}
 
	
	

}




