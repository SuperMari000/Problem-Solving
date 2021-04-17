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
ll OO=1e7+7;
const int N=1e1 + 5,M = N << 1,K = 5;
char arr[N][N];
int vis[N][N];
 
int n,m,k,cnt,SU,idx,len,T,lg;
int a,b,c,x,y;

bool valid(int x,int y){
	return ~x && ~y && x < n && y < m;
}

void BFS(){
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			vis[i][j] = OO;
	
	int x = 0,y = k-1;
	vis[x][y] = 0;
	
	while(true){
		
		int u = x,v = y;
		if(arr[x][y] == 'N')
			--u;
		else if(arr[x][y] == 'S')
			++u;
		else if(arr[x][y] == 'E')
			++v;
		else
			--v;
		
		if(!valid(u,v)){
			printf("%d step(s) to exit\n",vis[x][y]+1);
			return;
		}
		if(vis[x][y] + 1 > vis[u][v]){
			printf("%d step(s) before a loop of %d step(s)\n",vis[u][v],vis[x][y] - vis[u][v] + 1);
			return;
		}
		
		vis[u][v] = vis[x][y] + 1;
		x = u,y = v;
	}
}


int main(){
	
	
    while(scanf("%d%d%d",&n,&m,&k) && (n || m || k)){
    	for(int i=0;i<n;++i)
    		scanf("%s",arr+i);
    	
		BFS();
	}
	
	return 0;
}

