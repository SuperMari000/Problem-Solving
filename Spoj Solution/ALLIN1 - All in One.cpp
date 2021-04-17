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
 
int n,m,k;
ll a,b,c;
 
extern struct Node *empty;
enum DIR{L,R};
 
struct Node{
	
	int val;
	int p,sz,fr;
	Node *child[2];
	
	Node() : val(0), sz(0), fr(0), p(INT_MIN), child({this,this}){}
	Node(ll v,Node *l = empty,Node *r = empty){
		val = v;
		fr = sz = 1;
		p = rand();
		child[L] = l;
		child[R] = r;
	}
	void Push_Up(){
		sz = fr;
		for(int i=0;i<2;++i)
			sz += child[i]->sz;
	}
};
 
Node *empty=new Node();
 
struct Treap{
	Node *root;
	void init(){
		root = empty;
	}
	
 
	void Split(Node *root,const int v,Node *&lt,Node *&ge){
		
		if(root == empty){
			lt = ge = empty;
			return;
		}
		
		if(root->val >= v){
			ge = root;
			Split(root->child[L],v,lt,root->child[L]);
		}else{
			lt = root;
			Split(root->child[R],v,root->child[R],ge);
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
	
	void Insert(Node *&root, Node *nd){
		if(root == empty){
			root = nd;
			return;
		}
		
		if(nd->p > root->p){
			Split(root,nd->val,nd->child[L],nd->child[R]);
			root = nd;
		}else if(nd->val > root->val){
			Insert(root->child[R],nd);
		}else{
			Insert(root->child[L],nd);
		}
		
		root->Push_Up();
	}
	
	void Erase(Node *&root,const int &v){
		if(root == empty)
			return;
		
		if(v > root->val){
			Erase(root->child[R],v);
		}else if(v < root->val){
			Erase(root->child[L],v);
		}else{
			--root->fr;
			if(!root->fr){
				Node *ret = Merge(root->child[L],root->child[R]);
				delete root;
				root = ret;
			}
		}
		
		root->Push_Up();
	}
	
	int GetIndex(Node *root,int idx){ // Get Value in idx 0-Based
		if(root->sz <= idx) // invalid case
			return -1;
		
		int lsz = root->child[L]->sz;
		if(idx < lsz)
			return GetIndex(root->child[L],idx);
			
		int lsfr = lsz + root->fr;
		if(idx >= lsfr)
			return GetIndex(root->child[R],idx-lsfr);
		return root->val;
	}
	
	int Lower_Bound(Node *&rt,const int v){ // Get First Index Contain THis Val 0-Based
		Node *l,*r;
		Split(rt,v,l,r);
		
		int ret = l->sz;
		rt = Merge(l,r);
		return ret;
	}
	int Found(Node *&root,int v){ // Get First Index Contain THis Val 0-Based
		if(root == empty)
			return -1e9;
		
		if(root->val > v)
			return Found(root->child[L],v);
			
		int lsz = root->child[L]->sz;
		if(root->val == v)
			return lsz;
			
		return Found(root->child[R],v) + lsz + root->fr;
	}
	
	int Size(){
		return root->sz;
	}
	void print(Node *rt,int dpth=0){
	    if(rt == empty)
	        return;
	    print(rt->child[L],dpth+1);
	    printf("%s%2lld,%2d,%2d\n",string(dpth*5,' ').c_str(),rt->val,rt->sz,rt->fr);
	    print(rt->child[R],dpth+1);
	}
	
} TR;
 
 
 
 
int main() {
	//IO
	TR.init();
	int n,val;
	while(scanf("%d",&n) && n != -1){
		scanf("%d",&val);
		if(n == 1){
			TR.Insert(TR.root,new Node(val));
		}else if(n == 2){
			TR.Erase(TR.root,val);
		}else if(n == 3){
			printf("%d\n",max(-1,TR.Found(TR.root,val) + 1));
		}else{
			--val;
			if(val >= 0 && val < TR.Size())
				printf("%d\n",TR.GetIndex(TR.root,val));
			else
				puts("-1");
		}
	}
	
 
    return 0;
}   
