//       Author: Mostafa Mounir Shehab
 
#include <bits/stdc++.h>
using namespace std;
 
#define PI  acos(-1)
#define EPS (1e-10)
#define endl "\n"
#define SZ(v) (int)(v.size())
#define IO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL);
typedef long long ll;
typedef long double ld;
 
 
 
ll MOD=10000007;
int OO=1e9 + 1;
const int N=1e6 + 5,M= 1e6 + 5;


int n,m,k,SU,idx,len,MN,MX,T,lg;
int l,r,mid;
int a,b,c;


ll Power(ll n,ll p,ll mod = MOD){
	n %= mod;
	ll ans = 1;
	while(p){
		if(p&1)
			ans = ans*n%mod;
		
		n = n*n%mod;
		p >>= 1;
	}
	return ans;
}

int main(){
	
	ll n,k;
	while(scanf("%lld%lld",&n,&k) && (n || k)){
		ll ans = Power(n,n);
		ans += Power(n,k);
		ans += 2*Power(n-1,n-1);
		ans += 2*Power(n-1,k);
		ans %= MOD;
		printf("%lld\n",ans);
	}
	
	return 0;
}
