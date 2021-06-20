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
const int N=2e5 + 10,M = 5e4 + 10;
int arr[N];
int L[N],R[N],ID[N];
int ans[N],fr[N];
deque<int> vec[N];
priority_queue<int> pr;
int n,m,k,T;
int a,b,c;
ll cnt;



void add(int v){
	int val = arr[v];
	auto &rt = vec[val + M];
	if(SZ(rt)){
		int mn = rt.back() - rt.front();
		--fr[mn];
		if(v > rt.back())
			rt.push_back(v);
		else
			rt.push_front(v);
	}else{
		rt.push_back(v);
	}
	int mx = rt.back() - rt.front();
	++fr[mx];
	pr.push(mx);
}
void rem(int v){
	int val = arr[v];
	auto &rt = vec[val + M];
	
	int mn = rt.back() - rt.front();
	--fr[mn];	
	if(v == rt.back())
		rt.pop_back();
	else
		rt.pop_front();
	
	if(SZ(rt)){
		int mx = rt.back() - rt.front();
		++fr[mx];
		pr.push(mx);
	}
}


int valid(){
	while(SZ(pr) && fr[pr.top()] <= 0)
		pr.pop();
	return SZ(pr) ? pr.top() : 0;
}


void MO(){
	int sq = sqrt(n);
	sort(ID,ID+m,[sq](int s,int f){
		return make_pair(L[s]/sq,R[s]) < make_pair(L[f]/sq,R[f]);
	});
	
	int r = 0,l = 1;
	for(int i=0;i<m;++i){
		int idx = ID[i];
		while(r < R[idx]) add(++r);
        while(l > L[idx] - 1) add(--l);
        while(l < L[idx] - 1) rem(l++);
        while(r > R[idx]) rem(r--);
        ans[idx] = valid();
	}
	
}

 
int main(){
	IO
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>arr[i];
		arr[i] += arr[i-1];
	}
		
	for(int i=0;i<m;++i){
		cin>>L[i]>>R[i];
		ID[i] = i;	
	}
	
	
	MO();
	
	for(int i=0;i<m;++i)
		cout<<ans[i]<<endl;
	
	return 0;	
}
 
