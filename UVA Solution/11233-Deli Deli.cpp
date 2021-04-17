//       Author: Mostafa Mounir Shehab
 
#include <bits/stdc++.h>
using namespace std;
 
#define PI  acos(-1)
#define EPS (1e-10)
#define endl "\n"
#define SZ(v) (int)(v.size())
#define IO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL);
typedef long long ll;
typedef long double ld;
 
 
 
ll MOD=1e9 + 7;
ll OO=1e7+7;
const int N=1e1 + 5,M = N << 1,K = 5;
char arr[N][N];
int vis[N][N];
 
int n,m,k,cnt,SU,idx,len,T,lg;
int a,b,c,x,y;



map<string,string> mp;
string Solve(string &s){
	if(mp.count(s))
		return mp[s];
	
	char ch1 = s.back();
	char ch2 = s[SZ(s)-2];
	
	if(ch1 == 'y' && ch2 != 'a' && ch2 != 'e' && ch2 != 'i' && ch2 != 'o' && ch2 != 'u'){
		s.pop_back();
		s += "ies";
		return s;
	}
	if(ch1 == 'o' || ch1 == 's' || ch1 == 'x'){
		s += "es";
		return s;
	}
	
	if(ch1 == 'h' && (ch2 == 's' || ch2 == 'c')){
		s += "es";
		return s;
	}
	s += 's';
	return s;
}


int main(){
	
	IO
	cin>>n>>T;
	string s,t;
	while(n--){
		cin>>s>>t;
		mp[s] = t;
	}
	
	while(T--){
		cin>>s;
		cout<<Solve(s)<<endl;
	}
	
	
	return 0;
}

