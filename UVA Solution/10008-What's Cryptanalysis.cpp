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
const int N=50 + 5,M = N << 1,K = 5;
 
int n,m,k,cnt,SU,idx,len,T,lg;
int a,b,c,x,y;


vector<pair<char,int>> vec;
map<char,int> mp;

int main(){
	
	IO
	
	cin>>n;
	string str;
	getline(cin,str);
	for(int i=0;i<n;++i){
		getline(cin,str);
		for(char &c:str){
			c = toupper(c);
			if(c >= 'A' && c <= 'Z')
				++mp[c];
		}
	}
	
	for(auto it:mp)
		vec.push_back(it);
	
	sort(vec.begin(),vec.end(),[](pair<char,int> s,pair<char,int> f){
		if(s.second != f.second)
			return s.second > f.second;
		return s.first < f.first;	
	});
	
	for(auto it:vec)
		cout<<it.first<<" "<<it.second<<"\n";
	
	return 0;
}

