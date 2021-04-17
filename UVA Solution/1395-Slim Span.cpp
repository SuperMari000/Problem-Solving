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
const int N=1e2 + 5,M=1e4 + 100;

int n,m,k,T;
int a,b,c;
vector<pair<int,pair<int,int>>> adj;


struct DSU{
	
	int comp;
	int MN,MX;
	int par[N],sz[N];
	
	void init(int n){
		this->comp = n;
		this->MN = INT_MAX;
		this->MX = INT_MIN;
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
		MN = min(MN,val);
		MX = max(MX,val);
		comp--;
		
		return true;
	}

	
} DS;

void Read(int m){
	adj.clear();
	int a,b,c;
	while(m--){
		cin>>a>>b>>c;
		--a,--b;
		adj.push_back(make_pair(c,make_pair(a,b)));
	}
	
	sort(adj.begin(),adj.end());
}


int Solve(){
	
	int ans = M;
	for(int i=0;i<SZ(adj);++i){
		DS.init(n);
		
		for(int j=i;j<SZ(adj);++j){
			auto p = adj[j];
			DS.join(p.second.first,p.second.second,p.first);
		}
		
		if(DS.comp == 1)
			ans = min(ans,DS.MX-DS.MN);
		
	}
	
	return ans == M ? -1 : ans;
}


int main(){
	
	IO
	
	while(cin>>n>>m && (n || m)){
		
		Read(m);
		
		cout<<Solve()<<"\n";
	}
	
		
	return 0;
}
 

