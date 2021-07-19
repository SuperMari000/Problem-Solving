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
const int N=1e3 + 10,M = 1e5 + 5;
int par[N],sz[N];

int n,m,k,T,len,val;
int a,b,c;
int l,r,mid;

struct DSU{
	vector<pair<int,int>> ans,town;
	vector<pair<double,pair<int,int>>> vec;
	int comp;
	void init(int n){
		vec.clear();
		ans.clear();
		town.clear();
		comp = n;
		iota(par,par+n,0);
		fill(sz,sz+n,1);
	}
	
	int find(int u){
		if(u == par[u]) return u;
		return par[u] = find(par[u]);
	}
	
	bool join(int a,int b){
		a = find(a), b = find(b);
		
		if(a == b) return false;
		
		if(sz[a] < sz[b]) 
			swap(a,b);
			
		par[b] = a;
		sz[a] += sz[b];
		--comp;
		
		return true;
	}
	
	void readTown(int n){
		int a,b;
		while(n--){
			cin>>a>>b;
			town.push_back(make_pair(a,b));
		}
	}
	
	void readRoad(int n){
		int a,b;
		while(n--){
			cin>>a>>b;
			join(a-1,b-1);
		}
	}
	
	void bulidRoad(){
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j){
				double dx = town[i].first - town[j].first;
				double dy = town[i].second - town[j].second;
				double val = hypot(dx,dy);
				
				vec.push_back(make_pair(val,make_pair(i,j)));
			}
		}
	}
	
	void MST(){
		if(comp == 1){
			cout<<"No new highways need\n";
			return;
		}
		
		sort(vec.begin(),vec.end());
		
		for(auto it:vec)
			if(join(it.second.first,it.second.second))
				ans.push_back(it.second);
		
		
		for(auto it:ans)
			cout<<it.first+1<<" "<<it.second+1<<"\n";
		
	}
	
	
} DS;


int main(){
	
	IO
	
	cin>>T;
	for(int i=1;i<=T;++i){
		cin>>n;
		DS.init(n);
		DS.readTown(n);
		
		cin>>m;
		DS.readRoad(m);
		
		DS.bulidRoad();
		DS.MST();
		
		if(i != T)
			cout<<"\n";
		
	}

	
	return 0;
}
 
