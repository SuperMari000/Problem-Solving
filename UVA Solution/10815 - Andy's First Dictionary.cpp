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
const int N=1e3 + 5;
char arr[N];

map<char,set<string>> mp;
string str;



 
 
int main(){
	
	while(scanf("%s",arr) != EOF){
		
		for(int i=0;arr[i];++i){
			if(isalpha(arr[i]))
				str+=tolower(arr[i]);
			else if(SZ(str))
				mp[str[0]].insert(str),str="";
		}
		
		if(SZ(str))
			mp[str[0]].insert(str);
			
		str="";
	}
		
	
	for(auto i:mp)
		for(auto it=i.second.begin();it!=i.second.end();it++)
			printf("%s\n",(*it).c_str());
	
		
	
}
 
