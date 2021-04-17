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
const int N=1e5 + 5,M = N << 1,K = 5;
int arr[N];
 
int n,m,k,cnt,SU,idx,len,T,lg;
int a,b,c,x,y;

vector<int> adj[30];
vector<int> vec;
string str;

void init(){
	for(int i=0;i<30;++i)
		adj[i].clear();
	vec.clear();
	
}

int valid(int l,int r){
	int msk = 0;
	for(int i=0;i<26;++i){
		int idx = lower_bound(adj[i].begin(),adj[i].end(),l) - adj[i].begin();
		if(idx < SZ(adj[i]) && adj[i][idx] >= l && adj[i][idx] <= r)
			msk |= (1<<i);
	}
	
	return msk;
}

int BitCnt(int val){
	int cnt = 0;
	while(val){
		cnt += (val & 1);
		val >>= 1;
	}
	return cnt;
}

int Solve(){
	
	int cnt = 0;
	for(int i=0;i<k;++i){
		int idx = arr[i];
		int lt = 0,rt = n-1;
		for(int j:vec){
			if(j <= idx) lt = max(lt,j);
			if(j >= idx) rt = min(rt,j-1);	
		}
		vec.push_back(idx);
		if(lt > rt) continue;

		int msk = valid(lt,idx-1);
		msk ^= valid(idx,rt);
		
		cnt += BitCnt(msk);

	}
	
	return cnt;
}



int main(){
	
	IO
	
	cin>>T;
	while(T--){
		cin>>k;
		for(int i=0;i<k;++i)
			cin>>arr[i];
		cin>>str;
		n = SZ(str);
		init();
		
		for(int i=0;i<n;++i)
			adj[str[i]-'a'].push_back(i);
		
		cout<<Solve()<<endl;
		
	}
	
	return 0;
}

