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
int OO=1e8;
const int N=1e2 + 5,M= 1e4;


int n,m,k,SU,idx,len,MN,MX,T;
int l,r,mid;
int a,b,c;


pair<int,int> ans;
int head[N],nxt[M],to[M],vis[N],vid,ne,src;

void init(int n){
	memset(head,-1,n*sizeof(head[0]));
	memset(vis,0,n*sizeof(vis[0]));
	ne = 0;
	ans = {0,src};
}

void addEdge(int u,int v){
	nxt[ne] = head[u];
	to[ne] = v;
	head[u] = ne++;
}

void addBiEdge(int u,int v){
	addEdge(u,v);
	addEdge(v,u);
}

void BFS(int u){
	
	priority_queue<pair<int,int>> pr;
	pr.push({0,u});
	vis[u] = 0;
	
	while(SZ(pr)){
		int u = pr.top().second;
		pr.pop();
		
		for(int e = head[u]; ~e ; e = nxt[e]){
			int v = to[e];
			if(vis[u] + 1 < vis[v]) continue;
			vis[v] = vis[u] + 1;
			
			if(vis[v] > ans.first)
				ans = make_pair(vis[v],v);
			else if(vis[v] == ans.first)
				ans.second = min(ans.second,v);
			
			pr.push({vis[v],v});
		}
		
	}
}


 
int main(){
	
	int ID = 1;
	while(scanf("%d",&n) , n){
		scanf("%d",&src);
		--src;
		init(n);
		while(scanf("%d%d",&a,&b) && (a || b)){
			--a,--b;
			addEdge(a,b);
		}
		
		BFS(src);
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",ID++,src+1,ans.first,ans.second+1);

	}
	
}
