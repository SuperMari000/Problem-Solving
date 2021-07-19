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
ll OO=1e10;
const int N=30 + 1,M=1e7 + 1;
char str[N];
bool adj[N][N];
int par[N];
bool vis[N];

int n,m,k,T;
int a,b,c;

struct DSU{
	int nc;
	
	void init(int n){
		this->nc = n;
		iota(par,par+N,0);
		memset(adj,0,sizeof adj);
		memset(vis,0,sizeof vis);
	}
	
	int find(int u){
		if(u == par[u]) return u;
		return par[u] = find(par[u]);
	}
	
	bool join(int a,int b){
		a = find(a);
		b = find(b);
		if(a == b) return false;
		
		par[b] = a;
		--nc;
		return true;
	}
	
	void Solve(int n){
		if(nc != 1){
			puts("THIS BRAIN NEVER WAKES UP");
			return;
		}
		
		for(int i=0;str[i];++i)
			vis[str[i] - 'A'] = true;
		
		int year = 0;
		int len = n-3;
		bool val = true;
		while(len && val){
			val = false;
			vector<int> v;
			for(int i=0;i<26;++i){
				if(vis[i]) continue;
				int a = 0;
				for(int j=0;j<26;++j)
					a += (adj[i][j] && vis[j]);
				
				if(a >= 3)
					v.push_back(i);
			}
			
			val = SZ(v) > 0;
			for(int i:v)
				vis[i] = true;
			len -= SZ(v);
			++year;
		}
		
		if(len)
			puts("THIS BRAIN NEVER WAKES UP");
		else
			printf("WAKE UP IN, %d, YEARS\n",year);
		
	}
	
	
} DS;

 
 
 
 
int main(){

	
	while(~scanf("%d%d",&n,&m)){
		DS.init(n);
		
		scanf("%s",str);
		while(m--){
			char u,v;
			scanf(" %c%c",&u,&v);
			adj[u-'A'][v-'A'] = adj[v-'A'][u-'A'] = 1;
			DS.join(u-'A',v-'A');
		}
		
		
		DS.join(str[0]-'A',str[1]-'A');
		DS.join(str[1]-'A',str[2]-'A');
		
		DS.Solve(n);
		
	}
	
		
	return 0;
}
 

