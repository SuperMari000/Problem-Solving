//        Mostafa Mounir Shehab
 
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
 
 
ll MOD=998244353ll; 
const int N=1e3+ 1;
bool visit[N];

int n,m,k;
int a,b;

vector<int> adj[N];
stack<int> st;

void DFS(int u){
	visit[u]=true;
	
	for(int i:adj[u])
		if(!visit[i])
			DFS(i);
			
	st.push(u);
}




int main(){
	
	while(scanf("%d%d",&n,&m) && !(!n && !m)){
		
		memset(visit,0,sizeof(visit));
		
		for(int i=0;i<N;++i)
			adj[i].clear();
			
		while(m--){
			scanf("%d%d",&a,&b);
			adj[a].push_back(b);
		
		}
		
		for(int i=1;i<=n;++i)
			if(!visit[i])
				DFS(i);
	
			
		while(!st.empty()){
			printf("%d ",st.top());
			st.pop();
		}

		puts("");
	}
	
	

 
}
 
 
 
 
 
 
 
