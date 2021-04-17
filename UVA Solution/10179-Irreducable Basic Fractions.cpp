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
const int N=1e4 + 1;

ll n,m,k;


ll PHi(ll n){
	ll cnt=n;
	for(int i=2;i<=n/i;++i){
		
		cnt-=(n%i == 0) ? cnt/i : 0;
		
		while(n%i == 0)
			n/=i;
		
	}
	
	if(n != 1)
		cnt-=(cnt/n);
	
	return cnt;
	
}



int main(){
	
	
	while(scanf("%d",&n) && n){
		
		printf("%lld\n",PHi(n));
		
	}

		
	
 
}
 
 
 
 
