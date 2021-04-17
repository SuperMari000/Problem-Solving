//       Author: Mostafa Mounir Shehab
 
#include <bits/stdc++.h>
using namespace std;
 
#define PI  3.14159265  // PI = acos(-1)
#define EPS (1e-10)
#define endl "\n"
#define SZ(v) (int)(v.size())
typedef long long ll;
typedef long double ld;
//template <class Type>
 
 
void Fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
}
 
inline int D(){
	int t;
	scanf("%d",&t);
	return t;
}
inline ll llD(){
	ll t;
	scanf("%lld",&t);
	return t;
}
 
 
ll MOD=1e9 + 7;
int OO=1e9;
const int N=1e2 + 5;
int arr[N][N];
int pre[N][N];
int dp[N][N];


ll n,m,k;


bool valid(int x,int y){
	return x>-1 && y>-1 && x<n && y<n;
}

int Solve1(int x,int y){
	
	if(!valid(x,y))
		return 0;
	
	int &ret = pre[x][y];
	if(ret != -OO)
		return ret;
	
	
	ret =  Solve1(x+1,y) + Solve1(x,y+1) - Solve1(x+1,y+1) + arr[x][y];
	
	return ret;
	

}

int Solve(int x,int y){
	
	if(!valid(x,y))
		return -OO;
	
	int &ret = dp[x][y];
	if(ret != -OO)
		return ret;
		
	ret = -OO;
	for(int i=x;i<n;++i)
		for(int j=y;j<n;++j)
			ret = max(ret , Solve1(x,y) + Solve1(i+1,j+1) - Solve1(i+1,y) - Solve1(x,j+1));

	
	return ret = max({ret,Solve(x+1,y),Solve(x,y+1)});
	
}


int main(){
	
	while(scanf("%lld",&n) != EOF){
		
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				pre[i][j]=dp[i][j]=-OO;

		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				cin>>arr[i][j];
		
		Solve1(0,0);
	
		printf("%d\n",Solve(0,0));
		
	}
	
	
	

}





