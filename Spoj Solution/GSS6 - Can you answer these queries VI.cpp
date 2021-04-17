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
int a,b,c;
 
extern struct Node *empty;
enum DIR{L,R};

 
struct Data{
	ll lt,rt,best,sum;
	Data(){
		sum = 0;
		lt = rt = best = -1e18;
	}
	
	Data(ll val){
		sum = lt = rt = best = val;
	}
	
	friend ostream& operator << (ostream& out, Data &s){
		out<<s.sum<<" "<<s.best<<"\n";
	    return out;
	}
};

Data operator + (const Data l,const Data r){
	Data ret;
	
	ret.best = max({l.best,r.best,l.rt + r.lt});
	ret.lt = max(l.lt,l.sum + r.lt);
	ret.rt = max(r.rt,r.sum + l.rt);
	ret.sum = l.sum + r.sum;
	
	return ret;
}

struct Node{
	ll val;
	int p,sz;
	Node *child[2];
	Data d;
	
	Node() : sz(0), p(INT_MIN), child({this,this}), val(0){}
	Node(ll v,Node *l = empty,Node *r = empty){
		sz = 1;
		p = rand()*rand();
		child[L] = l;
		child[R] = r;
		d = Data(v);
		val = v;
	}
	
	void Push_Up(){
		if(this == empty)
			return;
		sz = 1;
		for(int i=0;i<2;++i)
			sz += child[i]->sz;
		
		d = (child[L]->d + Data(val)) + child[R]->d;
	}
	
};
 
Node *empty=new Node();
 
struct Treap{
	Node *root;
	void init(){
		root = empty;
	}
	
	void Split(Node *root,const int idx,Node *&lt,Node *&ge){
		
		if(root == empty){
			lt = ge = empty;
			return;
		}
	
		int lfsz = root->child[L]->sz;
		if(idx <= lfsz){
			ge = root;
			Split(root->child[L],idx,lt,root->child[L]);
		}else{
			lt = root;
			Split(root->child[R],idx - lfsz - 1,root->child[R],ge);
		}
		root->Push_Up();
	}
	
	Node *Merge(Node *lt,Node *ge){
		if(lt == empty) return ge;
		if(ge == empty) return lt;
		
		Node *temp;
		if(lt->p > ge->p){
			lt->child[R] = Merge(lt->child[R],ge);
			temp = lt;
		}else{
			ge->child[L] = Merge(lt,ge->child[L]);
			temp = ge;
		}
		
		temp->Push_Up();
		return temp;
	}
	
	void Replace(int st,int en,int val){
		Node *l,*mid,*r;
		Split(root,en+1,mid,r);
		Split(mid,st,l,mid);
		mid->d = Data(mid->val = val);
		root = Merge(l,Merge(mid,r));
	}

	void AddVal(int en,int val){
		Node *l,*mid,*r;
		Split(root,en+1,mid,r);
		Node *x = new Node(val);
		
		root = Merge(Merge(mid,x),r);
	}
	
	ll Query(int st,int en){
		Node *l,*mid,*r;
		Split(root,en+1,mid,r);
		Split(mid,st,l,mid);
		ll ans = mid->d.best;
		root = Merge(l,Merge(mid,r));
		return ans;
	}
	
	void Erase(int st,int en){
		Node *l,*mid,*r;
		Split(root,en+1,mid,r);
		Split(mid,st,l,mid);
		delete mid;
		root = Merge(l,r);
	}
	
	void print(Node *rt,int dpth=0){
	    if(rt == empty)
	        return;
	    static int idx = 0;
	    print(rt->child[L],dpth+1);
	  //  printf("%s%2lld,%2d\n",string(dpth*5,' ').c_str(),rt->val,rt->sz);
	    print(rt->child[R],dpth+1);
	}
	
} TR;
 
 
int main() {
	IO
	TR.init();
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a;
		TR.root = TR.Merge(TR.root,new Node(a));
	}

	cin>>T;
	char c;
	int idx,val;
	while(T--){
		cin>>c;
		if(c == 'I'){
			cin>>idx>>val;
			idx--;
			TR.AddVal(idx-1,val);
		}else if(c == 'Q'){
			int l, r;
			cin>>l>>r;
			--l,--r;
			cout<<TR.Query(l,r)<<endl;
		}else if(c == 'D'){
			cin>>idx;
			--idx;
			TR.Erase(idx,idx);
		}else{
			cin>>idx>>val;
			--idx;
			TR.Replace(idx,idx,val);
		}
		
	}
	
    return 0;
}
