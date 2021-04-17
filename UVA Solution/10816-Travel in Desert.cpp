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
int OO=1e6;
const int N=1e3 + 10,M=(1<<12) + 1;
double vis[N];
int par[N];
 
int n,m,k,T,cnt,SU,st,en;
ll a,b,c,d;
ll l,r,mid;
bool flage;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

vector<pair<int,pair<double,double>>> adj[N];
vector<double> vec;

void clr(int n){
	for(int i=1;i<=n;++i)
		adj[i].clear();
	vec.clear();
}


int Dijkstra(int idx){
	
	fill(vis+1,vis+n+1,OO);
	priority_queue<pair<double,int>> pr;
	vis[st] = 0;
	pr.push({-vis[st],st});
	
	while(SZ(pr)){
		int v = pr.top().second;
		pr.pop();
		
		for(auto it:adj[v]){
			if(vis[v] + it.second.first >= vis[it.first] || vec[idx] < it.second.second) continue;
			par[it.first] = v;
			vis[it.first] = vis[v] + it.second.first;
			pr.push(make_pair(-vis[it.first],it.first));
		}
	}
	
	return OO - vis[en] > EPS;
}

pair<double,double> BS(){
	int l=0,r = SZ(vec)-1,mid;
	while(l<r){
		mid = (l+r)>>1;
		if(Dijkstra(mid))
			r = mid;
		else
			l = mid + 1;
	}
	Dijkstra(r);
	return make_pair(vis[en],vec[r]);
}

void print(pair<double,double> p){
	int val = en;
	vector<int> ans;
	while(val != st){
		ans.push_back(val);
		val = par[val];
	}
	ans.push_back(st);
	reverse(ans.begin(),ans.end());

	for(int i=0;i<SZ(ans);++i)
		printf("%d%c",ans[i]," \n"[i == SZ(ans)-1]);
		
	printf("%0.1lf %0.1lf\n",p.first,p.second);
}


int main(){
	
	while(~scanf("%d%d",&n,&m)){
		scanf("%d%d",&st,&en);
		clr(n);
		while(m--){
			int u,v;
			double a,b;
			scanf("%d%d%lf%lf",&u,&v,&a,&b);
			adj[u].push_back(make_pair(v,make_pair(b,a)));
			adj[v].push_back(make_pair(u,make_pair(b,a)));
			vec.push_back(a);
		}
		
		sort(vec.begin(),vec.end());
		
		pair<double,double> p = BS();
		print(p);
	}

		
}
 
