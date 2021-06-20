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
const int N=1e5 + 5;
int arr[N];
int n,m,k,T;
int a,b,c,lg;
 
struct Node{
	int mx,smx;
	Node(){
		mx = smx = INT_MIN;
	}
	
	Node(int val){
		mx = val;
		smx = INT_MIN;
	}
	
	
	friend ostream& operator << (ostream& out, Node &s){
		//out<<s.mn<<" "<<s.mx<<"\n";
	    return out;
	}
};

Node operator + (const Node l,const Node r){
	Node ret;
	vector<int> v = {l.mx,l.smx,r.mx,r.smx};
	sort(v.rbegin(),v.rend());
	ret.mx = v[0];
	ret.smx = v[1];
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
	
	Node Query(int l,int r,int pos,int st,int en){
		if(st > r || en < l || st > en)
			return Node();
		if(l >= st && r <= en)
			return seg[pos];
		
		int mid = (l+r) >> 1;
		Node lt = Query(l,mid,pos << 1,st,en);
		Node rt = Query(mid+1,r,pos << 1 | 1,st,en);
		return lt + rt;
	}
	
	void Update(int l,int r,int pos,int idx,int val){
		if(l == r){
			seg[pos] = Node(val);
			return;
		}
		
		int mid = (l + r) >> 1;
		if(idx > mid)
			Update(mid + 1,r, pos << 1 | 1,idx,val);
		else
			Update(l,mid,pos << 1,idx,val);
		
		seg[pos] = seg[pos << 1] + seg[pos << 1 | 1];
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
	
	cin>>T;
	char ch;
	int l,r;
	while(T--){
		cin>>ch>>l>>r;
		if(ch == 'Q'){
			--l,--r;
			Node ret = ST.Query(0,n-1,1,l,r);
			cout<<ret.mx + ret.smx<<endl;
		}else{
			ST.Update(0,n-1,1,l - 1,r);
		}
	}
	
	
	return 0;
} 
