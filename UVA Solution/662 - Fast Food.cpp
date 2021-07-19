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
ll OO=1e15;
const int N=2e2 + 5,M=30 + 5;
int arr[N];
ll leftI[N][N];
ll rightI[N][N];
ll dp[N][N][M];


int n,m,k,len;

void clr(){
	memset(dp,-1,sizeof dp);
	len = 0;
}

void Init(){
	
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			ll val=0;
			
			for(int k=i+1;k<=j;++k)
				val+=arr[k]-arr[i];
			leftI[i][j]=val;
			
			val=0;
			
			for(int k=i;k<j;++k)
				val+=arr[j]-arr[k];
			rightI[i][j]=val;
		}
		
	}
	
}

ll Solve(int idx,int last,int k){
	
	if(idx == n)
		return !k && last == n ? 0 : OO;
	
	ll &ret = dp[idx][last][k];
	if(~ret)
		return ret;
	
	ret = Solve(idx+1,last,k);
	
	ll val = OO;
	for(int i=last;i<=idx;++i)
		val = min(val,rightI[last][i]+leftI[i][idx]);
	if(k)
		ret = min(ret,val + Solve(idx+1,idx+1,k-1));
	
	return ret;
	
	
}

void Bulid(int idx,int last,int k){
		
	if(idx == n)
		return;
	
	ll ret = Solve(idx,last,k);
	
	ll x = Solve(idx+1,last,k),y=OO;
	
	ll val = OO,id=last;
	for(int i=last;i<=idx;++i){
		ll lem = rightI[last][i]+leftI[i][idx];
		if(lem < val)
			val = lem, id = i;
		
	}
	if(k)
		y = val + Solve(idx+1,idx+1,k-1);
	
	if(ret == y){
		printf("Depot %d at restaurant %d serves restaurant",++len,id+1);
		if(last != idx)
			printf("s %d to %d\n",last+1,idx+1);	
		else
			printf(" %d\n",idx+1);
			
		Bulid(idx+1,idx+1,k-1);
		
	}else{
		Bulid(idx+1,last,k);
	}

}




int main(){
	
	int ID=1;
	while(scanf("%d%d",&n,&k) && (n || k)){
		
		clr();
		for(int i=0;i<n;++i)
			scanf("%d",arr+i);
		
		Init();
		ll val = Solve(0,0,k);
					
		printf("Chain %d\n",ID++);
		Bulid(0,0,k);
		printf("Total distance sum = %lld\n",val);
		puts("");
		
	}
	
	
	
	
	
	
}
