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
int OO=1e3;
const int N=1e2 + 1,M=(1<<15) + 1;
int arr[N];
int dp[N][M];

int n,m,k,T;

int Solve(int idx,int mask){
	
	if(idx == m)
		return !mask ? 0 : OO;
	
	int &ret = dp[idx][mask];
	if(~ret)
		return ret;
	
	ret = Solve(idx+1,mask);
	ret = min(ret, 1 + Solve(idx+1,mask^arr[idx]));
	
	return ret;
}



int main(){
	
	scanf("%d",&T);
	for(int i=0;i<T;++i){
		
		memset(dp,-1,sizeof dp);
		
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;++i){
			
			int v,mask=0;
			for(int j=0;j<n;++j){
				scanf("%d",&v);
				mask |= (v<<j);
			}
			
			arr[i] = mask;
		}
		
		printf("Case %d: ",i+1);
		int val = Solve(0,(1<<n)-1);
		
		if(val > m)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",val);
		
	}


}
