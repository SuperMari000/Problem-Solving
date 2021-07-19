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
const int N=1e6+ 1;

int n,m,k;
int a,b;


vector<int> adj[N];

int main(){


	while(scanf("%d%d",&n,&m) != EOF){
		
		
		for(int i=1;i<=n;++i)
			adj[D()].push_back(i);
		
		while(m--){
			scanf("%d%d",&a,&b);
			
			if(SZ(adj[b]) >= a)
				printf("%d\n",adj[b][a-1]);
			else
				puts("0");
		}
		
		for(int i=1;i<N;++i)
			adj[i].clear();
	}
	
	
	
	

 
}
 
 
 
 
 
 
 
