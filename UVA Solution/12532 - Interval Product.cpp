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
ll OO=1e9 + 1;
const int N=2e5 + 10,M=2e6+2;
int arr[N];
 
 
int n,m,k,T;
int a,b,c,d;
int l,r,mid;
string str;

 
struct Node{
	int p,n,z;
	Node(){
		p = n = z = 0;
	}
	
	Node(int v){
		p = v > 0;
		n = v < 0;
		z = v == z;
	}

	friend ostream& operator << (ostream& out, Node &s1){
		out<<s1.p<<" "<<s1.n<<" "<<s1.z<<"\n";
	    return out;
	}
};

Node operator * (const Node l,const Node r){
	Node ret;
	ret.p = l.p + r.p;
	ret.n = l.n + r.n;
	ret.z = l.z + r.z;
	return ret;
}
 
 
struct SegmetTree{
	vector<Node> seg;
	void init(int n){
		seg.resize(4*n);
	}
	
	void Bulid(int l,int r,int pos){
		
		if(l == r){
			seg[pos] = Node(arr[l]);
			return;
		}
			
		int mid = (l+r) >> 1;
		Bulid(l,mid,2*pos);
		Bulid(mid+1,r,2*pos+1);
		
		seg[pos] = seg[2*pos] * seg[2*pos+1];
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
	

	
	Node Query(int l,int r,int pos,int st,int en){
		if(st > r || en < l || st > en)
			return Node();

		if(l>=st && r<=en)
			return seg[pos];
		
		int mid = (l+r)>>1;
		Node lt = Query(l,mid,pos<<1,st,en);
		Node rt = Query(mid+1,r,pos<<1 | 1,st,en);

		return lt * rt;
	}
	
	void Update(int l,int r,int pos,int idx,int val){
		if(l == r){
			seg[pos] = Node(val);
			return;
		}
		int mid = (l+r) >> 1;
		if(idx > mid)
			Update(mid+1,r,2*pos+1,idx,val);
		else
			Update(l,mid,2*pos,idx,val);
		seg[pos] = seg[2*pos] * seg[2*pos+1];
	}
	char GetQuery(int l,int r,int pos,int st,int en){
		Node nd = Query(l,r,pos,st,en);
		if(nd.z > 0)
			return '0';
		if(nd.n&1)
			return '-';
		return '+';
	}

	

} ST;


int main(){

	while(~scanf("%d%d",&n,&T)){
		for(int i=0;i<n;++i)
			scanf("%d",arr+i);
		ST.init(n);
		ST.Bulid(0,n-1,1);
		char c;
		int a,b;
		string ans = "";
		while(T--){
			scanf(" %c%d%d",&c,&a,&b);
			
			if(c == 'P')
				ans += ST.GetQuery(0,n-1,1,a-1,b-1);
			else
				ST.Update(0,n-1,1,a-1,b);
	
		}
		printf("%s\n",ans.c_str());
	}

 
	return 0;
}
 
