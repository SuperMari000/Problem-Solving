//       Author: Mostafa Mounir Shehab
 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


ll n,m,T;

ll Power(ll n,ll m,ll p){
	n %= p;
	ll cnt = 1;
	while(m){
		if(m&1)
			cnt = cnt * n % p;
		n = n*n%p;
		m >>= 1;
	}
	return cnt;
}


int main(){

	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		printf("%lld\n",Power(n,m,10));
	}
	
}
