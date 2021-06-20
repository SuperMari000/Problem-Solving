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
const int N=1e4 + 10,M = 1e6 + 10;
int arr[N];

int n,m,k,T;
int a,b,c,ans;


#define neigh(u, e, v) for (int e = adj.head[u], v; ~e && (v = adj.to[e], 1); e = adj.nxt[e])
struct ADJ {
    int head[N], nxt[M], to[M], inDeg[N], n, ne;
 	
 	void init(int nNodes) {
        ne = 0;
        n = nNodes;
        memset(head, -1, n * sizeof head[0]);
    }
    void addEdge(int f, int t) {
    	inDeg[t]++;
        to[ne] = t;
        nxt[ne] = head[f];
        head[f] = ne++;
    }
 
    void addBiEdge(int u, int v) {
        addEdge(u, v);
		addEdge(v, u);
    }
    
} adj;

bool cycle;
int vis[N];
void Cycle(int u){
	vis[u] = 1;
	neigh(u,e,v){	
		if(!vis[v])
			Cycle(v);
		else if(vis[v] == 1)
			cycle = true;
	
	}
	vis[u] = 2;
}


void Solve(){
	for(int i=0;i<n;++i)
		if(!vis[i])
			Cycle(i);
	
	if(cycle){
		puts("Sandro fails.");
		return;
	}
	priority_queue<int> pr;
	for(int i=0;i<n;++i)
		if(!adj.inDeg[i])
			pr.push(-i);
	if(!SZ(pr)){
		puts("Sandro fails.");
		return;
	}
	while(SZ(pr)){
		int u = -pr.top();
		pr.pop();
		printf("%d ",u + 1);
		neigh(u,e,v){
			--adj.inDeg[v];
			if(!adj.inDeg[v])
				pr.push(-v);
		}
	}
	
}



int main(){
	
//	IO
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&m);
	adj.init(n);
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		--u,--v;
		adj.addEdge(u,v);
	}
	
	Solve();
	
	return 0;
}
