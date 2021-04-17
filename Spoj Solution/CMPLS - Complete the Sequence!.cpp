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
const int N=2e5 + 5,M=(1<<8) + 1;

int n,m,k,T;
ll a,b,c;
string str;


vector<int> Solve(vector<int> &arr){
	vector<vector<int>> v;
	v.push_back(arr);
	while(v.back().size() > 1){
		auto &vv = v.back();
		vector<int> nv;
		for(int i=1;i<SZ(vv);++i)
			nv.push_back(vv[i] - vv[i-1]);
		v.push_back(nv);
	}
	auto &vv = v.back();
	for(int i=0;i<k;++i)
		vv.push_back(vv.front());
	
	vector<int> ret = v.back();
	v.pop_back();

	while(v.size()){
		auto &cur = v.back();
		for(int i=0;i<k;++i){
			int sz = SZ(cur)-1;
			int val = cur[sz] + ret[sz];
			cur.push_back(val);
		}
		ret = v.back();
		v.pop_back();
	}

	return ret;
}


int main() {
	IO
//	freopen("stations.in","r",stdin);
	cin>>T;
	while(T--){
		cin>>n>>k;
		vector<int> ret(n);
		for(auto &it:ret)
			cin>>it;
		
		vector<int> ans = Solve(ret);
		//break;
		for(int i=n;i<SZ(ans);++i)
			cout<<ans[i]<<" ";
		cout<<"\n";
	}
    return 0;
} 
