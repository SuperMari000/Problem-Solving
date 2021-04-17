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
 
 
ll MOD=1e9 + 7; 
const int N=1e6+ 1;
int visit[N];


vector<int> adj[N];
stack<int> st;
bool flage;

int n,m,k;
int a,b;

void DFS(int u){
	visit[u]=0;
	for(int i:adj[u]){
		if(visit[i] == -1)
			DFS(i);
		else if(!visit[i])
			flage=false;
	}

	visit[u]=1;
	st.push(u);
}




int main(){
	
	
	while(scanf("%d%d",&n,&m) && !(!n && !m)){
		
		
		memset(visit,-1,sizeof(visit));
		st=stack<int>();
		flage=true;
		
		for(int i=0;i<N;++i)
			adj[i].clear();
		
		for(int i=0;i<m;++i){
			scanf("%d%d",&a,&b);
			adj[a].push_back(b);
		}
		
		for(int i=1;i<=n;++i)
			if(visit[i] == -1)
				DFS(i);
		
		if(flage)
			while(SZ(st))
				printf("%d\n",st.top()),st.pop();
		else
			puts("IMPOSSIBLE");
		
	}
	
	
	

 
}
 
 
 
 
 
 
 
