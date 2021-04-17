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
const int N=2e5 + 5,M=1e7 + 1;
int par[N];
int sz[N];
int id[N];
ll sum[N];


int n,m,k,T;
int a,b,c;

struct DSU{
	
	int pos;
	
	void init(int n){
		int len = (n<<1) + 2;
		
		this->pos = n+1;
		iota(par,par+len,0);
		iota(sum,sum+len,0);
		iota(id,id+len,0);
		fill(sz,sz+len,1);
		
	}
	
	int find(int u){
		if(u == par[u]) return u;
		return par[u] = find(par[u]);
	}
	
	bool join(int a,int b){
		a = id[a],b = id[b];
		a = find(a),b = find(b);
		if(a == b) return false;
		
		if(sz[a] < sz[b]) swap(a,b);
		
		par[b] = a;
		sz[a] += sz[b];
		sum[a] += sum[b];
		
		return true;
	}
	
	bool con(int a,int b){
		int u = id[a],v = id[b];
		u = find(u),v = find(v);
		
		if(u == v) return false;
		
		--sz[u];
		sum[u] -= a;
		
		int val = id[a] = pos++;
		par[val] = v;
		sz[v]++;
		sum[v] += a;
		return true;
	}
	
	void print(int u){
		u = id[u];
		u = find(u);
		cout<<sz[u]<<" "<<sum[u]<<endl;
	}
	
	
	
} DS;

 
 
 
int main(){

	
	while(~scanf("%d%d",&n,&m)){
		DS.init(n);
		int type,a,b;
		
		while(m--){
			cin>>type;
			if(type == 1){
				cin>>a>>b;
				DS.join(a,b);
			}else if(type == 2){
				cin>>a>>b;
				DS.con(a,b);
			}else{
				cin>>a;
				DS.print(a);
			}
		}
		
	}
	
		
	return 0;
}
 

