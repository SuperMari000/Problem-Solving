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
const int N=1e2 + 5,M = N << 1,K = 5;
char arr[N][N];
int vis[N][N],vid;
 
int n,m,k,cnt,SU,idx,len,T,lg;
int a,b,c,x,y;


bool valid(int x,int y){
	return ~x && ~y && x < n && y < m;
}
void DFS(int u,int v){
	if(!valid(u,v) || vis[u][v] == vid || arr[u][v] != '@')
		return;
	vis[u][v] = vid;
	for(int i=-1;i<=1;++i)
		for(int j=-1;j<=1;++j)
			DFS(u+i,v+j);

}


int main(){
	
	
    while(scanf("%d%d",&n,&m) ,n , m){
    	for(int i=0;i<n;++i)
    		scanf("%s",arr+i);
    	++vid;
    	int cnt = 0;
    	for(int i=0;i<n;++i){
    		for(int j=0;j<m;++j){
    			if(arr[i][j] == '@' && vis[i][j] != vid){
    				DFS(i,j);
    				++cnt;
				}
			}
		}
    	
    	printf("%d\n",cnt);
	}
	return 0;
}


