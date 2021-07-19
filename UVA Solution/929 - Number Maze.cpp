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
const int N=1e3 + 10,M=(1<<12) + 1;
int arr[N][N];
int vis[N][N];
 
int n,m,k,T,cnt,SU,len;
ll a,b,c,d;
ll l,r,mid;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void clr(int n,int m){
	for(int i=0;i<n;++i)
		fill(vis[i],vis[i] + m + 1,OO);
}

bool valid(int x,int y){
	return ~x && ~y && x < n && y < m;
}

int Dijkstra(){
	
	priority_queue<pair<int,pair<int,int>>> pr;
	vis[0][0] = arr[0][0];
	pr.push({-vis[0][0],{0,0}});
	
	while(SZ(pr)){
		auto it = pr.top().second;
		pr.pop();
		
		for(int i=0;i<4;++i){
			int u = it.first + dx[i];
			int v = it.second + dy[i];
			if(valid(u,v) && vis[it.first][it.second] + arr[u][v] < vis[u][v]){
				vis[u][v] = vis[it.first][it.second] + arr[u][v];
				pr.push(make_pair(-vis[u][v],make_pair(u,v)));
			}
		}
	}
	
	return vis[n-1][m-1];
}

int main(){
	IO
	cin>>T;
	while(T--){
		
		cin>>n>>m;
		clr(n,m);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				cin>>arr[i][j];
		
		cout<<Dijkstra()<<endl;
	
	}

	
	
	
}
 
