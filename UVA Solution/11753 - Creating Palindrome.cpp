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
int OO=1e6;  
const int N=1e4 + 5;
int arr[N];
 
int n,m,k,cnt,T;


int Solve(int x,int y,int len){
	
	if(len > k)
		return OO;
	
	if(x >= y)
		return len;
	
	
	if(arr[x] == arr[y])
		return Solve(x+1,y-1,len);
		
	int a = Solve(x+1,y,len+1);
	int b = Solve(x,y-1,len+1);
	
	return min(a,b);
	
}




int main(){
	
	scanf("%d",&T);
	for(int h=0;h<T;++h){
		
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;++i)
			scanf("%d",arr+i);
		
		cnt = Solve(0,n-1,0);
	
	
		if(!cnt)
			printf("Case %d: Too easy\n",h+1);
		else if(cnt > k)
			printf("Case %d: Too difficult\n",h+1);
		else
			printf("Case %d: %d\n",h+1,cnt);
		
		
	}

	
	

	
	
}
 

 
