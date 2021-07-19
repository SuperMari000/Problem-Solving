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
const int N=1e2 + 5;
int arr[N];
int OO=1e6; 

int n,m,k;



bool Solve(int idx,int sum){
	
	if(idx == n)
		return sum == m;
	
	
	return Solve(idx+1,sum) ||
		   Solve(idx+1,sum+arr[idx]);
 
	
} 
 
 

 
int main(){
	
	int T=D();
	while(T--){
		
		scanf("%d%d",&m,&n);
		for(int i=0;i<n;++i)
			scanf("%d",arr+i);
			
		puts(Solve(0,0) ? "YES" : "NO");
	}

 
		
	
}
 
 
