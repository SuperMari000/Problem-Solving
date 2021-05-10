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
const int N=1e5 + 10,M = 500 + 10; 
int arr[N],pre[N];

int n,m,k,T;
int a,b,c,st,en;


int main() {
	IO
	cin>>n>>T;
	for(int i=0;i<n;++i){
		cin>>arr[i];
		pre[i] = arr[i];
	}
	
	int sq = sqrt(n);
	auto start = [&](int idx){
		return idx*sq;
	};
	auto end = [&](int idx){
		return min((idx + 1) * sq,n) - 1;
	};
	for(int i=0;i<n;i += sq)
		sort(pre + i,pre + end(i/sq) + 1);
	
	char c;
	int l,r,v;
	while(T--){
		cin>>c;
		if(c == 'C'){
			cin>>l>>r>>v;
			--l,--r;
			int ans = 0;
			while(l <= r){
				int lvl = l/sq;
				if(l == start(lvl) && end(lvl) <= r){
					int cnt = upper_bound(pre + start(lvl),pre + end(lvl) + 1,v) - (pre + start(lvl));
					ans += cnt;
					l += sq;
				}else{
					ans += (arr[l] <= v);
					++l;
				}
			}
			
			cout<<ans<<endl;
		}else{
			cin>>l>>v;
			--l;
			int idx = lower_bound(pre + start(l/sq),pre + end(l/sq) + 1,arr[l]) - pre;
			pre[idx] = arr[l] = v;
			sort(pre + start(l/sq),pre + end(l/sq) + 1);
		}
	}
	
	
    return 0;
} 
