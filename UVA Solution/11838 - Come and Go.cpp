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
int OO=1e8 + 7;
const int N=2e3 + 2,M = 27;
int vis[N],instack[N],dfsn[N],low[N];

int n,m,k,T,lvl,comp;
int a,b,c;

vector<int> adj[N];
stack<int> st;

void clr(int n){
	for(int i=1;i<=n;++i)
		adj[i].clear();
	
	st = stack<int>();
	lvl = comp = 0;
	memset(vis+1,0,n*sizeof(vis[0]));
}

void Tarjan(int u){
	vis[u] = instack[u] = true;
	low[u] = dfsn[u] = ++lvl;
	st.push(u);
	
	for(int i:adj[u]){
		if(!vis[i]){
			Tarjan(i);
			low[u] = min(low[u],low[i]);
		}else if(instack[i])
			low[u] = min(low[u],dfsn[i]);
	}
	
	if(low[u] == dfsn[u]){
		++comp;
		while(st.top() != u){
			instack[st.top()] = false;
			st.pop();
		}
		instack[st.top()] = false;
		st.pop();
	}
	
}


bool valid(){
	
	for(int i=1;i<=n;++i)
		if(!vis[i])
			Tarjan(i);
	
	return comp == 1;
}


int main(){

	IO
	while(cin>>n>>m && (n || m)){
		clr(n);
		while(m--){
			cin>>a>>b>>c;
			adj[a].push_back(b);
			if(c == 2)
				adj[b].push_back(a);
		}
		
		cout<<valid()<<endl;
	}
	
	
	return 0;
}
 
