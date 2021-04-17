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
ll l,r;


bool valid(ll n){
	
	for(int i=0;i*i <= n;++i){
		m=n-i*i;
		l=0,r=N;
		while(l<=r){
			
			if(l*l + r*r < m)
				++l;
			else if(l*l + r*r > m)
				--r;
			else
				return printf("%d %lld %lld\n",i,l,r);

		}
	
	}
	puts("-1");
	return 0;
}




int main(){
	

	int T=D();
	while(T--){
		scanf("%d",&n);
		
		valid(n);
	}
		

	

 
}
 
 
 
 
 
 
 
