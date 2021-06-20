//       Author: Mostafa Mounir Shehab

#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
 
#define PI  acos(-1)
#define EPS (1e-9)
#define endl "\n"
#define SZ(v) (int)(v.size())
#define IO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL);
typedef long long ll;
typedef long double ld;
 
 
ll MOD=5e6;
int OO=1e8;
const int N=5e5 + 10,M = N << 1;
int n,m,k,T;

#define neigh(u, e, v) for (int e = adj.head[u], v; ~e && (v = adj.to[e], 1); e = adj.nxt[e])
struct ADJ {
    int head[N], nxt[M], to[M], n, ne;
 	
 	void init(int nNodes) {
        ne = 0;
        n = nNodes;
        memset(head, -1, n * sizeof head[0]);
    }
    void addEdge(int f, int t) {
        to[ne] = t;
        nxt[ne] = head[f];
        head[f] = ne++;
    }
 
    void addBiEdge(int u, int v) {
        addEdge(u, v);
		addEdge(v, u);
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
	vector<Pii> tour;
	int root,n;
	LCA(const int &root_) : root(root_){
		n = adj.n;
		depth = firstIn = vector<int>(n , -1);

		DFS(root,-1,0);
		SP.init(tour);
	}
	
	void DFS(int u,int p,int d){
		depth[u] = d;
		firstIn[u] = (int)tour.size();
		tour.push_back(make_pair(depth[u],u));

		neigh(u,e,v){
			if(v == p) continue;
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

bitset<251> clc[N];
int ans[N],arr[N];

void DfsClc(int u,int p){
	clc[u].reset();
	clc[u][arr[u] - 1] = 1;
	neigh(u,e,v){
		if(v == p) continue;
		DfsClc(v,u);
		clc[u] |= clc[v];
	}
	ans[u] = clc[u].count();
}

 
int main(){
	
	scanf("%d",&T);
	while(T--){
		int r,u,v;
		scanf("%d%d%d",&n,&m,&r);
		for(int i=0;i<n;++i)
			scanf("%d",arr+i);
		adj.init(n);
		for(int i=1;i<n;++i){
			scanf("%d%d",&u,&v);
			adj.addBiEdge(u,v);
		}
		LCA Tree(r);
		DfsClc(r,-1);

		while(m--){
			scanf("%d%d",&u,&v);
			int lc = Tree.get_LCA(u,v);
			printf("%d\n",ans[lc]);
		}
	}
	
	return 0;	
}
 
