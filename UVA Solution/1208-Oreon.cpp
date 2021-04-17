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

vector<pair<int,pair<char,char>>> adj;

struct DSU{
	vector<int> par,sz;
	
	void init(int n){
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

		return true;
	}
	
	void MST(int test){
		cout<<"Case "<<test<<":\n";

		sort(adj.begin(),adj.end());		
		for(auto it:adj)
			if(join(it.second.second-'A',it.second.first-'A'))
				cout<<it.second.first<<"-"<<it.second.second<<" "<<it.first<<"\n";
	}
	
	
} DS;

int strToint(string &str){
	int ret = 0;
	for(char i:str){
		if(i >= '0' && i<='9'){
			ret *= 10;
			ret += i-'0';
		}
	}
	return ret;
}

void Read(int n){
	adj.clear();
	string str;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>str;
			
			if(j <= i) continue;
			
			int a = strToint(str);
			if(a)
				adj.push_back(make_pair(a,make_pair('A' + i,'A' + j)));
		}

	}
	
}

int main(){
	
	IO
	
	cin>>T;
	for(int i=1;i<=T;++i){
		cin>>n;
		Read(n);
		DS.init(n);
		DS.MST(i);
	}
	
	return 0;
}
 
