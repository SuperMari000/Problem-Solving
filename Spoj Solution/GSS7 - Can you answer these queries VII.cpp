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
 
int sz[N],heavy[N],par[N],depth[N],idxNode[N],EndNode[N],value[N],CHhead[N];
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
	EndNode[u] = SZ(Tour) - 1;
	
}


struct Node{
	ll sum,best,pre,suf,lz;
	Node(){
		sum = 0;
		best = pre = suf = -1e9;
		lz = INT_MIN;
	} 
	
	Node(ll val){
		pre = suf = best = max(val,0ll);
		sum = val;	
		lz = INT_MIN;
	}
	void Swap(){
		swap(pre,suf);
	}
	void addLazy(int l,int r,ll val){
		sum = (r-l+1)*val;
		pre = suf = best = max(sum,0ll);
		lz = val;
	}
	
	
	friend ostream& operator << (ostream& out, Node &s){
		out<<s.pre<<" "<<s.suf<<" "<<s.suf<<" "<<s.sum<<"\n";
	    return out;
	}
};

Node operator + (const Node l,const Node r){
	Node ret;
	ret.pre = max(l.pre,l.sum + r.pre);
	ret.suf = max(r.suf,r.sum + l.suf);
	ret.best = max({r.best,l.best,l.suf + r.pre});
	ret.sum = l.sum + r.sum;
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

	void PushDown(int l,int r,int pos){
		ll &lz = seg[pos].lz;
		if(l == r || lz == INT_MIN) return;
		int mid = (l + r) >> 1;
		seg[pos << 1].addLazy(l,mid,lz);
		seg[pos << 1 | 1].addLazy(mid+1,r,lz);
		lz = INT_MIN;
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
	
	
	Node Query(int l,int r,int pos,int st,int en){
		if(st > r || en < l || st > en)
			return Node();
		PushDown(l,r,pos);
		if(l >= st && r <= en)
			return seg[pos];

		int mid = (l + r) >> 1;
		Node lt = Query(l,mid,pos << 1,st,en);
		Node rt = Query(mid+1,r,pos << 1 | 1,st,en);
		
		return lt + rt;
	}
	
	void Update(int l,int r,int pos,int st,int en,int val){
		if(st > r || en < l || st > en)
			return;
		PushDown(l,r,pos);
		if(l >= st && r <= en){
			seg[pos].addLazy(l,r,val);
			return;
		}
		
		int mid = (l + r) >> 1;
		Update(l,mid,pos << 1,st,en,val);
		Update(mid+1,r,pos << 1 | 1,st,en,val);
		
		seg[pos] = seg[pos << 1] + seg[pos << 1 | 1];
	}
	
	
} ST;
 


int Solve(int u,int v){
	Node Nu ,Nv;
	while(CHhead[u] != CHhead[v]){
		if(depth[CHhead[u]] < depth[CHhead[v]]){
			swap(u,v);
			swap(Nu,Nv);
		}
		
		Node lt = ST.Query(0,n-1,1,idxNode[CHhead[u]],idxNode[u]);
		Nu = lt + Nu;

		u = par[CHhead[u]];
	}
	
	if(idxNode[v] < idxNode[u]){
		swap(u,v);
		swap(Nu,Nv);
	}
	Node lt = ST.Query(0,n-1,1,idxNode[u],idxNode[v]);
	Nv = lt + Nv;
	
	Nu.Swap();
	Nu = Nu + Nv;
	return Nu.best;
}

void Update(int u,int v,int val){

	while(CHhead[u] != CHhead[v]){
		if(depth[CHhead[u]] < depth[CHhead[v]])
			swap(u,v);

		ST.Update(0,n-1,1,idxNode[CHhead[u]],idxNode[u],val);
		
		u = par[CHhead[u]];
	}
	
	if(idxNode[v] < idxNode[u])
		swap(u,v);
	
	ST.Update(0,n-1,1,idxNode[u],idxNode[v],val);
}

void clr(int n){
	adj.init(n);
	Tour.clear();
	
}
 
int main(){

//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int ID = 1;
	while(ID--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",value+i);
		
		clr(n);
		for(int i=1;i<n;++i){
			int u,v,c;
			scanf("%d%d",&u,&v);
			adj.addBiEdge(u-1,v-1,0);
		}
		
		DFS();
		HLD();
		ST.init(Tour);
		
		scanf("%d",&T);
		while(T--){
			int tp,u,v,val;
			scanf("%d%d%d",&tp,&u,&v);
			--u,--v;
			
			if(tp == 1){
				printf("%d\n",Solve(u,v));
			}else{
				scanf("%d",&val);
				Update(u,v,val);
			}

		}

	}
	
	
	return 0;
} 
