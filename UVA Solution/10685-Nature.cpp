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
const int N=2e5 + 10,M = 1e5 + 5;

int n,m,k,T,len,val;
int a,b,c;
int l,r,mid;

struct DSU{
	vector<int> par,sz;
	int mx;
	void init(int n){
		mx = 1;
		par.resize(n);
		sz.resize(n);
		iota(par.begin(),par.end(),0);
		fill(sz.begin(),sz.end(),1);
	}
	
	int find(int u){
		if(u == par[u]) return u;
		return par[u] = find(par[u]);
	}
	
	bool join(int a,int b){
		a = find(a);
		b = find(b);
		if(a == b) return false;
		
		if(sz[a] < sz[b])
			swap(a,b);
		par[b] = a;
		sz[a] += sz[b];
		mx = max(mx,sz[a]);
		return true;
	}
	
	
} DS;


int main(){
	
	IO
	
	while(cin>>n>>m && (n || m)){
		map<string,int> mp;
		string s,t;
		for(int i=0;i<n;++i){
			cin>>s;
			mp[s] = i;
		}
		DS.init(n);
		
		while(m--){
			cin>>s>>t;
			DS.join(mp[s],mp[t]);
		}
		
		cout<<DS.mx<<endl;
	}
	
	return 0;
}
 
