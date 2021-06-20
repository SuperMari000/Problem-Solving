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
	int rem[3];
	int lazy,len;
	Node(){
		lazy = 0,len = 3;
		memset(rem,0,sizeof rem);
	}
	
	Node(int val){
		memset(rem,0,sizeof rem);
		lazy = 0;
		rem[val % 3]++;
		len = 3;
	}
	
	void addLazy(int lz){
		for(int i=0;i < lz;++i){
			int x = rem[len - 1];
			for(int j=len - 1;j;--j)
				rem[j] = rem[j - 1];
			rem[0] = x;
		}
		lazy += lz;
		lazy %= 3;
	}
	
	
	friend ostream& operator << (ostream& out, Node &s){
		for(int i=0;i<4;++i)
			out<<s.rem[i]<<" ";
		out<<"\n";
	    return out;
	}
};
 
Node operator + (const Node l,const Node r){
	Node ret;
	for(int i=0;i<ret.len;++i)
		ret.rem[i] = l.rem[i] + r.rem[i];
	return ret;
}
 
struct SegmentTree{
	vector<Node> seg;
	void init(int n){
		seg = vector<Node>(n << 2);
	}
	void PushDown(int l,int r,int pos){
		int &lz = seg[pos].lazy;
		if(l == r || !lz) return;
		seg[pos << 1].addLazy(lz);
		seg[pos << 1 | 1].addLazy(lz);
		lz = 0;
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
	
	
	int Query(int l,int r,int pos,int st,int en){
		if(st > r || en < l || st > en)
			return 0;
		PushDown(l,r,pos);
		if(l >= st && r <= en)
			return seg[pos].rem[0];
		
		int mid = (l+r) >> 1;
		int lt = Query(l,mid,pos << 1,st,en);
		int rt = Query(mid+1,r,pos << 1 | 1,st,en);
		return lt + rt;
	}
	
	void Update(int l,int r,int pos,int st,int en){
		if(st > r || en < l || st > en)
			return;
		PushDown(l,r,pos);
		if(l >= st && r <= en){
			seg[pos].addLazy(1);
			return;
		}
		
		int mid = (l+r) >> 1;
		Update(l,mid,pos << 1,st,en);
		Update(mid+1,r,pos << 1 | 1,st,en);
		seg[pos] = seg[pos << 1] + seg[pos << 1 | 1];
	}
	
} ST;
 
 
int main() {
 
	IO
	//freopen("alice.in","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>n>>T;
	ST.init(n);
	ST.Bulid(0,n-1,1);
 
	int tp,a,b;
	while(T--){
		cin>>tp>>a>>b;
		if(tp & 1)
			cout<<ST.Query(0,n-1,1,a,b)<<endl;
		else
			ST.Update(0,n-1,1,a,b);
		
	}
	
	return 0;
} 
