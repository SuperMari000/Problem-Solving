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
const int N=1e5 + 10,M=20;
int arr[N];
char str[150];
 
 
int n,m,k,T;
int a,b,c,d;
int l,r,mid;
 
 
 
struct Node{
	int val;
	Node(){
		val = -1;
	}
	
	Node(int val){
		this->val = val;
	}
	friend ostream& operator << (ostream& out, Node &s1){
		out<<s1.val<<"\n";
	    return out;
	}
};

Node Min(const Node l,const Node r){
	Node ret;
	ret.val = min(l.val,r.val);
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
		
		seg[pos] = Min(seg[2*pos],seg[2*pos+1]);
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
	
	void Update(int l,int r,int pos,int idx,int val){
		if(l == r){
			seg[pos].val = val;
			return;
		}
		
		int mid = (l+r)>>1;
		if(idx <= mid)
			Update(l,mid,2*pos,idx,val);
		else
			Update(mid+1,r,2*pos+1,idx,val);
		
		seg[pos] = Min(seg[2*pos],seg[2*pos+1]);
 
	}
	
	int Query(int l,int r,int pos,int st,int en){
		if(st > r || en < l || st > en)
			return OO;
		if(l>=st && r<=en)
			return seg[pos].val;
		
		int mid = (l+r)>>1;
		int lt = Query(l,mid,pos<<1,st,en);
		int rt = Query(mid+1,r,pos<<1 | 1,st,en);
		return min(lt,rt);
	}

	
} ST;

vector<int> v;
void GEN(){
	v.clear();
	string s="";
	for(int i=0;str[i];++i){
		if(isdigit(str[i]))
			s+=str[i];
		else if(SZ(s)){
			int n;
			istringstream ss(s);
			ss>>n;
			v.push_back(n-1);
			s = "";
		}
	}
} 
 
void Solve(){
	int stv = arr[v.front()];
	for(int i=0;i<SZ(v)-1;++i){
		arr[v[i]] = arr[v[i+1]];
		ST.Update(0,n-1,1,v[i],arr[v[i]]);
	}
	
	arr[v.back()] = stv;
	ST.Update(0,n-1,1,v.back(),stv);
}
 
 
int main(){

	scanf("%d%d",&n,&T);
	for(int i=0;i<n;++i)
		scanf("%d",arr+i);
 
	ST.init(n);
	ST.Bulid(0,n-1,1);
	
	while(T--){
		scanf("%s",str);
		GEN();
		if(str[0] == 'q'){
			printf("%d\n",ST.Query(0,n-1,1,v.front(),v.back()));
			continue;
		}
		
		Solve();
	}
 
	return 0;
}
 
  
