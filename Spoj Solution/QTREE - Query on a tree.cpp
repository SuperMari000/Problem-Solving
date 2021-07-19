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
const int N=1e5 + 10,M = N << 1;
int n,m,k,T;
int a,b,c;
 
 
#define neigh(u, e, v) for (int e = adj.head[u], v; ~e && (v = adj.to[e], 1); e = adj.nxt[e])
struct ADJ {
    int head[N], nxt[M], to[M], cost[M], n, ne;
 	
 	void init(int nNodes) {
        ne = 0;
        n = nNodes;
        memset(head, -1, n * sizeof head[0]);
    }
    void addEdge(int f, int t,int c) {
        to[ne] = t;
        nxt[ne] = head[f];
        cost[ne] = c;
        head[f] = ne++;
    }
 
    void addBiEdge(int u, int v, int c) {
        addEdge(u, v, c);
		addEdge(v, u, c);
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
		value[v] = adj.cost[e];
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
	int mx;
	Node(){
		mx = INT_MAX;
	}
	
	Node(int val){
		mx = val;
	}

};

Node operator + (const Node l,const Node r){
	Node ret;
	ret.mx = max(l.mx, r.mx);
	return ret;
}
 
 
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
		
		seg[pos] = seg[pos << 1] + seg[pos << 1 | 1];
	}
	
	
	int Query(int l,int r,int pos,int st,int en){
		if(st > r || en < l || st > en)
			return 0;

		if(l >= st && r <= en)
			return seg[pos].mx;
		
		int mid = (l + r) >> 1;
		int lt = Query(l,mid,pos << 1,st,en);
		int rt = Query(mid+1,r,pos << 1 | 1,st,en);
		return max(lt, rt);
	}
	
	void Update(int l,int r,int pos,int idx,int val){
		if(l == r){
			seg[pos] = Node(val);
			return;
		}
		
		int mid = (l + r) >> 1;
		if(idx > mid)
			Update(mid+1,r,pos << 1 | 1,idx,val);
		else
			Update(l,mid,pos << 1,idx,val);

		seg[pos] = seg[pos << 1] + seg[pos << 1 | 1];
	}
 
 
} ST;
 
int Solve(int u,int v){
	int ans = 0;
	while(CHhead[u] != CHhead[v]){
		
		if(depth[CHhead[u]] < depth[CHhead[v]])
			swap(u,v);

		ans = max(ans, ST.Query(0,n-1,1,idxNode[CHhead[u]],idxNode[u]));

		u = par[CHhead[u]];
	}
	
	if(idxNode[v] < idxNode[u])
		swap(u,v);

	ans = max(ans, ST.Query(0,n-1,1,idxNode[u] + 1,idxNode[v]));
	return ans;
}

void Update(int idx,int val){
	idx = idx << 1;
	adj.cost[idx] = adj.cost[idx + 1] = val;
	int f = adj.to[idx];
	int t = adj.to[idx + 1];
	
	if(f == par[t])
		ST.Update(0,n-1,1,idxNode[t],val);
	else
		ST.Update(0,n-1,1,idxNode[f],val);
}

 
void clr(int n){
	adj.init(n);
	Tour.clear();
	
}
 
int main(){

//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int ID;
	scanf("%d",&ID);
	while(ID--){
		scanf("%d",&n);
		clr(n);
		for(int i=1;i<n;++i){
			int u,v,c;
			scanf("%d%d%d",&u,&v,&c);
			adj.addBiEdge(u-1,v-1,c);
		}
		
		DFS();
		HLD();
		ST.init(Tour);
		char arr[10];
		while(scanf("%s",arr)){
			string str = arr;
			if(str == "DONE")
				break;
			
			int u,v;
			scanf("%d%d",&u,&v);
			if(str == "QUERY"){
				--u,--v;
				printf("%d\n",Solve(u,v));
			}else{
				Update(u-1,v);
			}
		}

	}
	
	
	return 0;
} 
