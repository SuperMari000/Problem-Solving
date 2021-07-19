//        Mostafa Mounir Shehab
 
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
ll arr[N];
 
 
ll n,op,val;

int main(){
	while(scanf("%lld",&n) != EOF){
		
		bool isS=true,isQ=true,isPQ=true;
		stack<ll> st;
		queue<ll> q;
		priority_queue<ll> pr;
		
		while(n--){
			scanf("%lld%lld",&op,&val);
			
			if(op == 1){
				pr.push(val);
				q.push(val);
				st.push(val);
			}else{
				if(st.empty() || st.top()!=val)
					isS=false;
				if(q.empty() || q.front()!=val)
					isQ=false;
				if(q.empty() || pr.top()!=val)
					isPQ=false;
				
				if(!st.empty()){
					pr.pop();
					q.pop();
					st.pop();
				}
			}
			
		}
		
		if(isS && !isQ && !isPQ)
			puts("stack");
		else if(!isS && isQ && !isPQ)
			puts("queue");
		else if(!isS && !isQ && isPQ)
			puts("priority queue");
		else if(!isS && !isQ && !isPQ)
			puts("impossible");
		else
			puts("not sure");
	
		
	}
	


	

	


		
	
		
	
}
 
 
