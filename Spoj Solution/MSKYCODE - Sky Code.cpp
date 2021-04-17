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
 
 
 
ll MOD=(1ll<<31)-1;
int OO=1e9 + 1;
const int N=1e4 + 5,M= 1e6 + 5;
int fr[N],arr[N],pre[N],vis[N],mx;

int n,m,k,SU,idx,len,MN,MX,T,lg;
int l,r,mid;
int a,b,c;


void Seive(){
	for(int i=2;i<N;++i){
		if(fr[i]) continue;
		for(int j=i;j<N;j+=i)
			fr[j]++;
	}
	
}

void init(){
	memset(vis,0,sizeof vis);
	memset(pre,0,sizeof pre);
	mx = -1;
	
}

ll nCr(int n,int r){
	if(r == 0 || n == r) return 1;
	if(n < r) return 0;
	
	return nCr(n - 1, r)*n/(n - r);
}


int main(){

	Seive();
	while(~scanf("%d",&n)){
		init();
		for(int i=0;i<n;++i){
			scanf("%d",arr+i);
			pre[arr[i]]++;
			mx = max(mx,arr[i]);
		}
		
		ll ans = nCr(n,4);
		for(int i=2;i<=mx;++i){
			if(vis[i]) continue;
			int cnt = 0;
			for(int j=i;j<=mx;j+=i){
				if(fr[j] == fr[i]) vis[j] = true;
				cnt += pre[j];
			}
			
			if(fr[i]&1)
				ans -= nCr(cnt,4);
			else
				ans += nCr(cnt,4);
		}
		
		printf("%lld\n",ans);
		
	}
	
	return 0;
}
