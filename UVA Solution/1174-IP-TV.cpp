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
const int N=2e3 + 10,M = 1e5 + 5;
int par[N],sz[N];

int n,m,k,T;


struct DSU{
	vector<pair<int,pair<int,int>>> vec;
	int comp;
	ll SU;
	void init(int n){
		comp = n;
		SU = 0;
		vec.clear();
		iota(par,par+n,0);
		fill(sz,sz+n,1);
	}
	
	int find(int u){
		if(u == par[u]) return u;
		return par[u] = find(par[u]);
	}
	
	bool join(int a,int b,int val){
		a = find(a);
		b = find(b);
		if(a == b) return false;
		
		if(sz[a] < sz[b]) 
			swap(a,b);
		par[b] = a;
		sz[a] += sz[b];
		SU += val;
		
		return true;
	}
	
	void read(int n){
		int cost,idx = 0;
		string s,t;
		map<string,int> mp;
		while(n--){
			cin>>s>>t>>cost;
			if(!mp.count(s))
				mp[s] = idx++;
			if(!mp.count(t))
				mp[t] = idx++;
			
			vec.push_back(make_pair(cost,make_pair(mp[s],mp[t])));
		}
	}
	
	ll MST(){
		
		sort(vec.begin(),vec.end());
		for(auto it:vec)
			join(it.second.first,it.second.second,it.first);
		
		return SU;
	}
	
} DS;

int main(){
	
	IO
	
	cin>>T;
	for(int i=1;i<=T;++i){
		cin>>n;
		DS.init(n);
		cin>>m;
		DS.read(m);
		cout<<DS.MST()<<"\n";
		
		if(i != T) cout<<"\n";
	}

	
	return 0;
}
 
