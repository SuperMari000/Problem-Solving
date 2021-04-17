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
const int N=1e2 + 1,M=(1<<10) + 1,K=10 + 1;
int dp[N][M][K];

int n,m,k,T;

int Solve(int idx,int mask,int cur){
	
	mask|=(1<<cur);
	
	if(idx == 1)
		return mask == (1<<n)-1;
	
	int &ret = dp[idx][mask][cur];
	if(~ret)
		return ret;
		
	ret = 0;
	int nxt = cur+1;
	int prv = cur-1;
	
	if(nxt < n)
		ret += Solve(idx-1,mask,nxt);
	if(prv > -1)
		ret += Solve(idx-1,mask,prv);
		
		
	return ret = ret%MOD;
}

ll Evaluate(){
	
	ll ans = 0;
	memset(dp,-1,sizeof dp);
	
	for(int i=n;i<=m;++i){
		for(int j=1;j<n;++j)
			ans+=Solve(i,0,j);
			
		ans%=MOD;
	}
	
	return ans;
}

int main(){
	
	IO
	
	cin>>T;
	while(T--){
		cin>>n>>m;
		
		cout<<Evaluate()<<endl;
	}
	
	return 0;
}

