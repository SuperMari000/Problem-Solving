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
ll OO=1e15;
const int N=1e3 + 5,M=30 + 1;
int pre[M];
int arr[M];
int col[M];
ll dp[M][N];

ll n,m,k;
bool flage;

vector<ll> vec;

ll Solve(int idx,int rem){
	
	if(idx == n)
		return 0;
	
	ll &ret = dp[idx][rem];
	if(~ret)
		return ret;
	
	ret = Solve(idx+1,rem-col[idx]*5);
	
	ll st=arr[idx],def=pre[idx],val=0;
	while(rem >= 5){
		val += st;
		st-=def;
		rem-=5;
		ret = max(ret, val + Solve(idx+1,rem - col[idx]*5));
		st = (st <=0) ? 0 : st;
	}
	
	return ret;
}


void Bulid(int idx,int rem){
	
	if(idx == n)
		return;
	
	ll ret = Solve(idx,rem);
	
	ll init=Solve(idx+1,rem-col[idx]*5);
	ll bestrem=rem,bestlen=0;
	
	ll st=arr[idx],def=pre[idx],val=0,len=0;
	while(rem >= 5){
		++len;
		val += st;
		st-=def;
		rem-=5;
		init = val + Solve(idx+1,rem - col[idx]*5);
		st = (st <=0) ? 0 : st;
		if(init == ret){
			bestlen = len*5;
			bestrem = rem;
		}
	}
	vec.push_back(bestlen);
	Bulid(idx+1,bestrem - col[idx]*5);
}

int main(){
	IO
	
	while(scanf("%d",&n) && n){
		
		if(flage)
			puts("");
		
		memset(dp,-1,sizeof dp);
		vec.clear();
		scanf("%d",&m);
		m*=60;
		for(int i=0;i<n;++i)
			scanf("%d",arr+i);
		
		for(int i=0;i<n;++i)
			scanf("%d",pre+i);
		
		for(int i=0;i<n-1;++i)
			scanf("%d",col+i);
		
		ll val = Solve(0,m);
		Bulid(0,m);
		while(SZ(vec) < n)
			vec.push_back(0);
		for(int i=0;i<SZ(vec)-1;++i)
			printf("%lld, ",vec[i]);
		printf("%lld\n",vec.back());
		
		printf("Number of fish expected: %lld\n",val);
		
		flage=true;
	}
	
}


