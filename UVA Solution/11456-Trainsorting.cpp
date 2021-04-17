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
const int N=2e3 + 5;
int arr[N];
int dpi[N][N];
int dpd[N][N];
int OO=1e9; 
 
ll n,m,k;




int SolveInc(int idx,int last){
	if(idx == n)
		return 0;
	
	int &ret = dpi[idx][last];
	if(~ret)
		return ret;
	
	ret = 0;
	ret = max(ret,SolveInc(idx+1,last));
	
	if(arr[idx] > arr[last])
		ret = max(ret,1+SolveInc(idx+1,idx));
	
	return ret;
	
}
int SolveDic(int idx,int last){
	if(idx == n)
		return 0;
	
	int &ret = dpd[idx][last];
	if(~ret)
		return ret;
	
	ret = 0;
	ret = max(ret,SolveDic(idx+1,last));
	
	if(arr[idx] < arr[last])
		ret = max(ret,1+SolveDic(idx+1,idx));
	
	return ret;
	
}

int valid(){
	int MX=0;
	
	for(int i=0;i<n;++i)
		MX=max(MX,SolveInc(i+1,i)+SolveDic(i+1,i)+1);
	
	return MX;
	
}

int main(){
	
	int T=D();
	while(T--){
		memset(dpi,-1,sizeof dpi);
		memset(dpd,-1,sizeof dpd);
		
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",arr+i);
		
		printf("%d\n",valid());
		
	}
	
	
}








