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
ll OO=1e6;  
const int N=20 + 2;
bool visit[N][N];
ll dp[N][N];

int n,m,k,T;
string str;

bool valid(int i,int j){
	
	return i>-1 && j>-1 && i<n && j<m && !visit[i][j];
}


int Solve(int x,int y){
	
	if(!valid(x,y))
		return 0;
	
	if(x == n-1 && y == m-1)
		return 1;
	
	ll &ret = dp[x][y];
	
	if(~ret)
		return ret;
	
	
	
	return ret = Solve(x+1,y) + Solve(x,y+1);
}

int main(){
	
	
	cin>>T;
	while(T--){
		memset(visit,0,sizeof visit);
		memset(dp,-1,sizeof dp);
		cin>>n>>m;
		
		getchar();
		
		for(int i=0;i<n;++i){
			getline(cin,str);
			istringstream iss(str);
			int x;
			iss>>x;
			while(iss >> x)
				visit[i][x-1]=true;	
			
		}
		
		cout<<Solve(0,0)<<endl;
		if(T)
			cout<<"\n";
					
	}
	

	
}
 
 

