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
const int N=2e5 + 5,M=(1<<8) + 1;
int arr[N];
 
int n,m,k,T;
int a,b,c;

struct SparseTable{
	
	//const static int N = 1e5 + 5;
	int sp[N][20],LOG[N];
	
	void init(){
		for(int i=2;i<N;++i)
			LOG[i] += LOG[i-1] + !(i&(i-1));
	}
	
	void Build(){ // O( n log(n) )
		int lg = LOG[n];
		for(int i=0;i<n;++i)
			sp[i][0] = arr[i];
		
		for(int j=1;j<=lg;++j)
			for(int i=0;i + (1<<j) <= n;++i)
				sp[i][j] = max(sp[i][j-1],sp[i + (1<<(j-1))][j-1]);
			
	}
	
	int Query(int l,int r){ // O(1)
		int len = r-l+1;
		int lg = LOG[len];
		return max(sp[l][lg],sp[r - (1<<lg) + 1][lg]);
	}
	
	
} SP;


 
int main() {
	IO
	cin>>n>>T;
	for(int i=0;i<n;++i)
		cin>>arr[i];
	SP.init();
	SP.Build();
	
	int l,r,cnt = 0;
	while(T--){
		cin>>l>>r;
		--l,--r;
		
		if(l == r) ++cnt;
		else cnt += (SP.Query(l,r-1) <= arr[l]);
	}
	
	cout<<cnt<<endl;
		
	
    return 0;
} 
