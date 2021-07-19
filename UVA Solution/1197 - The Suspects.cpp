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
 
 
 
ll MOD=1e9 + 7;
ll OO=1e15;
const int N=1e5 + 10,M=2*N;
int par[N],sz[N];


int n,m,k,T;
int a,b,c;


struct DSU{
	
	void init(int n,int m){
		iota(par,par+n+m,0);
		fill(sz,sz+n,1);
		fill(sz+n,sz+n+m,0);
	}
	
	int find(int u){
		if(u == par[u]) return u;
		return par[u] = find(par[u]);
	}
	
	bool join(int a,int b){
		a = find(a);
		b = find(b);
		if(a == b) return false;
		
		if(sz[a] < sz[b]) swap(a,b);
		
		par[b] = a;
		sz[a] += sz[b];
		return true;
	}
	
	int GetSize(int u){
		u = find(u);
		return sz[u];
	}
	
} DS;




int main(){
	
	
	while(scanf("%d%d",&n,&m) && (n || m)){
		DS.init(n,m);
		for(int i=0;i<m;++i){
			int len,a;
			scanf("%d",&len);
			while(len--){
				scanf("%d",&a);
				DS.join(a,n+i);
			}
		}
		
		printf("%d\n",DS.GetSize(0));
	}
	
	return 0;
}
 
