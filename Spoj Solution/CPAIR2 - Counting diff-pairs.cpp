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
 
 
ll MOD=5e6;
int OO=1e8;
const int N=1e5 + 10,M = 1e5;
int arr[N];
int L[N],R[N],ID[N];
ll ans[N];

int n,m,k,T;
int a,b,c;
ll cnt;

struct BIT{
	int Tree[N];
	void init(){
		memset(Tree,0,sizeof Tree);
	}
	
	void add(int idx,int val){ // 1-Based
		while(idx < N){
			Tree[idx] += val;
			idx += (idx & -idx);
		}
	}
	
	int get(int idx){ // 1-Based
		int ret = 0;
		while(idx){
			ret += Tree[idx];
			idx -= (idx & -idx);
		}
		return ret;
	}
	int getRange(int l,int r){
		if(r >= N || l <= 0 || l > r)
			return 0;
		return get(r) - get(l - 1);
	}
	
} bit;


void add(int v){
	v = arr[v];
	cnt += bit.getRange(v + k,N - 1);
	cnt += bit.getRange(1,v - k);
	bit.add(v,1);
}
void rem(int v){
	v = arr[v];
	cnt -= bit.getRange(v + k,N - 1);
	cnt -= bit.getRange(1,v - k);
	bit.add(v,-1);
}


void MO(){
	int sq = sqrt(n);
	sort(ID,ID+m,[sq](int s,int f){
		return make_pair(L[s]/sq,R[s]) < make_pair(L[f]/sq,R[f]);
	});
	
	int r = -1,l = 0;
	for(int i=0;i<m;++i){
		int idx = ID[i];
		while(r < R[idx]) add(++r);
        while(l > L[idx]) add(--l);
        while(l < L[idx]) rem(l++);
        while(r > R[idx]) rem(r--);
        ans[idx] = cnt;
	}
	
}

 
int main(){
	IO
	
	bit.init();
	
	cin>>n>>m>>k;
	for(int i=0;i<n;++i)
		cin>>arr[i];

	for(int i=0;i<m;++i){
		cin>>L[i]>>R[i];
		--L[i],--R[i];
		ID[i] = i;	
	}
	
	
	MO();
	
	for(int i=0;i<m;++i)
		cout<<ans[i]<<endl;
	
	return 0;	
}
 
