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
int OO=1e6;
const int N=10 + 2,M=1e3 + 10;
char arr[N],pre[N];
bool vis[M],instack[M];
int dfsn[M],low[M];

int n,m,k,T;
int a,b,c;

vector<int> adj[M];
stack<int> st;
int Time;

void clr(int n){
	for(int i=0;i<n;++i){
		adj[i].clear();
		instack[i] = vis[i] = false;
	}
	st = stack<int>();
	Time = 1;
}

void Tarjan(int u){
	vis[u] = instack[u] = true;
	dfsn[u] = low[u] = Time++;
	st.push(u);
	
	for(int i:adj[u]){
		if(!vis[i]){
			Tarjan(i);
			low[u] = min(low[u],low[i]);
		}else if(instack[i])
			low[u] = min(low[u],low[i]);
	}
	
	if(low[u] == dfsn[u]){
		while(st.top() != u){
			instack[st.top()] = false;
			st.pop();
		}
		
		instack[st.top()] = false;
		st.pop();	
		
		
	}
	
}


int valid(){
	for(int i=0;i<n;++i)
		if(!vis[i])
			Tarjan(i);
	
	int ans = 0;
	for(int i=0;i<n;++i)
		ans += (low[i] == dfsn[i]);
		
	return ans;
}

int main(){
	
	while(scanf("%d%d",&n,&m) && (n || m)){
		map<string,int> mp;
		clr(n);
		for(int i=0;i<n;++i){
			scanf("%s %s",arr,pre);
			string str = arr;
			str += pre;
			mp[str] = i;
		}
		
		while(m--){
			scanf("%s %s",arr,pre);
			string from = arr;
			from += pre;
			scanf("%s %s",arr,pre);
			string to = arr;
			to += pre;
			adj[mp[from]].push_back(mp[to]);
		}
		
		printf("%d\n",valid());
	}
	
	


		
}
 
