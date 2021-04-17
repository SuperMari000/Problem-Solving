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
const int N=12 + 1 ,M=(1<<N) + 1;
char str[N];
int dp[M];

int n,m,k,T;

int Solve(int mask,int sz){
	
	int &ret = dp[mask];
	if(~ret)
		return ret;
	
	ret = 0;
	for(int i=1;i<sz-1;++i){
		
		int a = i-1, b = i, c = i+1;
		
		if(((1<<a)&mask) && ((1<<b)&mask) && !((1<<c)&mask)){
			int val = mask;
			val^=(1<<a);
			val^=(1<<b);
			val|=(1<<c);
			ret = max(ret, 1 + Solve(val,sz));
		}
			
		if(!((1<<a)&mask) && ((1<<b)&mask) && ((1<<c)&mask)){
			int val = mask;
			val|=(1<<a);
			val^=(1<<b);
			val^=(1<<c);
			ret = max(ret, 1 + Solve(val,sz));
		}
	}
	
	return ret;
}



int main(){

	scanf("%d",&T);
	for(int i=0;i<T;++i){
		
		scanf("%s",str);
		
		int mask = 0, cnt = 0, sz = 12;
		for(int i=0;i<str[i];++i){
			if(str[i] == 'o')
				mask |= (1<<i);

			cnt += (str[i] == 'o');
		}
		
			
		memset(dp,-1,sizeof dp);
		printf("%d\n",cnt - Solve(mask,sz));
	}


}
