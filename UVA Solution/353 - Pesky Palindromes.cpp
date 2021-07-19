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
const int N=1e2 + 5,M = N << 1,K = 5;
char arr[N];
 
int n,m,k,cnt,SU,idx,len,T,lg;
int a,b,c,x,y;

string str;
map<string,bool> mp;


void init(){
	str = arr;
	n = SZ(str);
	mp.clear();
}

void Bulid(int lt,int rt){
	while(lt  > -1 && rt < n && str[lt] == str[rt]){
		mp[str.substr(lt,rt-lt+1)] = true;
		--lt;
		++rt;
	}	
}


int main(){
	
	while(~scanf("%s",arr)){
		init();

		for(int i=0;i<n;++i){
			Bulid(i,i+1);
			Bulid(i,i);
		}
			
		
		printf("The string '%s' contains %d palindromes.\n",arr,SZ(mp));
	}
	
	return 0;
}


