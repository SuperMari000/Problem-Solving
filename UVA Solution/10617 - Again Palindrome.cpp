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
const int N=60 + 2 ,M=6;
ll dp[N][N];


ll n,m,k,T;
string str;


ll Solve(int l,int r){
	
	if(l >= r)
		return l == r;
	
	
	ll &ret = dp[l][r];
	if(~ret)
		return ret;

	
	if(str[l] == str[r])
		return ret = 1 +  Solve(l+1,r) + Solve(l,r-1);
	
	
	return ret = Solve(l+1,r) + Solve(l,r-1) - Solve(l+1,r-1);
	
}



int main(){


	cin>>T;
	while(T--){
		memset(dp,-1,sizeof dp);
		cin>>str;
		cout<<Solve(0,SZ(str)-1)<<endl;
	}

	
	
		
}
 
 

