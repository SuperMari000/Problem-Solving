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
const int N=2e2 + 5,M=1e4 + 100;
int par[N];
int sz[N];

int n,m,k,T;
int a,b,c;
vector<pair<double,pair<int,int>>> adj;
vector<pair<int,int>> vec;
int st,en;


struct DSU{
	int comp;
	void init(int n){
		comp = n;
		iota(par,par+n,0);
		fill(sz,sz+n,1);
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
		--comp;
		
		return true;
	}
	
	bool IsCon(int a,int b){
		return find(a) == find(b);
	}
	
	double Solve(){
		
		for(auto &p:adj){
			join(p.second.first,p.second.second);
			
			if(IsCon(st,en))
				return p.first;
		}
		
		return 0;
	}
	
} DS;

void Read(int m){
	vec.clear();
	
	int a,b;
	while(m--){
		cin>>a>>b;
		vec.push_back(make_pair(a,b));
	}
	st = 0,en = 1;
}

void Gun(){
	adj.clear();
	int sz = SZ(vec);
	
	for(int i=0;i<sz;++i){
		for(int j=i+1;j<sz;++j){
			double dx = vec[i].first - vec[j].first;
			double dy = vec[i].second - vec[j].second;
			
			double val = hypot(dx,dy);
			adj.push_back(make_pair(val,make_pair(i,j)));
		}
	}
	
	sort(adj.begin(),adj.end());
}



int main(){
	

	int ID = 1;
	while(scanf("%d",&n) && n){
		
		Read(n);
		Gun();
		
		DS.init(n);
		printf("Scenario #%d\n",ID++);
		printf("Frog Distance = %0.3f\n\n",DS.Solve());
	}
	
		
	return 0;
}
 
