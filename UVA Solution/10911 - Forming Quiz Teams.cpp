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
const int N=16 ,M=(1<<N) + 1;
int X[N],Y[N];
double dp[M];
int vis[M];

int n,m,k,T;
string str;

double Solve(int mask){

	if(mask == (1<<n)-1)
		return 0;
	
	double &ret = dp[mask];
	if(vis[mask] == T)
		return ret;
	
	vis[mask] = T;
	ret = 1e7;
	
	for(int i=0;i<n;++i){
		if(mask & (1<<i))
			continue;
		
		for(int j=0;j<n;++j){
			if(i == j || (mask & (1<<j))) continue;
			int st = (X[i] - X[j]) * (X[i] - X[j]);
			int en = (Y[i] - Y[j]) * (Y[i] - Y[j]);
			double val = sqrt(st + en);
			
			ret = min(ret,val + Solve(mask|(1<<i)|(1<<j)));
			
		}
	}
	
	return ret;
}


int main(){
	
	IO
	
	while(cin>>n && n){
		n<<=1;
		for(int i=0;i<n;++i)
			cin>>str>>X[i]>>Y[i];
			
		++T;
		cout<<"Case "<<T<<": "<<fixed<<setprecision(2)<<Solve(0)<<"\n";
		
	}
	
}
