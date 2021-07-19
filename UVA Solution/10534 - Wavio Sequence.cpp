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
const int N=1e4 + 4;
int vis[N];
int arr[N];

int n,m,k;

vector<int> lis(){
	int idx=0;
	vector<int> v;
	
	v.push_back(0);
	vis[idx++]=arr[0];
	
	for(int i=1;i<n;++i){
		
		int len = lower_bound(vis,vis+idx,arr[i])-vis;
		
		if(arr[i] < vis[0]){
			
			v.push_back(0);
			vis[0]=arr[i];
			
		}else if(arr[i] > vis[idx-1]){
			
			v.push_back(idx);
			vis[idx++]=arr[i];
			
		}else{
			
			v.push_back(len);
			vis[len]=arr[i];
			
		}
		
	}
	return v;
	
}


int main(){
	
	while(scanf("%d",&n) != EOF){

		for(int i=0;i<n;++i)
			scanf("%d",arr+i);
		
		
		vector<int> in = lis();
		reverse(arr,arr+n);
		vector<int> de = lis();
		
		
		int MX=1,MN;
		for(int i=0;i<n;++i){
			MN = 2*min(in[i] , de[n-i-1]);
			MX = max(MX , MN+1);
		}
		
		printf("%d\n",MX);
		
		
	}
	
	
	
 
}


