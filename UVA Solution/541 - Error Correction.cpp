//       Author: Mostafa Mounir Shehab
 
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
const int N=1e2+ 5;
int arr[N][N];


ll n,m,k;





int main(){
	
		
	while(scanf("%d",&n) && n){
		int row,col,cntr,cntc,idxr,idxc;
		row=col=idxr=idxc=cntr=cntc=0;
		
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				scanf("%d",&arr[i][j]);
				
		for(int i=0;i<n;++i){
			cntc=cntr=0;
			for(int j=0;j<n;++j){
				cntc+=arr[j][i];
				cntr+=arr[i][j];
			}
			
			if(cntc&1)
				++col,idxc=i;
			if(cntr&1)
				++row,idxr=i;
			
		}
		
		
		if(!row && !col)
			puts("OK");
		else if(row==1 && col==1)
			printf("Change bit (%d,%d)\n",idxr+1,idxc+1);
		else
			puts("Corrupt");
		
	}
	

 
}
 
 
 
 
 
 
 
