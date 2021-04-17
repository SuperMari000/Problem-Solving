//       Author: Mostafa Mounir Shehab
 
#include <bits/stdc++.h>
using namespace std;
 
#define PI  3.14159265  // PI = acos(-1)
#define EPS (1e-10)
#define endl "\n"
#define SZ(v) (int)(v.size())
typedef long long ll;
typedef long double ld;
//template <class Type>

 
inline int D(){
	int t;
	scanf("%d",&t);
	return t;
}
inline ll llD(){
	ll t;
	scanf("%lld",&t);
	return t;
}
 
 
const int N=1e5 + 5;
bool visit[N];
vector<int> adj[N];

int n,m,k;
int a,b;

int DFS(int u){
	
	visit[u] = true;
	int cnt=1;
	for(int i:adj[u])
		if(!visit[i])
			cnt+=DFS(i);
	return cnt;
}


void clr(){
	for(int i=0;i<N;++i){
		visit[i]=false;
		adj[i].clear();
	}
}

 
int main(){
	
	int T=D();
	while(T--){
		
		clr();
		scanf("%d%d",&n,&m);
		
		while(m--){
			scanf("%d%d",&a,&b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int MX=0;
		
		for(int i=1;i<=n;++i)
			if(!visit[i])
				MX=max(MX,DFS(i));
		
		printf("%d\n",MX);
		
	}
	
	
 
}



