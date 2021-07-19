//       Author: Mostafa Mounir Shehab
#pragma GCC optimize("O3")
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
const int N=1e5 + 10,M = N << 1;
int n,m,k,T;
int a,b,c;
 
 
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
 
int sz[N],heavy[N],par[N],depth[N],idxNode[N],value[N],CHhead[N];
vector<int> Tour;
 
 
void DFS(int u=0){
	sz[u] = 1;
	int &Hch = heavy[u] = -1;
	
	neigh(u,e,v){
		if(v == par[u]) continue;
		par[v] = u;
		depth[v] = depth[u] + 1;
		DFS(v);
		sz[u] += sz[v];
		if(Hch == -1 || sz[v] > sz[Hch])
			Hch = v;
	}
}
 
 
void HLD(int u=0,int ch=0){
	
	CHhead[u] = ch;
	idxNode[u] = SZ(Tour);
	Tour.push_back(u);
	
	if(~heavy[u])
		HLD(heavy[u],ch);
	
	neigh(u,e,v){
		if(v == par[u] || v == heavy[u]) continue;
		HLD(v,v);
	}
}
 
 
struct Node{
	vector<int> v;
	Node(){
		v.clear();
	}
	
	Node(int x){
		v = {x};
	}

};
 
 
struct SegmentTree{
	vector<Node> seg;
	vector<int> v;
	int n;
	void init(vector<int> &A){
		v = A;
		n = SZ(A);
		seg = vector<Node>(n << 2);
		Bulid(0,n-1,1);
	}
	
	
	void Bulid(int l,int r,int pos){
		if(l == r){
			seg[pos] = Node(value[v[l]]);
			return;
		}
			
		int mid = (l+r) >> 1;
		Bulid(l,mid,pos << 1);
		Bulid(mid+1,r,pos << 1 | 1);
		
		auto &lt = seg[pos << 1].v,&rt = seg[pos << 1 | 1].v,&cur = seg[pos].v;
		merge(lt.begin(),lt.end(),rt.begin(),rt.end(),inserter(cur,cur.begin()));
	}
	
	
	bool Query(int l,int r,int pos,int st,int en,int val){
		if(st > r || en < l || st > en)
			return 0;
		
		auto &cur = seg[pos].v;
		if(l >= st && r <= en)
			return SZ(cur) && val <= cur.back() && *lower_bound(cur.begin(),cur.end(),val) == val;
		
		int mid = (l+r) >> 1;
		bool lt = Query(l,mid,pos << 1,st,en,val);
		bool rt = Query(mid+1,r,pos << 1 | 1,st,en,val);
		return lt || rt;
	}
	
	bool Query(int st,int en,int val){
		return Query(0,n-1,1,st,en,val);
	}
 
 
} ST;
 
bool Solve(int u,int v,int xx){
	bool ans = false;
	while(CHhead[u] != CHhead[v]){
		
		if(depth[CHhead[u]] < depth[CHhead[v]])
			swap(u,v);
		
		ans |= ST.Query(idxNode[CHhead[u]],idxNode[u],xx);
 
		u = par[CHhead[u]];
	}
	
	if(idxNode[v] < idxNode[u])
		swap(u,v);
	ans |= ST.Query(idxNode[u],idxNode[v],xx);
	
	return ans;
}
 
 
 
 
void clr(int n){
	adj.init(n);
	Tour.clear();
	
}
 
int main(){

//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	while(~scanf("%d%d",&n,&T)){
		clr(n);
		for(int i=0;i<n;++i)
			scanf("%d",value+i);
		for(int i=1;i<n;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			adj.addBiEdge(u-1,v-1);
		}
		
		DFS();
		HLD();
		ST.init(Tour);
		
		while(T--){
			int u,v,c;
			scanf("%d%d%d",&u,&v,&c);
			--u,--v;
			puts(Solve(u,v,c) ? "Find" : "NotFind");
		}
		
	}
	
	
	return 0;
} 
