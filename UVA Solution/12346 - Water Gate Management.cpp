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
ll OO=1e15;
const int N=1e2 + 5;
ll arr[N];
ll pre[N];


ll n,m,k,cnt;
ll a,b,c,d;


ll Solve(int idx,ll cost,ll val){
	
	
	if(idx == n)
		return (val <= 0) ? cost : OO;

	
	ll x = Solve(idx+1,cost,val);
	ll y = Solve(idx+1,cost+pre[idx],val-b*arr[idx]);
	

	return min(x,y);
	
	
}





int main(){
	
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>arr[i]>>pre[i];
	
	cin>>m;
	for(int i=0;i<m;++i){
		cin>>a>>b;
		cnt = Solve(0,0,a);
		
		if(cnt == OO)
			cout<<"Case "<<i+1<<": "<<"IMPOSSIBLE"<<endl;
		else
			cout<<"Case "<<i+1<<": "<<cnt<<endl;
		
	}



}



