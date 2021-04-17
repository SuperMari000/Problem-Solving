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
const int N=1e3+ 5;
int arr[N];


ll n,m,k;


ll power(ll n,ll m,ll k){
	ll cnt=1;
	n%=k;
	while(m){
		if(m&1)
			cnt=(cnt*n)%k;
		
		n=(n*n)%k;
		m>>=1;
	}
	return cnt;
}




int main(){
	

	while(scanf("%lld%lld%lld",&n,&m,&k) != EOF)
		printf("%lld\n",power(n,m,k));
		

	

 
}
 
 
 
 
 
 
 
