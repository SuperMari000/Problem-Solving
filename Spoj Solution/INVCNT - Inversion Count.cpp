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
int arr[N];

int n,m,k,T;
ll a,b,c;
string str;


extern struct Node *empty;

struct Node{
    ll sum;
    Node *lf, *rt;
    Node():sum(0), lf(this), rt(this){}
    Node(ll val):sum(val), lf(empty), rt(empty){}
};
 
Node *empty = new Node();

struct MultiSet{
	Node *root;
	int mn,mx;
	
	void Init(int mn,int mx){
		Clear(root);
		root = empty;
		this->mn = mn;
		this->mx = mx;
	}
	void Clear(Node *&root){
		if(root == empty || root == nullptr)
			return;
		Clear(root->lf);
		Clear(root->rt);
		delete root;
	}
	
	void Add(int idx,int val,Node *&nd,int l,int r){
		if(idx > r || idx < l) return;
		if(nd == empty) nd = new Node(0);
		if(l == r){
			nd->sum += val;
			return;
		}
		
		int mid = l + (r - l) / 2;
		
		Add(idx,val,nd->lf,l,mid);
		Add(idx,val,nd->rt,mid + 1,r);
		nd->sum = nd->lf->sum + nd->rt->sum;
	}
	
	int Count(int qs,int qe,Node *&nd,int l,int r){
		if(l > qe || r < qs || qs > qe) return 0;
		if(l >= qs && r <= qe) return nd->sum;
		
		int mid = l + (r - l) / 2;
		return Count(qs,qe,nd->lf,l,mid) 
			 + Count(qs,qe,nd->rt,mid + 1,r);
	}
	
	int Find(int val,Node *&nd,int l,int r){
		if(l == r) return l;
		
		int lsz = nd->lf->sum;
		int mid = l + (r - l) / 2;
		
		if(val < lsz)
			return Find(val,nd->lf,l,mid);
		return Find(val - lsz,nd->rt,mid + 1,r);
	}
	
	void Insert(int x){
		Add(x,1,root,mn,mx);
	}
	
	void Erase(int x){
		Add(x,-min(1,Count(x)),root,mn,mx); // -min(1,count(x)) -> if x not found
	}
	
	int Count(int x){
		return Count(x,x,root,mn,mx);
	}
	
	int Size(){
		return root->sum;
	}
	
	int operator [] (int idx){ // Zero-Based
		return Find(idx,root,mn,mx);
	}
	
	int LowerBound(int val){ // Zero-Based
		return Count(mn,val-1,root,mn,mx);
	}
	
	int UpperBound(int val){ // Zero-Based
		return Count(mn,val,root,mn,mx);
	}
	
} MLS;

int main() {
	IO
//	freopen("stations.in","r",stdin);
//	freopen("out.txt","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		vector<int> v(n);
		int mn = INT_MAX,mx = INT_MIN;
		for(auto &it:v){
			cin>>it;
			mn = min(it,mn);
			mx = max(it,mx);
		}
		MLS.Init(mn,mx);
		for(int i:v)
			MLS.Insert(i);
		
		ll ans = 0;
		for(int i=n-1;~i;--i){
			MLS.Erase(v[i]);
			ans += MLS.Size() - MLS.UpperBound(v[i]);
		}
		
		cout<<ans<<endl;
	}
	
	
	
	
    return 0;
} 
