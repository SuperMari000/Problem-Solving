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
const int N=1e5 + 10,M=2*N;
int par[N],sz[N];


int n,m,k,T;
int a,b,c;
string str;

struct DSU{
	int yes,no;
	void init(int n){
		yes = no = 0;
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
		return true;
	}
	
	void same(int a,int b){
		a = find(a);
		b = find(b);
		
		yes += (a == b);
		no += (a != b);
	}
	
} DS;




int main(){

	IO
	cin>>T;
	while(T--){
		cin>>n;
		DS.init(n);
		getline(cin,str);
		while(getline(cin,str) && SZ(str)){
			char c;
			int x,y;
			
			istringstream iss(str);
			iss>>c>>x>>y;
			
			if(c == 'c')
				DS.join(x-1,y-1);
			else
				DS.same(x-1,y-1);
		}
		cout<<DS.yes<<","<<DS.no<<"\n";
		if(T)
			cout<<"\n";
	}
	
	return 0;
}
 
