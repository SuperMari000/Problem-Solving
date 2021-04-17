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
const int N=1e2 + 5;
char arr[N];
char cop[N];

ll n,m,k;


string key,val;

void print(char x,set<string> &st){
	if(!SZ(st))
		return;
	string str="";
	str+=x;
	for(auto it=st.begin();it!=st.end();it++)
		str+=(*it)+',';
		
	str.pop_back();
	printf("%s\n",str.c_str());
}



int main(){
	int T=D();
	while(T--){
		
		scanf("%s",arr);
		scanf("%s",cop);
		
		map<string,string> mp;
		set<string> plus,mins,star;
		
		key=val="";
		for(int i=0;arr[i];++i){
			
			if(isalpha(arr[i]))
				key+=arr[i];
			if(isdigit(arr[i]))
				val+=arr[i];
				
			if(arr[i] == ',' || (arr[i] == '}' && SZ(key)))
				mp[key]=val,key=val="";
		}
		
		key=val="";
		for(int i=0;cop[i];++i){
			
			if(isalpha(cop[i]))
				key+=cop[i];
			if(isdigit(cop[i]))
				val+=cop[i];
				
			if(cop[i] == ',' || (cop[i] == '}' && SZ(key))){
				if(!SZ(mp[key]))
					plus.insert(key);
				else if(mp[key] != val)
					star.insert(key);
				mp[key]="";
				key=val="";
			}
		}
		
		for(auto i:mp)
			if(SZ(i.second))
				mins.insert(i.first);
		
		if(!SZ(plus) && !SZ(mins) && !SZ(star))
			puts("No changes");
		else
			print('+',plus),print('-',mins),print('*',star);
		
		
		puts("");
		
	}


	
}
 
 
 
 
 
 
 
 
 
 
