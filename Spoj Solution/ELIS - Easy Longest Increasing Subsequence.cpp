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
int OO=1e8;
const int N=1e2 + 5,M= N << 1;
int dp[N][N],arr[N];

int n,m,k,SU,idx,len,MN,MX,T;
int l,r,mid;
int a,b,c;


 
int main(){
	IO
	//freopen("in.txt","r",stdin);

	cin>>n;
	for(int i=0;i<n;++i){
		cin>>arr[i];
		dp[i][i] = 1;
	}
	int ans = 0;
	for(int i=0;i<n;++i){
		int &ret = dp[i][i];
		for(int j=0;j<i;++j)
			if(arr[i] > arr[j])
				ret = max(ret,dp[j][j] + 1);
		ans = max(ans,dp[i][i]);
	}
	cout<<ans<<endl;
	
	return 0;
}
