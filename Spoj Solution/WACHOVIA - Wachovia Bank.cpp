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
int OO=1e9;
const int N=100 + 5,M=1e3 + 5;
int arr[N],pre[N];
int dp[N][M],vis[N][M],vid;

int n,m,k,cnt,SU,idx,len,MN,MX,cur,T;
int l,r,mid;




int Solve(int idx,int cost){
	if(cost > m)
		return -OO;
	if(idx == n)
		return 0;
	int &ret = dp[idx][cost];
	int &vv = vis[idx][cost];
	if(vv == vid) return ret;
	vv = vid;
	
	ret = Solve(idx+1,cost);
	ret = max(ret, Solve(idx+1,cost + arr[idx]) + pre[idx]);
	
	return ret;
}

int main(){
	
	IO
	cin>>T;
	while(T--){
		cin>>m>>n;
		for(int i=0;i<n;++i)
			cin>>arr[i]>>pre[i];
		++vid;
		cout<<"Hey stupid robber, you can get "<<Solve(0,0)<<".\n";
	}
	
	return 0;
}
