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
const int N=1e2+ 1,alpha=26;
char arr[N];
bool visit[alpha];
vector<int> adj[alpha];


int n,m,k,cnt;
int a,b;


void DFS(int u){
	visit[u]=true;
	for(int i:adj[u])
		if(!visit[i])
			DFS(i);
	++cnt;
}



int main(){


	int T=D();
	while(T--){
		a=b=0;
		
		while(scanf("%s",arr) && arr[0]!='*'){
			adj[arr[1]-'A'].push_back(arr[3]-'A');
			adj[arr[3]-'A'].push_back(arr[1]-'A');
		}

		scanf("%s",arr);
		for(int i=0;arr[i];++i){
			cnt=0;
			if(isalpha(arr[i]) && !visit[arr[i]-'A']){
				DFS(arr[i]-'A');
				a+=(cnt > 1),b+=(cnt == 1);
			}
				
		}
		
		printf("There are %d tree(s) and %d acorn(s).\n",a,b);
		
		for(int i=0;i<alpha;++i)
			adj[i].clear();
		memset(visit,0,sizeof(visit));

	}
	
	
	
	

 
}
 
 
 
 
 
 
 
