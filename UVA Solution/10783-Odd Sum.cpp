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
const int N=1e5+ 5;
int arr[N];


ll n,m,k,cnt;
ll l,r,mid;





int main(){
	
		
	int T=D();
	for(int i=1;i<=T;++i){
		scanf("%d%d",&l,&r);
		r+=(r&1);
		r>>=1; // Divide By 2
		l>>=1; // Divide By 2
		
		cnt=r*r - l*l;

		printf("Case %d: %lld\n",i,cnt);
		
	}
	

 
}
 
 
 
 
 
 
 
