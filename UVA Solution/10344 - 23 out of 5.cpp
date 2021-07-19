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
const int N=1e1+ 5;
int arr[N];


ll n,m,k;

bool Solve(int idx,int sum){
	
	if(idx == n)
		return sum == 23;
	
	return Solve(idx+1,sum + arr[idx]) || 
		   Solve(idx+1,sum - arr[idx]) || 
		   Solve(idx+1,sum * arr[idx]);	
	
}


bool readNum(){
	int num=0;
	for(int i=0;i<n;++i)
		scanf("%d",arr+i),num+=arr[i];
	
	return num > 0;
}


int main(){
	
	n = 5;
	
	while(readNum()){
		
		sort(arr,arr+n);
		
		bool flage=false;
		
		do{
			
			flage|=Solve(1,arr[0]);
			
		}while(next_permutation(arr,arr+n) && !flage);
		
		
		puts(flage ? "Possible" : "Impossible");
		
	}
		

	

 
}
 
 
 
 
 
 
 
