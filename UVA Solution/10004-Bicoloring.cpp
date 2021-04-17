//        Mostafa Mounir Shehab
 
#include <bits/stdc++.h>
using namespace std;
 
#define PI  3.14159265  // PI = acos(-1)
#define EPS (1e-10)
#define endl "\n"
#define SZ(v) (int)(v.size())
typedef long long ll;
typedef long double ld;
//template <class Type>
 
inline int D(){
	int t;
	scanf("%d",&t);
	return t;
}
inline ll llD(){
	ll t;
	scanf("%lld",&t);
	return t;
}
 
 
ll MOD=1e9 + 7; 
const int N=1e3+ 1;
int visit[N];


int n,m,k,a,b;





int main(){
	
	
	while(scanf("%d",&n) && n){
		
		vector<int> adj[N];
		memset(visit,-1,sizeof(visit));	
		bool flage=true;
		
		scanf("%d",&m);
		for(int i=0;i<m;++i){
			scanf("%d%d",&a,&b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		queue<int> q;
		q.push(0);
		visit[0]=0;
		
		while(SZ(q)){
			
			int cur=q.front();
			q.pop();
			
			for(int i:adj[cur]){
				if(visit[i] == -1)
					q.push(i),visit[i]=visit[cur]^1;
				
				flage&=(visit[i] != visit[cur]);
			}
				
					
		}
		
		
		puts(flage ? "BICOLORABLE.":"NOT BICOLORABLE.");
		
	}
	
	
	

 
}
 
 
 
 
 
 
 
