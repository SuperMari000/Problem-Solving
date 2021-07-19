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
const int N=2e5 + 100,M=2*N;
 
int n,m,k,T;
int a,b,c;
int ans;
map<int,vector<int>> adj; 
map<int,int> mp;
map<int,bool> vis;
void clr(){
	adj.clear();
	mp.clear();
	vis.clear();
}


bool DFS(int u){
	vis[u] = true;
	bool flage = false;
	
	if(!SZ(adj[u])) return flage;
	
	for(int i:adj[u])	
		flage |= (vis[i] ? true : DFS(i));
	
	return flage;
}


bool valid(){
	if(!SZ(mp)) return true;
	
	int u = -1;
	for(auto it:mp)
		if(!it.second)
			u = it.first;
	
	if(!~u) return false;
	
	if(DFS(u)) return false;
	
	for(auto it:mp)
		if(!vis.count(it.first))
			return false;
	return true;
}



int main(){
	IO
	int ID =1;
	while(true){
		clr();
		while(cin>>a>>b && a > 0 && b > c){
			adj[a].push_back(b);
			++mp[b];
			if(!mp.count(a)) mp[a] = 0;
		}
		
		if(a<0 && b<0) break;
		
		cout<<"Case "<<ID++<<" "<<(valid() ? "is a tree." : "is not a tree.")<<"\n";
		
		
	}
	
	return 0;
}

