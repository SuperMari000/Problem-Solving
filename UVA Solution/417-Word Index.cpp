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
const int N=1e1 + 5;
char arr[N];

ll n,m,k,cnt,idx;


string key;
map<string,ll> mp;
queue<string> q;

int main(){

	key="";
	for(char i='a';i<='z';++i)
		q.push(key+i);
		
	while(q.size() + cnt < 83681){
		
		key=q.front();
		mp[key]=++cnt;
		q.pop();
		
		char idx=char(key.back()+1);
		while(idx<='z'){
			q.push(key+idx);
			++idx;
		}
		
	}	
	while(!q.empty())
		mp[q.front()]=++cnt,q.pop();
	
	
	while(scanf("%s",arr) != EOF){
		key=arr;
		printf("%lld\n",mp[key]);
	}
		

}
 
 
 
 
 
 
 
 
 
 
