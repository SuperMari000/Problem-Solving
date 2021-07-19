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
ll OO=1e7;
const int N=14,M=(1<<N)+ 1;
int X[N],Y[N];
int dp[M][N][2];
int vis[M][N][2];

int n,m,k,T;
int a,b,c,d;

int Solve(int idx,int mask,int last,bool rev){
	
	if(idx == n)
		return last == c;
	
	int &ret = dp[mask][last][rev];
	int &v = vis[mask][last][rev];
	if(v == T)
		return ret;
	
	v = T;
	ret = 0;
	
	for(int i=0;i<m;++i){
		if(mask & (1<<i)) continue;
		
		if(X[i] == last)
			ret |= Solve(idx+1,mask | (1<<i),Y[i],false);
		if(Y[i] == last)
			ret |= Solve(idx+1,mask | (1<<i),X[i],true);
		
	}
	
	return ret;
}





int main(){

	
	while(scanf("%d%d",&n,&m) && n){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		
		for(int i=0;i<m;++i)
			scanf("%d%d",X+i,Y+i);
		
		++T;
		puts(Solve(0,0,b,false) ? "YES" : "NO");
	}

}
