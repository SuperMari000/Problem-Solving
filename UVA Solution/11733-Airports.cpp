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
const int N=1e4 + 5,M=1e4 + 100;
int par[N],sz[N];

int n,m,k,T;
int a,b,c;
vector<pair<int,pair<int,int>>> adj;


struct DSU{
	
	int comp;
	ll SU;
	
	void init(int n){
		comp = n;
		SU = 0;
		iota(par,par+n,0);
		fill(sz,sz+n,1);
	}
	
	int find(int u){
		if(u == par[u]) return u;
		return par[u] = find(par[u]);
	}
	
	bool join(int a,int b,int &val){
		a = find(a);
		b = find(b);
		if(a == b) return false;
		
		if(sz[a] < sz[b]) swap(a,b);
		
		par[b] = a;
		sz[a] += sz[b];
		--comp;
		SU += val;
		return true;
	}
	

	void Solve(){
		for(auto &p:adj){
			if(p.first < k)
				join(p.second.first,p.second.second,p.first);
		}
		ll ans = 1ll*comp*k + SU;
		printf("%lld %d\n",ans,comp);
	}
	
} DS;

void Read(){
	adj.clear();
	scanf("%d%d%d",&n,&m,&k);
	int a,b,c;
	while(m--){
		scanf("%d%d%d",&a,&b,&c);
		--a,--b;
		adj.push_back(make_pair(c,make_pair(a,b)));
	}
	
	sort(adj.begin(),adj.end());
}



int main(){
	

	scanf("%d",&T);
	int ID = 1;
	while(T--){
		Read();
		
		DS.init(n);
		
		printf("Case #%d: ",ID++);
		DS.Solve();

	}
	

	return 0;
}
 
