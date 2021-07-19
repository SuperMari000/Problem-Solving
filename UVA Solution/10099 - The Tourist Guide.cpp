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
	
	int comp,st,en,val,MX;
	int par[N],sz[N];
	
	void init(int n){
		MX = val + 1;
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
		
		return true;
	}
	
	
	bool IsCon(int a,int b){
		return find(a) == find(b);
	}
	int Solve(){
		for(auto &p:adj){
			join(p.second.first,p.second.second);
			MX = min(MX,p.first);
			
			if(this->IsCon(st,en))
				break;
		}
		--MX;
		
		return val/MX + (val%MX != 0);
	}
	
} DS;

void Read(int m){
	adj.clear();
	
	int a,b,c;
	while(m--){
		scanf("%d%d%d",&a,&b,&c);
		adj.push_back(make_pair(c,make_pair(a,b)));
	}
	
	sort(adj.rbegin(),adj.rend());

	scanf("%d%d%d",&DS.st,&DS.en,&DS.val);
}



int main(){
	

	int ID = 1;
	while(scanf("%d%d",&n,&m) && (n || m)){
		
		Read(m);
		
		DS.init(n+1);
		
		printf("Scenario #%d\n",ID++);
		printf("Minimum Number of Trips = %d\n\n",DS.Solve());

	}
	
		
	return 0;
}
 
