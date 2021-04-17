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
const int N=1e5 + 5,M=(1<<8) + 1;
int arr[N];
 
int n,m,k,T;
int a,b,c;
 
extern struct Node *empty;
enum DIR{L,R};
 
struct Node{
	
	int val;
	int p,sz;
	Node *child[2];
	bool isRev;
	
	Node() : val(0), sz(0), p(INT_MIN), child({this,this}), isRev(0){}
	Node(int v,Node *l = empty,Node *r = empty){
		val = v;
		sz = 1;
		p = rand()*rand();
		child[L] = l;
		child[R] = r;
		isRev = 0;
	}
	
	void Push_Up(){
		sz = 1;
		for(int i=0;i<2;++i)
			sz += child[i]->sz;
	}
	
	void Push_Down(){
		if(this == empty || !isRev)
			return;
		for(int i=0;i<2;++i)
			child[i]->Reverse();
		isRev = false;
	}
	
	void Reverse(){
		if(this == empty)
			return;
		isRev ^= 1;
		swap(child[L],child[R]);
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
		root->Push_Down();
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
		lt->Push_Down();
		ge->Push_Down();
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
	
	void DoRev(int st,int en){
		Node *l,*mid,*r;
		Split(root,en+1,mid,r);
		Split(mid,st,l,mid);
		mid->Reverse();
		root = Merge(l,Merge(mid,r));
	}


	
	void print(Node *rt,int dpth=0){
	    if(rt == empty)
	        return;
	    rt->Push_Down();
	    static int idx = 0;
	    print(rt->child[L],dpth+1);
	   	//printf("%s%2d,%2d\n",string(dpth*5,' ').c_str(),rt->val,rt->sz);
	    arr[idx++] = rt->val;
	    print(rt->child[R],dpth+1);
	}
	
} TR;
 
 
int main() {
	IO
	TR.init();
	int n,k,l,r;
	cin>>n>>k;

	for(int i=1;i<=n;++i)
		TR.root = TR.Merge(TR.root,new Node(i));

	while(k--){
		cin>>l>>r;
		--l,--r;
		TR.DoRev(l,r);
	}
	TR.print(TR.root);
	for(int i=0;i<n;++i)
		cout<<arr[i]<<" ";
	
	
    return 0;
} 
