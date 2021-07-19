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
int OO=1e9 + 7;
const int N=1e2 + 10,M = 1e5 + 5;
int par[N],sz[N];

int n,m,k,T,len,val;
int a,b,c;
int l,r,mid;
vector<pair<int,pair<int,int>>> vec;
vector<int> rem;

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
	
	bool join(int a,int b,int val){
		a = find(a);
		b = find(b);
		if(a == b) return false;
		
		if(sz[a] < sz[b]) 
			swap(a,b);
		par[b] = a;
		sz[a] += sz[b];
		SU += val;
		--comp;
		return true;
	}
	
	ll MST(){
		
		for(int i=0;i<SZ(vec);++i){
			auto p = vec[i];
			if(join(p.second.first,p.second.second,p.first))
				rem.push_back(i);
		}
		
		return SU;
	}
	
	
} DS;


void Read(int n){
	vec.clear();
	rem.clear();
	int a,b,c;
	while(n--){
		cin>>a>>b>>c;
		--a,--b;
		vec.push_back(make_pair(c,make_pair(a,b)));
	}
	
	sort(vec.begin(),vec.end());
}

void Solve(){
	DS.init(n);
	ll a = DS.MST();
	ll b = 1e12;
	
	for(int i:rem){
		DS.init(n);
		for(int j=0;j<SZ(vec);++j){
			if(i == j) continue;
			auto p = vec[j];
			DS.join(p.second.first,p.second.second,p.first);
		}
		
		if(DS.comp == 1)
			b = min(b,DS.SU);
	}
	
	cout<<a<<" "<<b<<"\n";
}


int main(){
	
	IO
	
	cin>>T;
	while(T--){
		cin>>n>>m;
		Read(m);
		Solve();
	}

	
	return 0;
}
 
