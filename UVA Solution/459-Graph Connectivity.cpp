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
const int N=1e2 + 5,M=1e7 + 5;

int n,m,k,T;

struct DSU{
	int par[N];
	int sz[N];
	int n;
	
	DSU(int n){
		this->n = n;
		fill(sz,sz+n,1);
		iota(par,par+n,0);
	}
	
	int find(int u){
		if(u == par[u]) return u;
		return par[u] = find(par[u]);
	}
	
	void join(int a,int b){
		a = find(a);
		b = find(b);
		if(a == b) return;
		
		if(sz[a] < sz[b]) swap(a,b);
		
		par[b] = a;
		sz[a] += sz[b];
		
		--n;
	}

};



int main(){
	
	IO
	
	char c;
	string s;
	
	cin>>T;
	while(T--){
		
		cin>>c;
		cin.ignore();
		
		DSU DS(c - 'A' + 1);
		
		while(getline(cin, s) && s != "")
			DS.join(s.front()-'A',s.back()-'A');
		
		
		cout<<DS.n<<endl;
		if(T)
			cout<<"\n";
	}
	
	return 0;
}
