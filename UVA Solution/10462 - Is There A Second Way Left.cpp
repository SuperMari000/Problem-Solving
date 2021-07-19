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
const int N=1e2 + 5,M=1e7 + 1;

int n,m,k,T;
int a,b,c;
vector<pair<int,pair<int,int>>> adj,rem;


struct DSU{
	
	int comp;
	ll SU;
	int par[N],sz[N];
	
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
	
	bool join(int a,int b,int val){
		a = find(a);
		b = find(b);
		if(a == b) return false;
		
		if(sz[a] < sz[b]) swap(a,b);
		
		par[b] = a;
		sz[a] += sz[b];
		SU += val;
		comp--;
		
		return true;
	}

	
} DS;

void Read(int m){
	adj.clear();
	rem.clear();
	
	int a,b,c;
	while(m--){
		cin>>a>>b>>c;
		--a,--b;
		adj.push_back(make_pair(c,make_pair(a,b)));
	}
	
	sort(adj.begin(),adj.end());	
}

void Solve(){

	for(auto &p:adj){
		
		if(!DS.join(p.second.first,p.second.second,p.first))
			rem.push_back(p);
	}
	
	if(DS.comp != 1){
		cout<<"No way\n";
		return;
	}
	
	ll ans = DS.SU;
	ll MN = OO;
	
	for(auto &p:rem){
		DS.init(n);
		DS.join(p.second.first,p.second.second,p.first);
		
		for(auto &pp:adj)
			DS.join(pp.second.first,pp.second.second,pp.first);
		
		if(DS.comp == 1)
			MN = min(MN,DS.SU);
	}
	
	if(MN == OO)
		cout<<"No second way\n";
	else
		cout<<MN<<endl;
	
}
 
int main(){
	
	IO

	cin>>T;
	for(int i=1;i<=T;++i){
		cin>>n>>m;
		DS.init(n);
		
		Read(m);
		
		cout<<"Case #"<<i<<" : ";
		Solve();
	}
	
		
	return 0;
}
 

