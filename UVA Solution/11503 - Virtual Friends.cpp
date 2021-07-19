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
ll OO=1e15;
const int N=2e5 + 5,M=1e4 + 100;
int par[N],sz[N];

int n,m,k,T;
int a,b,c;


struct DSU{
	
	int comp;
	
	void init(int n){
		comp = n;
		iota(par,par+n,0);
		fill(sz,sz+n,1);
	}
	
	int find(int u){
		if(u == par[u]) return u;
		return par[u] = find(par[u]);
	}
	
	bool join(int a,int b){
		a = find(a);
		b = find(b);
		if(a == b) return false;
		
		if(sz[a] < sz[b]) swap(a,b);
		
		par[b] = a;
		sz[a] += sz[b];
		--comp;
		return true;
	}
	
	int getSize(int a){
		a = find(a);
		return sz[a];
	}
	
} DS;


void Solve(int n){
	int idx = 0,a,b;
	string s1,s2;
	map<string,int> mp;
	
	while(n--){
		cin>>s1>>s2;
		if(!mp.count(s1))
			mp[s1] = idx++;
		
		if(!mp.count(s2))
			mp[s2] = idx++;
		
		a = mp[s1];
		b = mp[s2];
		
		DS.join(a,b);
		printf("%d\n",DS.getSize(a));
	}
	
	
}

int main(){

	
	IO
	cin>>T;
	while(T--){
		cin>>n;
		
		DS.init(2*n);
		
		Solve(n);
		
	}

	

	return 0;
}
 
