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
 
 
 
ll MOD = 2000000011;
ll OO=1e15;
const int N=2e5 + 5,M=1e7 + 5;

 
ll n,m,k,T;


ll Power(ll n,ll m,ll p){
	if(m < 0)
		return 1;
	
	n = n%p;
	ll ans = 1;
	while(m){
		if(m&1)
			ans = (n*ans)%p;
		
		n = (n*n)%p;
		m >>= 1;
	}
	
	return ans;
}



int main(){
	IO
	
	cin>>T;
	for(int i=1;i<=T;++i){
		cin>>n;
		cout<<"Case #"<<i<<": "<<Power(n,n-2,MOD)<<endl;
	}
	
	
	
}


