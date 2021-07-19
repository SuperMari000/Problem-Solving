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
const int N=1e3 + 100,M=(1<<12) + 1;
int arr[N][N];
int vis[N][N];
 
int n,m,k,T,cnt,SU,st,en,len;
int a,b,c,d;
int l,r,mid;
bool flage;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};


void clr(int n,int m){
	for(int i=0;i<n;++i){
		memset(arr[i],0,m*sizeof(arr[0][0]));
		fill(vis[i],vis[i]+m,OO);
	}
	
}

bool valid(int u,int v){
	return ~u && ~v && u < n && v < m;
}
int BFS(int a,int b,int c,int d){
	
	queue<pair<int,int>> q;
	vis[a][b] = 0;
	q.push(make_pair(a,b));
	
	while(SZ(q)){
		auto p = q.front();
		q.pop();
		
		for(int i=0;i<4;++i){
			int u = p.first + dx[i];
			int v = p.second + dy[i];
			if(valid(u,v) && !arr[u][v] && vis[p.first][p.second] + 1 < vis[u][v]){
				vis[u][v] = vis[p.first][p.second] + 1;
				q.push(make_pair(u,v));
			}
				
		}
	}
	
	return vis[c][d];
}

int main(){
	
	while(scanf("%d%d",&n,&m) && n && m){
		
		clr(n,m);
		scanf("%d",&len);
		while(len--){
			int u,v,cnt;
			scanf("%d%d",&u,&cnt);
			while(cnt--){
				scanf("%d",&v);
				arr[u][v] = 1;
			}
			
		}
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d\n",BFS(a,b,c,d));
		
	}

		
}
 
