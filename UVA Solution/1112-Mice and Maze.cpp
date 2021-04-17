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
int OO=1e9;
const int N=1e2 + 10,M=(1<<12) + 1;
int vis[N];
 
int n,m,k,T,cnt,SU,len;
ll a,b,c,d;
ll l,r,mid;
bool flage;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

vector<pair<int,int>> adj[N];

void clr(int n){
	for(int i=1;i<=n;++i)
		adj[i].clear();
	
	fill(vis+1,vis+n+1,OO);
}


int Dijkstra(int u){
	int cnt = 0;
	
	priority_queue<pair<int,int>> pr;
	vis[u] = 0;
	pr.push({-vis[u],u});
	
	while(SZ(pr)){
		int v = pr.top().second;
		cnt += (-pr.top().first <= k);
		pr.pop();
		
		for(auto it:adj[v]){
			if(vis[v] + it.second >= vis[it.first]) continue;
			
			vis[it.first] = vis[v] + it.second;
			pr.push(make_pair(-vis[it.first],it.first));
		}
	}
	
	return cnt;
}

int main(){
	IO
	cin>>T;
	while(T--){
		
		cin>>n>>m>>k>>len;
		clr(n);
		while(len--){
			cin>>a>>b>>c;
			adj[b].push_back(make_pair(a,c));
		}
		if(flage)
			cout<<"\n";
		cout<<Dijkstra(m)<<endl;
		flage = true;
	}

		
}
 
