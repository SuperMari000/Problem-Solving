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
    int head[N], nxt[M], to[M], cost[M], n, ne;
 	
 	void init(int nNodes) {
        ne = 0;
        n = nNodes;
        memset(head, -1, n * sizeof head[0]);
    }
    void addEdge(int f, int t,int c) {
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

int dist[N];

void Dijkstra(int u,int v){
	priority_queue<pair<int,int>> pr;
	fill(dist,dist+n,OO);
	pr.push({0,u});
	dist[u] = 0;
	while(SZ(pr)){
		int u,len;
		tie(len,u) = pr.top();
		pr.pop();
		neigh(u,e,v){
			if(dist[u] + adj.cost[e] < dist[v]){
				dist[v] = dist[u] + adj.cost[e];
				pr.push({-dist[v],v});
			}
		}
	}
	
	if(dist[v] >= OO)
		puts("NO");
	else
		printf("%d\n",dist[v]);
}



int main(){
	
//	IO
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		adj.init(n);
		int u,v,c;
		while(m--){
			scanf("%d%d%d",&u,&v,&c);
			--u,--v;
			adj.addEdge(u,v,c);
		}
		
		scanf("%d%d",&u,&v);
		--u,--v;
		Dijkstra(u,v);
		
	}
	
	
	return 0;
}
