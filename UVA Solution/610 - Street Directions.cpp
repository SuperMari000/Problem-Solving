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
int OO=1e9 + 1;
const int N=1e3 + 10,M=1e3 + 10;

bool vis[N];
int dfsn[N],low[N];

int n,m,k,T;
int a,b,c;

vector<int> adj[N];
map<pair<int,int>,bool> mp;
int Time;

void clr(int n){
	for(int i=0;i<n;++i){
		adj[i].clear();
		vis[i] = false;
	}
	mp.clear();
	Time = 1;
}


void Tarjan(int u,int p){
	vis[u] = true;
	dfsn[u] = low[u] = Time++;

	for(int i:adj[u]){
		if(i == p) continue;
		if(!vis[i]){
			Tarjan(i,u);
			low[u] = min(low[u],low[i]);
			
			mp[{u,i}] = true;
			
			if(dfsn[u] < low[i])
				mp[{i,u}] = true;
			
		}else{
			if(!mp.count({i,u}))
				mp[{u,i}] = true;
				
			low[u] = min(low[u],dfsn[i]);			
		}
			
	}
	
}



int main(){
	
	IO
	int ID = 1;
	while(cin>>n>>m && (n || m)){
		clr(n);
		while(m--){
			cin>>a>>b;
			--a,--b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
				
		Tarjan(0,-1);
		
		cout<<ID++<<"\n\n";
		for(auto it:mp)
			cout<<it.first.first+1<<" "<<it.first.second+1<<endl;
		cout<<"#\n"; 
		
	}
		
}


