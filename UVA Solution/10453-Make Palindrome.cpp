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
const int N=1e3 + 5,M=1e3 + 5;

int dp[N][N];

int n,m,k;

string str,ans;
int st,en;

int Solve(int l,int r){
	
	if(l>r)
		return 0;
	
	int &ret = dp[l][r];
	if(~ret)
		return ret;
	
	ret = OO;
	
	if(str[l] == str[r])
		ret = Solve(l+1,r-1);
	
	ret = min(ret,1+Solve(l+1,r));
	ret = min(ret,1+Solve(l,r-1));
	
	return ret;
	
}

void Bulid(int l,int r){
	
	if(l>r)
		return;
	
	int ret = Solve(l,r);
	
	if(str[l] == str[r]){
		ans[st++]=ans[en--]=str[l];
		Bulid(l+1,r-1);
		return;
	}
		
	
	int x = 1+Solve(l+1,r);
	int y = 1+Solve(l,r-1);
	
	if(x == ret){
		ans[st++]=ans[en--]=str[l];
		Bulid(l+1,r);
	}else{
		ans[st++]=ans[en--]=str[r];
		Bulid(l,r-1);
	}
	
}




int main(){
	IO
	
	while(cin>>str){
		memset(dp,-1,sizeof dp);
		
		int val = Solve(0,SZ(str)-1);
		
		ans = string(val+SZ(str),'-');
		st=0,en=val+SZ(str)-1;
		
		Bulid(0,SZ(str)-1);
		cout<<val<<" "<<ans<<endl;

	}

	
}



