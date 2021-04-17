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
int OO=1e6;
const int N=152;
int dp[N][51][N];

int n,m,k;
int ten,five,one;

int Solve(int rem,int ten,int five,int sum){

	if(!rem)
		return 0;
	
	int &ret = dp[rem][ten][five];
	if(~ret)
		return ret;
	
	ret = OO;
	
	if(sum >= 8)
		ret = min(ret , 8+Solve(rem-1,ten,five,sum-8));
	if(five && sum >= 3)
		ret = min(ret , 4+Solve(rem-1,ten,five-1,sum-3));
	if(ten && sum >= 3)
		ret = min(ret , 4+Solve(rem-1,ten-1,five+1,sum-3));
	if(ten)
		ret = min(ret , 1+Solve(rem-1,ten-1,five,sum+2));
	if(five >= 2)
		ret = min(ret , 2+Solve(rem-1,ten,five-2,sum+2));
	
	
	
	return ret;
		
}




int main(){
	
	int T;
	scanf("%d",&T);
	while(T--){
		
		memset(dp,-1,sizeof dp);
		
		scanf("%d%d%d%d",&n,&one,&five,&ten);
		
		printf("%d\n",Solve(n,ten,five,one));
		
	}
	

 
}
 
 

