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
const int N=2e5 + 5;
 
ll n,m,k;

queue<int> q;




int main(){
	while(scanf("%lld",&n) && n){
		for(int i=1;i<=n;++i)
			q.push(i);
		
		printf("Discarded cards:");
		
		while(q.size()>1){
			printf(" %d",q.front());
			q.pop();
			
			q.push(q.front());
			q.pop();
			
			if(q.size()>1)
				printf(",");
		}
		
		printf("\nRemaining card: %d\n",q.front());
		q.pop();
		
		
	}

	
}
 
 
 
 
 
 
