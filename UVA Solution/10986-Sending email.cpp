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
int OO=1e9 + 7;
const int N=2e4 + 100;
int vis[N];
 
int n,m,k,T,st,en;


vector<pair<int,int>> adj[N];
 
void clr(int n){
	fill(vis,vis+n,OO);
	for(int i=0;i<n;++i)
		adj[i].clear();
}
 
 
void Read(int n){
	int a,b,c;
	while(n--){
		cin>>a>>b>>c;
	
		adj[a].push_back(make_pair(b,c));
		adj[b].push_back(make_pair(a,c));
	}
	
}

void Dijkstra(int a,int b){

	priority_queue<pair<int,int>> pr; // cost , node
	
	vis[a] = 0;
	pr.push(make_pair(vis[a],a));
	
	while(SZ(pr)){
		int u = pr.top().second;
		pr.pop();
		
		for(auto i:adj[u]){
			if(i.second + vis[u] >= vis[i.first]) continue;
			
			vis[i.first] = vis[u] + i.second;
			pr.push(make_pair(-vis[i.first],i.first));
			
		}
	}
	
	if(vis[b] == OO)
		cout<<"unreachable\n";
	else
		cout<<vis[b]<<"\n";
	
}
  
int main(){
	
	IO
	cin>>T;
	int ID = 1;
	while(T--){
		cin>>n>>m>>st>>en;
		clr(n);
		Read(m);
		
		cout<<"Case #"<<ID++<<": ";
		Dijkstra(st,en);
		
	}
 
	return 0;
}
 
 
