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
const int N=1e4 + 3,M=1e2 + 3;
int arr[N];
int dp[N][M];
ll OO=1e12; 
 
ll n,m,k;


bool Solve(int idx,int mod){
		
	if(idx == n)
		return mod == 0;
	
	int &ret=dp[idx][mod];
	if(~ret)
		return ret;
	
	return ret = Solve(idx+1,(mod+arr[idx])%m) || Solve(idx+1,((mod-arr[idx])%m+m)%m);
		
	
}



 
 
int main(){
	int T=D();
	while(T--){
		memset(dp, -1 ,sizeof dp);
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i)
			scanf("%d",arr+i);
		
		puts(Solve(1,arr[0]%m) ? "Divisible" : "Not divisible");
		
	}

	

	


}
