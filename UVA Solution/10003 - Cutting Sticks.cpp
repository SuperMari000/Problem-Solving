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
 
 
ll OO=1e10;
const int N=60 + 5;
int arr[N];
int dp[N][N];


int n,m,k,len;



int Solve(int l,int r){
	
	if(l+1 == r)
		return 0;
	
	int &ret = dp[l][r];
	if(~ret)
		return ret;
		
	ret=OO;
	for(int i=l+1;i<r;++i)
		ret=min(ret,arr[r]-arr[l]+Solve(i,r)+Solve(l,i));
		
	return ret;
}




int main(){
	
	while(scanf("%d",&len) && len){
		memset(dp,-1,sizeof dp);
		
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",arr+i);
		
		arr[++n]=len;
		printf("The minimum cutting is %d.\n",Solve(0,n));
	}
	

}



