//        Author: Mostafa Mounir Shehab
 
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
const int N=1e6 + 5;
int arr[N];

ll n,m,k,cnt,SU;



int main(){
	
	while(scanf("%lld",&n) && n ){
		cnt=SU=0;
		priority_queue<int> pr;
		
		while(n--){
			scanf("%lld",&m);
			pr.push(-m);
		}
			
		while(pr.size() > 1){
			SU=-pr.top();
			pr.pop();
			
			SU+=-pr.top();
			pr.pop();
			
			pr.push(-SU);
			cnt+=SU;

		}
		
		printf("%lld\n",cnt);
	}

}
 
 

 
 
 
 
 
 
 
