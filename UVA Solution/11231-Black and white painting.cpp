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
 
 
 

const int N=1e3 + 5,M= 1e6 + 5;


int n,m,k;
int l,r,mid;
int a,b,c;



int main(){
	
	while(scanf("%d%d%d",&n,&m,&k), (n || m || k)){
		if((n+m)&1) k ^= 1;
		
		int len = m - 7;
		ll ans = 0;
		for(int i=0;i<len;++i){
			int v = n - 7;
			ans += v/2;
			ans += ((v&1) && k);
			k ^= 1;
		}
		
		printf("%lld\n",ans);
	}
	
	
	
}
