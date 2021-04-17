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
const int N=1e2 + 3;
int dp[N][N];
ll OO=1e12; 
 
ll n,m,k,idx;
string str,s;


int Solve(int x,int y){
	
	if(x == SZ(str) || y == SZ(s))
		return 0;
		
	int &ret=dp[x][y];
	if(~ret)
		return ret;
		
	if(str[x] == s[y])
		return ret = 1+Solve(x+1,y+1);
	
	ret = max(ret,Solve(x,y+1));
	ret = max(ret,Solve(x+1,y));
	
	return ret ;
		
	
}



 
 
int main(){


	while(getline(cin,str) && str.front() != '#'){
		getline(cin,s);
		
		memset(dp, -1 ,sizeof dp);
		
		cout<<"Case #"<<++idx<<": you can visit at most "<<Solve(0,0)<<" cities."<<endl;
		
	}

	

	


}
