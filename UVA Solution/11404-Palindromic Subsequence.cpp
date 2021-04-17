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
ll OO=1e6;
const int N=1e3 + 5;
string val[N][N];
bool dp[N][N];



int n,m,k;
string str;


string Solve(int l,int r){
	
	if(l == r)
		return string(1,str[l]);
	
	if(l+1 == r){
		if(str[l] == str[r])
			return string(2,str[l]);
		
		return min(string(1,str[l]),string(1,str[r]));
	}

	
	bool &ret = dp[l][r];
	string &p = val[l][r];
	if(ret)
		return p;
	
	ret = true;
	
	if(str[l] == str[r]){
		
		p = Solve(l+1,r-1);
		p = str[l] + p + str[r];
		return p;
		
	}
	
	string x = Solve(l+1,r);
	string y = Solve(l,r-1);
	
	if(SZ(x) != SZ(y)){
		
		if(SZ(x) > SZ(y))
			p = x;
		else
			p=y;

	}else{
		
		if(x < y)
			p = x;
		else
			p=y;
			
	}
	
	return p;
	
}


int main(){
	IO
	
	while(cin>>str){
		memset(dp,0,sizeof dp);
		
		cout<<Solve(0,SZ(str)-1)<<endl;
	}

	
}



