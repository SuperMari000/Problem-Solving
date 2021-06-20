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
int OO=1e9 + 10;
const int N=1e5 + 10,M=20;
ll arr[N];
 
int n,m,k,T;
int a,b,c,d;
int l,r,mid;
string str;
 
struct Node{
	ll sum,sumsq,lazy;
	int id;
	Node(){
		sum = sumsq = lazy = id = 0;
	}
	Node(ll val){
		sum = val;
		sumsq = sum*sum;
		lazy = id = 0;
	}
	
	void addLazy(ll v,int l,int r,int cur){
		if(cur == id){
			ll a = v*v*(r-l+1);
			ll b = 2*v*sum;
			sumsq += a + b;
			sum += v*(r-l+1);
			lazy += v;
		}else{
			sum = v*(r-l+1);
			sumsq = v*sum;
			lazy = v;
		}
		id = cur;
	}
	
	friend ostream& operator << (ostream& out, Node &s){
			
		out<<s.sum<<"\n";
	    return out;
	}
};
 
struct SegmentTree{
	vector<Node> seg;
	
	void init(int n){
		seg.resize(4*n);
	}
	void PushDown(int pos,int l,int r){
		Node &cur = seg[pos];
		if(cur.lazy == 0 || l == r) return;
		int mid = (l+r) >> 1;
		seg[2*pos].addLazy(cur.lazy,l,mid,cur.id);
		seg[2*pos+1].addLazy(cur.lazy,mid+1,r,cur.id);
		cur.lazy = 0;
	}
	
	void Bulid(int l,int r,int pos){
		if(l == r){
			seg[pos] = Node(arr[l]);
			return;
		}
		
		int mid = (l+r)>>1;
		Bulid(l,mid,2*pos);
		Bulid(mid+1,r,2*pos+1);
		seg[pos] = Node();
		seg[pos].sum = seg[2*pos].sum + seg[2*pos+1].sum;
		seg[pos].sumsq = seg[2*pos].sumsq + seg[2*pos+1].sumsq;
	}
	void Print(int l,int r,int pos){
		cout<<"["<<l<<" , "<<r<<"] ";
		cout<<seg[pos];
		
		if(l == r)
			return;
		
		int mid = (l+r) >> 1;
		Print(l,mid,2*pos);
		Print(mid+1,r,2*pos+1);
	}
 
	ll QueryRange(int l,int r,int pos,int st,int en){
		if(st > r || en < l)
			return 0;
		
		if(l >= st && r <= en)
			return seg[pos].sumsq;
		PushDown(pos,l,r);
		
		int mid = (l+r)>>1;
		return QueryRange(l,mid,2*pos,st,en) + QueryRange(mid+1,r,2*pos+1,st,en);
	}
	
	void UpdateAdd(int l,int r,int pos,int st,int en,int val){
		if(st > r || en < l)
			return;
		if(l >= st && r <= en){
			seg[pos].addLazy(val,l,r,seg[pos].id);
			return;
		}
		PushDown(pos,l,r);
		int mid = (l+r)>>1;
 
		UpdateAdd(l,mid,2*pos,st,en,val);
		UpdateAdd(mid+1,r,2*pos+1,st,en,val);
		
		seg[pos].sum = seg[2*pos].sum + seg[2*pos+1].sum;
		seg[pos].sumsq = seg[2*pos].sumsq + seg[2*pos+1].sumsq;
	}
	
	void UpdateVal(int l,int r,int pos,int st,int en,int val,int id){
		if(st > r || en < l)
			return;
		if(l >= st && r <= en){
			seg[pos].addLazy(val,l,r,id);
			return;
		}
		PushDown(pos,l,r);
		int mid = (l+r)>>1;
 
		UpdateVal(l,mid,2*pos,st,en,val,id);
		UpdateVal(mid+1,r,2*pos+1,st,en,val,id);
		
		seg[pos].sum = seg[2*pos].sum + seg[2*pos+1].sum;
		seg[pos].sumsq = seg[2*pos].sumsq + seg[2*pos+1].sumsq;
	}
	
} ST;
 
 
int main(){
	
	//freopen("in.txt","r",stdin);
	int ID = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i)
			scanf("%lld",arr+i);
			
		ST.init(n);
		ST.Bulid(0,n-1,1);
		
		printf("Case %d:\n",++ID);
		for(int i=1;i<=m;++i){
			scanf("%d%d%d",&a,&b,&c);
			
			if(a == 2){
				printf("%lld\n",ST.QueryRange(0,n-1,1,b-1,c-1));
				continue;
			}
			scanf("%d",&d);
			if(a == 1)
				ST.UpdateAdd(0,n-1,1,b-1,c-1,d);
			else
				ST.UpdateVal(0,n-1,1,b-1,c-1,d,i);
			
		}
		
	}
	
	return 0;
} 
