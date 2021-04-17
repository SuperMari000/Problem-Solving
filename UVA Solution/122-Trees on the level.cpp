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
int OO=1e9 + 1;
const int N=1e3 + 10;
char arr[N];
 
ll n,m,k,T,ans;
int a,b,c;
vector<pair<string,int>> vec;
map<string,bool> mp;


class Node{
	public:
		int val;
		int used;
		Node *left;
		Node *right;
		Node(){
			val = -1;
			used = 0;
			left = nullptr;
			right = nullptr;
		}
};

class Tree{
	public:
		Node *root;
		bool flage;
		void init(){
			Delete(root);
			root = new Node();
			flage = true;
		}
		
		void insert(int val,string path){
			if(!SZ(path)){
				root->val = val;
				root->used++;
				return;
			}
			Node *cur = root;
			reverse(path.begin(),path.end());
			while(SZ(path) > 1){
				if(path.back() == 'L'){
					if(cur->left == nullptr)
						cur->left = new Node();
					cur = cur->left;
				}else{
					if(cur->right == nullptr)
						cur->right = new Node();
					cur = cur->right;
				}
				path.pop_back();
			}
			
			if(path.back() == 'L'){
				if(cur->left == nullptr)
					cur->left = new Node();
				cur = cur->left;
				cur->val = val;
				cur->used++;
			}else{
				if(cur->right == nullptr)
					cur->right = new Node();
				cur = cur->right;
				cur->val = val;
				cur->used++;
			}
		}
		
		void preOrder(Node *root){
			if(root == nullptr)
				return;
			flage &= (root->used == 1);
			preOrder(root->left);
			preOrder(root->right);
		}
		
		void BFS(){
			if(!flage){
				puts("not complete");
				return;
			}
			vector<int> ans;
			queue<Node*> q;
			q.push(this->root);
			
			while(SZ(q)){
				auto it = q.front();
				q.pop();
				ans.push_back(it->val);
				
				if(it->left != nullptr)
					q.push(it->left);
				if(it->right != nullptr)
					q.push(it->right);
			}
			
			for(int i=0;i<SZ(ans);++i)
				printf("%d%c",ans[i]," \n"[i == SZ(ans)-1]);
		}
		
		void Delete(Node *root){
			if(root == nullptr)
				return;
			
			Delete(root->left);
			Delete(root->right);
			delete root;
		}
} BinaryTree;

bool read(){
	string str;
	while(~scanf("%s",arr)){
		str = arr;
		if(SZ(str) == 2)
			return true;
		str.pop_back();
		for(int i=0;i<SZ(str)-1;++i){
			if(str[i+1] == ',')
				str[i+1] = ' ';
			str[i] = str[i+1];
		}
		str.pop_back();
		istringstream iss(str);
		int val;
		string s;
		iss>>val>>s;
		vec.push_back({s,val});
	}
	return false;
}


int main(){
	
	while(read()){
		BinaryTree.init();
		for(auto it:vec)
			BinaryTree.insert(it.second,it.first);
		
		BinaryTree.preOrder(BinaryTree.root);
		BinaryTree.BFS();
				
		vec.clear();
	}
	
	
	
	
	
}

