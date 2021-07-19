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
const int N=1e4 + 10,M = N << 1;

int n,m,k,T;
int a,b,c,ans;


#define neigh(u, e, v) for (int e = adj.head[u], v; ~e && (v = adj.to[e], 1); e = adj.nxt[e])
struct ADJ {
    int head[N], nxt[M], to[M], cost[M], n, ne;
 	
 	void init(int nNodes) {
        ne = 0;
        n = nNodes;
        memset(head, -1, n * sizeof head[0]);
    }
    void addEdge(int f, int t, int c) {
    	cost[ne] = c;
        to[ne] = t;
        nxt[ne] = head[f];
        head[f] = ne++;
    }
 
    void addBiEdge(int u, int v, int c) {
        addEdge(u, v, c);
		addEdge(v, u, c);
    }
    
} adj;


struct LCA{
	
	typedef pair<int, int> Pii;
	
	struct SparseTable{
		
		vector<vector<Pii>> spT;
		vector<int> LOG;
		int len;
		
		void init(vector<Pii> &tour){
			len = (int)tour.size();
			
			LOG = vector<int>(len + 1 , 0);
			for(int i=2;i<=len;++i)
				LOG[i] += LOG[i-1] + !(i & (i - 1));
			
			Bulid(tour);
		}
		
		void Bulid(vector<Pii> &tour){
			if(tour.empty())
				return;

			int K = LOG[len];
			spT = vector<vector<Pii>>(K + 1,vector<Pii> (len));
			
			spT[0] = tour;
			
			for(int lvl = 1; lvl <= K ; ++lvl)
				for(int i = 0; i + (1 << lvl) <= len; ++i)
					spT[lvl][i] = min(spT[lvl - 1][i],
									  spT[lvl - 1][i + (1 << (lvl-1))]);
			
		}
		
		Pii Query(int l,int r){
			int lg = LOG[r - l + 1];
			return min(spT[lg][l], spT[lg][r - (1 << lg) + 1]);
		}
		
	} SP;
	

	vector<int> depth,firstIn;
	vector<ll> dist;
	vector<Pii> tour;
	int root,n;
	LCA(const int &root_) : root(root_){

		n = (int)adj.n;
		depth = firstIn = vector<int>(n , -1);
		dist = vector<ll>(n , 0);

		DFS(root,-1,0);
		SP.init(tour);
	}
	
	void DFS(int u,int p,int d){
		depth[u] = d;
		firstIn[u] = (int)tour.size();
		tour.push_back(make_pair(depth[u],u));
		
		neigh(u,e,v){
			if(v == p) continue;
			dist[v] = dist[u] + adj.cost[e];
			DFS(v, u, d + 1);
			tour.push_back(make_pair(depth[u],u));
		}
	}
	
	int get_LCA(int u,int v){
		if(firstIn[u] > firstIn[v])
			swap(u,v);
		return SP.Query(firstIn[u], firstIn[v]).second;
	}
	
	int get_Distance(int u,int v){
		int lca = get_LCA(u,v);
		return depth[u] + depth[v] - (depth[lca] << 1);
	}
};

int par[N],SP[N][20];
void DFS(int u,int p){
	par[u] = p;
	SP[u][0] = p;
	neigh(u,e,v){
		if(v == p) continue;
		DFS(v,u);
	}
}


void BulidBF(){
	for(int lvl=1;lvl<20;++lvl){
		for(int i=0;i<n;++i){
			int p = SP[i][lvl - 1];
			if(p == -1) continue;
			SP[i][lvl] = SP[p][lvl - 1];
		}
	}
}

int Solve(int a,int b,int k,LCA &Tree){
	int lc = Tree.get_LCA(a,b);
	assert(k <= Tree.get_Distance(a,b));
	int x = a;
	for(int lvl=19;~lvl;--lvl){
		int p = SP[x][lvl];
		if(p == -1) continue;
		if((1<<lvl) <= k && Tree.depth[p] >= Tree.depth[lc]){
			k -= (1 << lvl);
			x = p;
		}
	}
	if(!k) return x + 1;
	x = b;
	k = Tree.depth[b] - Tree.depth[lc] - k;
	for(int lvl=19;~lvl;--lvl){
		int p = SP[x][lvl];
		if(p == -1) continue;
		if((1<<lvl) <= k && Tree.depth[p] >= Tree.depth[lc]){
			k -= (1 << lvl);
			x = p;
		}
	}
	return x + 1;
}


int main(){
	
//	IO
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		adj.init(n);
		for(int i=1;i<n;++i){
			int u,v,c;
			scanf("%d%d%d",&u,&v,&c);
			--u,--v;
			adj.addBiEdge(u,v,c);
		}

		LCA Tree(0);
		memset(SP,-1,sizeof SP);
		DFS(0,-1);
		BulidBF();
		
		char typ[5];
		while(scanf("%s",typ)){
			if(typ[0] == 'D' && typ[1] == 'O')
				break;
			int u,v;
			scanf("%d%d",&u,&v);
			--u,--v;
			if(typ[0] == 'D'){
				int lc = Tree.get_LCA(u,v);
				ll ans = Tree.dist[u] + Tree.dist[v] - 2 * Tree.dist[lc];
				printf("%lld\n",ans);
			}else{
				int k;
				scanf("%d",&k);
				--k;
				printf("%d\n",Solve(u,v,k,Tree));
			}
		}
	}
	
	return 0;
}
