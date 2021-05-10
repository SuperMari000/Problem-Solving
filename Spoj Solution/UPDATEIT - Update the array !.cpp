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
int OO=1e8;
const int N=1e4 + 10,M=(1<<8) + 1;
ll arr[N],sum[N];

int n,m,k,T;
int a,b,c,st,en;


void clr(){
	memset(arr,0,sizeof arr);
	memset(sum,0,sizeof sum);
}



int main() {
	IO
	
	cin>>T;
	while(T--){
		clr();
		cin>>n>>m;
		
		int sq = sqrt(n);
		auto start = [&](int idx){
			return idx*sq;
		};
		auto end = [&](int idx){
			return min((idx + 1) * sq,n) - 1;
		};
		
		while(m--){
			cin>>a>>b>>c;
			if(a > b) swap(a,b);
			while(a <= b){
				int lvl = a/sq;
				if(a == start(lvl) && end(lvl) <= b){
					sum[lvl] += c;
					a += sq;
				}else{
					arr[a] += c;
					++a;
				}
			}
		}
		
		cin>>m;
		while(m--){
			cin>>a;
			ll ans = sum[a/sq] + arr[a];
			cout<<ans<<endl;
		}
		
	}
	
    return 0;
} 
