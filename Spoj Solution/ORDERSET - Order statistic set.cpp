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
const int N=270 + 5,M=(1<<8) + 1;
int arr[N];
 
int n,m,k;
 
 
typedef int TN;
extern struct Node *empty;
enum DIR{L,R};
 
struct Node{
	
	TN val;
	int p,sz,freq;
	Node *child[2];
	
	Node() : val(0), sz(0), freq(0), p(INT_MIN), child({this,this}){}
	Node(TN v,Node *lt = empty,Node *rt = empty){
		val = v;
		freq = sz = 1;
		p = rand() * rand();
		child[L] = lt;
		child[R] = rt;
	}
 
	void Push_Up(){
		sz = freq;
		for(Node *ch:child)
			sz += ch->sz;
	}
};
 
Node *empty = new Node();
 
struct Treap{
	Node *root;
	Treap() : root(empty) {}
	void init(){
		Clear(root);
		root = empty;
	}
	void Clear(Node *&root){
		if(root == nullptr || root == empty)
			return;
		Clear(root->child[L]);
		Clear(root->child[R]);
		delete root;
	}
	
	void Split(Node *root,const TN v,Node *&lt,Node *&ge){
		
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
	
	void Insert(Node *&root,const TN v){
 
		Node *before, *between, *after;
		Split(root,v,before,between);
		Split(between,v+1,between,after);
		
		if(between == empty){
			between = new Node(v);
		}else{
			between->freq++;
			between->sz++;
		}
			
		root = Merge(before,Merge(between,after));
	}
	
	void Erase(Node *&root,const TN v){
 
		Node *before, *between, *after;
		Split(root,v,before,between);
		Split(between,v+1,between,after);
		
		if(between != empty){
			between->freq--;
			between->sz--;
			if(!between->freq){
				delete between;
				between = empty;
			}
		}
			
		root = Merge(before,Merge(between,after));	
	}
	
	TN GetByIndex(Node *root,int idx){ // Get Value in idx 0-Based
		if(root->sz <= idx) // invalid case
			return -1;
		
		int lsz = root->child[L]->sz;
		if(idx < lsz)
			return GetByIndex(root->child[L],idx);
			
		lsz += root->freq;
		if(idx >= lsz)
			return GetByIndex(root->child[R],idx - lsz);
		return root->val;
	}
	
	pair<int,int> Count(Node *&root,TN v){ // Get First Index Contain THis Val 0-Based And freqeq of value
		
		Node *before, *between, *after;
		Split(root,v,before,between);
		Split(between,v+1,between,after);
		
		pair<int,int> ret;
		ret.first = before->sz; // lower bound
		ret.second = between->freq; // frequance of value
		
		root = Merge(before,Merge(between,after));
 
		return ret;
	}
	
	void print(Node *rt,int dpth=0){
	    if(rt == empty)
	        return;
	    print(rt->child[L],dpth+1);
	    printf("%s%2lld,%2d,%2d\n",string(dpth*5,' ').c_str(),rt->val,rt->sz,rt->freq);
	    print(rt->child[R],dpth+1);
	}
	
	
	void Insert(TN v){
		Insert(root,v);
	}
	
	void Erase(TN v){
		Erase(root,v);
	}
	
	int Count(TN v){
		return Count(root,v).second;
	}
	
	TN operator [] (int idx){ // Zero-Based
		if(idx >= 0 && idx < Size())
			return GetByIndex(root,idx);
		puts("Invalid");
		return -1;
	}
	
	int Lower_Bound(TN v){ // Zero-Based
		return Count(root,v).first;
	}
	
	int Upper_Bound(TN v){ // Zero-Based
		return Count(root,v + 1).first;
	}
 
	int Size(){
		return root->sz;
	}
	
} TR;
 
 
int main() {
	//IO
	TR.init();
	char type;
	int n,val;
    scanf("%d",&n);
    while(n--){
        scanf(" %c %d",&type,&val);
        switch (type)
        {
            case 'I':
                if(TR.Count(val) == 0)
                	TR.Insert(val);
                break;
            case 'D':
            	TR.Erase(val);
                break;
            case 'K':
                if(val > TR.Size())
                    puts("invalid");
                else
                    printf("%d\n",TR[val - 1]);
                break;
            case 'C':
                printf("%d\n",TR.Lower_Bound(val));
                break;
        }
    }
	
	
    return 0;
}  
