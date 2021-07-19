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
ll OO=1e9 + 10;
const int N=5e3 + 5;
int par[N];
vector<int> adj[N];
set<int> best,worst;
pair<int,int> node; // First NodeID , Second MaxLen
int n,m,k;

void clr(){
	for(int i=1;i<=n;++i)
		adj[i].clear();
	
	best.clear();
	worst.clear();
	node = make_pair(1,-1);
}

void DFS(int u,int p,int curLen){
	par[u] = p;
	
	for(int v:adj[u])
		if(v != p)
			DFS(v,u,curLen+1);
	
	int &MxLen = node.second;
	
	if(curLen > MxLen){
		MxLen = curLen;
		worst.clear();
	}
	
	if(curLen == MxLen){
		node.first = u;
		worst.insert(u);
	}
}

void Solve(){
	
	int &curU = node.first,&Mx = node.second;
	
	memset(par,-1,(n+1) * sizeof(par[0]));
	DFS(curU,-1,0); // Get Start Node In Diameter
	
	memset(par,-1,(n+1) * sizeof(par[0]));
	DFS(curU,-1,0); // Get End Node In Diameter & Get First Part In Worst Node
	
	memset(par,-1,(n+1) * sizeof(par[0]));
	DFS(curU,-1,0); // Get Second Part In Worst Node
	

	int cnt = 0;
	while(~curU){ // Get Best Node Using DSU( Array par )

		if(cnt == Mx/2) best.insert(curU);
		if((Mx&1) && cnt == Mx/2 +1) best.insert(curU);
		
		curU = par[curU];
		++cnt;
	}
	
}

void Print(string str,set<int> &st){
	
	printf("%s",str.c_str());
	for(auto it=st.begin(); it != st.end(); it++)
		printf(" %d",(*it));
	puts("");
	
}


int main(){
	
	while(~scanf("%d",&n)){
		
		clr();
		
		int a,b;
		for(int i=1;i<=n;++i){
			scanf("%d",&a);
			while(a--){
				scanf("%d",&b);
				adj[i].push_back(b);
			}
		}
		
		Solve();
		
		Print("Best Roots  :",best);
		Print("Worst Roots :",worst);

		
	}
	
}


