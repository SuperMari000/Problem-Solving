//       Author: Mostafa Mounir Shehab
//#pragma GCC optimize("O3")
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
int OO=1e9;
const int N=1e3 + 10,M = N << 1;
int id[N];
int n,m,k,T;
int a,b,c,ans;

vector<pair<int,pair<int,int>>> edges;
struct DSU{
	int par[N],sz[N],comp;
	
	void init(int n){
		comp = n;
		iota(par,par+n,0);
		fill(sz,sz+n,1);
	}
	
	int find(int u){
		if(u == par[u]) return u;
		return par[u] = find(par[u]);
	}
	
	bool join(int u,int v){
		u = find(u);
		v = find(v);
		if(u == v) return false;
		
		if(sz[u] < sz[v]) swap(u,v);
		par[v] = u;
		sz[u] += sz[v];
		--comp;
		return true;
	}
	
	vector<int> MST(vector<pair<int,pair<int,int>>> &v){
		sort(v.begin(),v.end());
		vector<int> ret;
		for(auto &it:v){
			int u,v;
			tie(u,v) = it.second;
			if(!join(u,v))
				ret.push_back(it.first);
		}
		return ret;
	}
	
} DS;


void clr(int n){
	DS.init(n);
	edges.clear();
}

int main(){
	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%d%d",&n,&m) , (n || m)){
		clr(n);
		for(int i=0;i<m;++i){
			int u,v,c;
			scanf("%d%d%d",&u,&v,&c);
			edges.push_back({c,{u,v}});
		
		}
		
		vector<int> ans = DS.MST(edges);
		if(!SZ(ans))
			puts("forest");
		
		for(int i=0;i<SZ(ans);++i)
			printf("%d%c",ans[i]," \n"[i+1 == SZ(ans)]);
	}


	
	return 0;
}
