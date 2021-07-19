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
const int N=1e5 + 5;
char val[N];
string str[N];
int arr[N],id[N];

ll n,m,k,cnt;
ll l,r,mid;




int BS(string x){

	l=0,r=n-1,mid;
	while(l<r){
		mid=(l+r+1)>>1;

		if(str[id[mid]] <= x)
			l=mid;
		else
			r=mid-1;
	}
	
	if(str[id[l]] == x)
		return arr[id[l]];
	
	return 0;
	
}

bool cmp(int s,int f){
	
	return str[s]<str[f];
}

int main(){

	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%s%d",val,&k);

		arr[i]=k;
		str[i]=val;
		id[i]=i;

	}
	
	sort(id,id+n,cmp);


	while(m--){
		cnt=0;
		
		while(scanf("%s",val) && val[0]!='.')
			cnt+=BS(val);
		
		
		printf("%lld\n",cnt);
		
	}
		

}
 
 
 
 
 
 
 
 
 
 
