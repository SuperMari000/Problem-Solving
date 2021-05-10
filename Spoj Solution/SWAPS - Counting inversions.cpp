//       Author: Mostafa Mounir Shehab
 
#include <bits/stdc++.h>
using namespace std;
 
#define PI  acos(-1)
#define EPS (1e-9)
#define endl "\n"
#define SZ(v) (int)(v.size())
#define IO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL);
typedef long long ll;
typedef long double ld;
 
 
ll MOD=1e9 + 7;
int OO=1e8;
const int N=1e6 + 10,M=(1<<17);
int arr[N],pre[N];

int n,m,k,T;
int a,b,c;
string s,t;

struct BIT{
	int Tree[M];
	void init(){
		memset(Tree,0,sizeof Tree);
	}
	
	void add(int idx,int val){		
		while(idx < M){
			Tree[idx] += val;
			idx += (idx & -idx);
		}
	}
	
	int get(int idx){
		int ret = 0;
		while(idx){
			ret += Tree[idx];
			idx -= (idx & -idx);
		}
		return ret;
	}
	
	int find(int idx){
		int st = 0;
		for(int sz = M >> 1;sz;sz >>= 1){
			if(Tree[st + sz] < idx){
				idx -= Tree[st += sz];
			}
		}
		return st + 1;
	}
	
} bit;

int sq;

ll Solve(int pos){
	auto start = [&](int idx){
		return idx * sq;
	};
	auto end = [&](int idx){
		return min((idx + 1) *sq, n) - 1;	
	};
	ll cnt = 0;
	int l = pos + 1,r = n - 1;
	while(l <= r){
		int x = l / sq;
		if(l == start(x) && end(x) <= r){
			cnt += lower_bound(pre + l,pre + end(x) + 1,arr[pos]) - (pre + l);
			l += sq;
		}else{
			cnt += (arr[l] < arr[pos]);
			++l;
		}
		
	}
	
	l = 0,r = pos - 1;
	while(l <= r){
		int x = l / sq;
		if(l == start(x) && end(x) <= r){
			cnt += (pre + end(x) + 1) - upper_bound(pre + l,pre + end(x) + 1,arr[pos]);
			l += sq;
		}else{
			cnt += (arr[l] > arr[pos]);
			++l;
		}
	}
	return cnt;
}


 
int main() {
	IO
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	ll ans = 0;
	bit.init();
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>arr[i];
		pre[i] = arr[i];
	}
	for(int i=n-1;~i;--i){
		ans += bit.get(arr[i] - 1);
		bit.add(arr[i],1);
	}
	sq = sqrt(n);
	auto start = [&](int idx){
		return idx * sq;
	};
	auto end = [&](int idx){
		return min((idx + 1) *sq, n) - 1;	
	};

	for(int i=0;i<n;i += sq)
		sort(pre + i,pre + end(i/sq) + 1);

	cin>>T;
	while(T--){
		int idx,val;
		cin>>idx>>val;
		--idx;
		ans -= Solve(idx);
		int st = start(idx / sq),en = end(idx / sq) + 1;
		int nidx = lower_bound(pre + st,pre + en,arr[idx]) - pre;
		pre[nidx] = val;
		sort(pre + st,pre + en);
		arr[idx] = val;
		ans += Solve(idx);
		cout<<ans<<endl;
	}
	
	
    return 0;
}   
