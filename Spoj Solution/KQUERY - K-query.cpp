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
 
 
 
ll MOD=1e9 + 9;
int OO=1e9+7;
const int N=1e6 + 5;
int arr[N];
ll n,m,k,T;
int a,b,c,lg;
 
 
struct Node{
	vector<int> v;
	Node(){
		v.clear();
	}
	
	Node(int val){
		v.push_back(val);
	}

	friend ostream& operator << (ostream& out, Node &s){
		
	    return out;
	}
};
 
Node operator + (const Node &lt,const Node &rt){
	Node ret;
	auto &cur = ret.v;
	auto &chlt = lt.v;
	auto &chrt = rt.v;
	merge(chlt.begin(),chlt.end(),chrt.begin(),chrt.end(),inserter(cur,cur.begin()));
	return ret;
}
 
struct SegmentTree{
	vector<Node> seg;
	void init(int n){
		seg = vector<Node>(n << 2);
	}
	
	void Bulid(int l,int r,int pos){
		if(l == r){
			seg[pos] = Node(arr[l]);
			return;
		}
			
		int mid = (l+r) >> 1;
		Bulid(l,mid,pos << 1);
		Bulid(mid+1,r,pos << 1 | 1);
		
		seg[pos] = seg[pos << 1] + seg[pos << 1 | 1];
	}
	
	
	int Query(int l,int r,int pos,int st,int en,int val){
		if(st > r || en < l || st > en)
			return 0;
		auto &cur = seg[pos].v;
		if(l >= st && r <= en)
			return cur.end() - upper_bound(cur.begin(),cur.end(),val);
		
		int mid = (l+r) >> 1;
		int lt = Query(l,mid,pos << 1,st,en,val);
		int rt = Query(mid+1,r,pos << 1 | 1,st,en,val);
		return lt + rt;
	}
	
	
} ST;
 
 
int main() {
 
	IO
	//freopen("alice.in","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>arr[i];
	
	ST.init(n);
	ST.Bulid(0,n-1,1);
 
	int l,r,val;
	cin>>T;
	while(T--){
		cin>>l>>r>>val;
		--l,--r;
		cout<<ST.Query(0,n-1,1,l,r,val)<<endl;
	}
	
	return 0;
} 
