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
const int N=2e6 + 10,M=100;
int pre[N];
 
 
int n,m,k,T;
int a,b,c,d;

struct Node {
	const static int N = 26;
	int num,pre;
	Node *chld[N];
	
	Node(){
		num = pre = 0;
		memset(chld,0,sizeof chld);
	}
	
	void addNode(int x){
		Node *&ret = chld[x];
		if(ret == nullptr)
			ret = new Node();
		ret->pre++;
	}
	
};

struct Trie {
	Node *root;
	Trie() : root(nullptr) {}
	void init(){
		Clear(root);
		root = new Node();
	}
	void Clear(Node *&rt){
		if(rt == nullptr) return;
		for(int i=0;i<rt->N;++i)
			Clear(rt->chld[i]);
		delete rt;
	}
	
	bool Insert(string &str){
		int idx = 0;
		bool flage = true;
		Node *rt = root;
		while(idx < SZ(str)){
			int x = str[idx] - '0';
			rt->addNode(x);
			rt = rt->chld[x];
			if(rt->num) flage = false;
			++idx;
		}
		rt->num++;
		return flage && rt->num == 1 && rt->pre == 1;
	}
	
	pair<int,int> Count(string &str){
		int idx = 0;
		Node *rt = root;
		while(idx < SZ(str) && rt != nullptr){
			int x = str[idx] - '0';
			rt = rt->chld[x];
			++idx;
		}
		if(rt == nullptr)
			return make_pair(0,0);
		return make_pair(rt->num,rt->pre);
	}
	
	
	bool Erase(string &str){
		if(!Search(str)) return false;
		int idx = 0;
		Node *rt = root;
		while(idx < SZ(str)){
			int x = str[idx] - '0';
			rt = rt->chld[x];
			--rt->pre;
			++idx;
		}
		rt->num--;
		return true;
	}
	
	int Search(string &str){
		return Count(str).first;
	}
	int Prefix(string &str){
		return Count(str).second;
	}
	
	
} TR;

 
int main(){
	IO
	
	string str;
	cin>>T;
	while(T--){
		cin>>n;
		TR.init();
		bool flage = true;
		for(int i=0;i<n;++i){
			cin>>str;
			flage &= TR.Insert(str);
		}
		cout<<(flage ? "YES" : "NO")<<endl;
	}
	
	
	return 0;
}
