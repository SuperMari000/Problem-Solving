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
const int N=2e6 + 5,M = 30;
int arr[N];
bool vis[N];
int n,m,k,T;
int a,b,c,lg;


void Seive(){
	vis[0] = vis[1] = true;;
	for(int i=2;i <= N/i;i += (1 + (i & 1))){
		if(vis[i]) continue;
		for(int j = i * i;j < N;j += i)
			vis[j] = true;
	}
}


 
struct Node{
	int su,lz;
	Node(){
		lz = -1;
		su = 0;
	}
	
	Node(ll val){
		su = !vis[val];
		lz = -1;
	}
	
	void addLazy(ll v,int l,int r){
		su = (r - l + 1)*(!vis[v]);
		lz = v;
	}
	
	friend ostream& operator << (ostream& out, Node &s){
		//out<<s.mn<<" "<<s.mx<<"\n";
	    return out;
	}
};
 
Node operator + (const Node l,const Node r){
	Node ret;
	ret.su = l.su + r.su;
	return ret;
}
 
struct SegmentTree{
	vector<Node> seg;
	void init(int n){
		seg = vector<Node>(n << 2);
	}
	
	void PushDown(int l,int r,int pos){
		int &lz = seg[pos].lz;
		if(l == r || lz == -1) return;
		int mid = (l + r) >> 1;
		seg[pos << 1].addLazy(lz,l,mid);
		seg[pos << 1 | 1].addLazy(lz,mid+1,r);
		lz = -1;
	}
	
	
	void Bulid(int l,int r,int pos){
		if(l == r){
			seg[pos] = Node(arr[l]);
			return;
		}
			
		int mid = (l + r) >> 1;
		Bulid(l,mid,pos << 1);
		Bulid(mid+1,r,pos << 1 | 1);
		
		seg[pos] = seg[pos << 1] + seg[pos << 1 | 1];
	}
	
	
	int Query(int l,int r,int pos,int st,int en){
		if(st > r || en < l || st > en)
			return 0;
		PushDown(l,r,pos);
		if(l >= st && r <= en)
			return seg[pos].su;
		
		int mid = (l + r) >> 1;
		int lt = Query(l,mid,pos << 1,st,en);
		int rt = Query(mid+1,r,pos << 1 | 1,st,en);
		return lt + rt;
	}
	
	void Update(int l,int r,int pos,int st,int en,ll val){
		if(st > r || en < l || st > en)
			return;
		PushDown(l,r,pos);
		if(l >= st && r <= en){
			seg[pos].addLazy(val,l,r);
			return;
		}
		
		int mid = (l + r) >> 1;
		Update(l,mid,pos << 1,st,en,val);
		Update(mid+1,r,pos << 1 | 1,st,en,val);
		seg[pos] = seg[pos << 1] + seg[pos << 1 | 1];
	}
 
} ST;


 
int main() {
 
	//IO
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	Seive();
	scanf("%d",&T);
	for(int cse = 1;cse <= T;cse++){
		printf("Case %d:\n",cse);
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i)
			scanf("%d",arr+i);
		ST.init(n);
		ST.Bulid(0,n-1,1);
		int tp,l,r,v;
		while(m--){
			scanf("%d%d%d",&tp,&l,&r);
			--l,--r;
			if(!tp){
				scanf("%d",&v);
				ST.Update(0,n-1,1,l,r,v);
			}else{
				printf("%d\n",ST.Query(0,n-1,1,l,r));
			}
		}
	}
	
	
	return 0;
} 
