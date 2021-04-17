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
int OO=1e7;
const int N=20 + 5 ,M=(1<<10) + 1;
int x[N],y[N];
int dp[N][N][M];

int n,m,k,T;
int st,en;

int Solve(int idx,int st,int en,int mask){
	
	if(idx == n)
		return abs(::st - st) + abs(::en - en);
	
	int &ret = dp[st][en][mask];
	if(~ret)
		return ret;
	
	ret = OO;
	
	for(int i=0;i<n;++i){
		if((1<<i) & mask) continue;
		
		int val = abs(st - x[i]) + abs(en - y[i]);
		ret = min(ret, val + Solve(idx+1,x[i],y[i],mask|(1<<i)));
	}
	
	return ret;
}




int main(){
	
	scanf("%d",&T);
	while(T--){
		int u,v;
		scanf("%d%d%d%d",&u,&v,&st,&en);
		
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d%d",x+i,y+i);
		
		memset(dp,-1,sizeof dp);
		printf("The shortest path has length %d\n",Solve(0,st,en,0));
		
	}

}
