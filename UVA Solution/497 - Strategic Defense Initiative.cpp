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
 
 
ll MOD=998244353; 
const int N=1e3 + 3;
int arr[N];
int dp[N][N];
int OO=1e6; 
 
ll n,m,k,T;

string str;


int Solve(int idx,int last){
		
	if(idx == n)
		return 0;
	
	int &ret = dp[idx][last];
	if(~ret)
		return ret;
	
	int x=0,y=0;
	if(arr[idx] > arr[last])
		x = 1 + Solve(idx+1,idx);
	
	y = Solve(idx+1,last);
	
	
	return ret = max(x,y);
}

void Print(int idx,int last){
	
	if(idx == n)
		return;
	
	int x=0,y=0;
	if(arr[idx] > arr[last])
		x = 1 + Solve(idx+1,idx);
	
	y = Solve(idx+1,last);
	
	int val = Solve(idx,last);
	

	if(x == val && val){
		cout<<arr[idx]<<"\n";
		Print(idx+1,idx);
	}else
		Print(idx+1,last);


}



 
int main(){
	
	
	cin>>T;
	getchar();
	getchar();
	while(T--){
		n=0;
		arr[n++]=-1;
		while(getline(cin,str) && SZ(str)){
			istringstream iss(str);
			iss >> arr[n++];
		}

		memset(dp,-1,sizeof dp);
		cout<<"Max hits: "<<Solve(0,0)<<endl;
		Print(0,0);
		
		if(T)
			cout<<"\n";
		
	}
	



}




