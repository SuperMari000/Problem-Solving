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
ll OO=1e6;
const int N=30 + 5,M=1e3 + 5;
int arr[N];
int pre[N];
ll dp[N][M];
int ans[N];

int n,m,k,len,T;
bool flage;

ll Solve(int idx,int rem){
	
	if(idx == n)
		return 0;
	
	ll &ret = dp[idx][rem];
	if(~ret)
		return ret;
	
	ret = Solve(idx+1,rem);
	
	ll val = 1ll*m*arr[idx] + 2ll*m*arr[idx];
	if(val <= rem)
		ret = max(ret,pre[idx] + Solve(idx+1,rem-val));
	
	return ret;
	
}


void Bulid(int idx,int rem){
	if(idx == n)
		return;
	
	ll ret = Solve(idx,rem);

	ll x = Solve(idx+1,rem),y=-1;
	
	ll val = 1ll*m*arr[idx] + 2ll*m*arr[idx];
	if(val <= rem)
		y = pre[idx] + Solve(idx+1,rem-val);
	
	
	if(ret == y){
		ans[T++]=idx;
		Bulid(idx+1,rem-val);
	}else
		Bulid(idx+1,rem);

}


int main(){
	
	
	while(~scanf("%d%d",&len,&m)){
		
		if(flage)
			puts("");
		
		memset(dp,-1,sizeof dp);
		T = 0;		
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d%d",arr+i,pre+i);
		
		assert((len < M && n < N));
		
		printf("%lld\n",Solve(0,len));
		Bulid(0,len);
		
		printf("%d\n",T);
		
		for(int i=0;i<T;++i)
			printf("%d %d\n",arr[ans[i]],pre[ans[i]]);
		
		flage=true;
	}
	
	
}



