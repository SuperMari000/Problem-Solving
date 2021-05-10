//       Author: Mostafa Mounir Shehab
 
#include <bits/stdc++.h>
using namespace std;
 
#define PI  acos(-1)
#define EPS (1e-9)
#define endl "\n"
#define SZ(v) (int)(v.size())
#define IO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL);
typedef long long ll;
typedef long double ld;
 
 
ll MOD=5e6;
int OO=1e8;
const int N=1e4 + 10,M=1e5 + 10;
int arr[N];
int dp[60][N];
int n,m,k,T;
int a,b,c;
string s,t;

struct BIT{
	ll Tree[M];
	void init(){
		memset(Tree,0,sizeof Tree);
	}
	
	void add(int idx,ll val){		
		while(idx < M){
			Tree[idx] += val;
			idx += (idx & -idx);
		}
	}
	
	ll get(int idx){
		ll ret = 0;
		while(idx){
			ret += Tree[idx];
			idx -= (idx & -idx);
		}
		return ret;
	}
	
	
} bit;


 
int main() {
	IO
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>arr[i];
		++arr[i];
	}
	bit.init();	
	
	for(int i=0;i<n;++i)
		dp[1][i] = 1;
		
	for(int lvl = 2;lvl <= m; ++lvl){
		
		for(int i=0;i<n;++i){
			dp[lvl][i] = bit.get(arr[i] - 1) % MOD;
			bit.add(arr[i],dp[lvl - 1][i]);
		}
		
		for(int i=0;i<n;++i)
			bit.add(arr[i],-dp[lvl - 1][i]);
	}
	
	int ans = 0;
	for(int i=0;i<n;++i){
		ans += dp[m][i];
		ans %= MOD;
	}

	
	cout<<ans<<endl;
    return 0;
}   
