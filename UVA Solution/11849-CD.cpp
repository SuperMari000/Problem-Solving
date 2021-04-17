//        Mostafa Mounir Shehab
 
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
 
ll n,m,k;




int main(){

	while(scanf("%d%d",&n,&m) && (n || m)){
		map<int,bool> mp;
		int val=0,cnt=0;
		for(int i=0;i<n;++i){
			scanf("%d",&val);
			mp[val]=true;
		}
		for(int i=0;i<m;++i){
			scanf("%d",&val);
			cnt+=(mp[val]);
			mp[val]=true;
		}
		
		printf("%d\n",cnt);
	}


	
}
 
 
 
 
 
 
 
 
 
 
