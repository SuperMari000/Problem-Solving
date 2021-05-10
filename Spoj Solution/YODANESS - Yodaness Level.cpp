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
const int N=3e4 + 10,M=(1<<8) + 1;
int arr[N];
int n,m,k,T;
int a,b,c,st,en;



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
	
} bit;

map<string,deque<int>> mp;
string str;
void clr(){
	mp.clear();
	bit.init();
}


int main() {
	IO
	
	cin>>T;
	while(T--){
		clr();
		
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>str;
			mp[str].push_back(i);
		}
		
		for(int i=0;i<n;++i){
			cin>>str;
			arr[i] = mp[str].front();
			mp[str].pop_front();
			bit.add(arr[i],1);
		}
		
		int ans = 0;
		for(int i=n-1;~i;--i){
			ans += bit.get(N - 1) - bit.get(arr[i]);
			bit.add(arr[i],-1);
		}
		
		cout<<ans<<endl;
	}
	
    return 0;
} 
