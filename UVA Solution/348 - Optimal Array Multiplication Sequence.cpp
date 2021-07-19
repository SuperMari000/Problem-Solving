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
int OO=1e9;
const int N=50,M=1e3 + 5;


int n,m,k,cnt,SU,idx,len,MN,MX,cur,T;
int l,r,mid;

string str;

struct Node{
	int r,c;
	ll val;
	Node(){
		r = 1,c = 1;
		val = 0;
	}
	Node(int r,int c,ll v){
		this->val = v;
		this->r = r;
		this->c = c;
	}
	
	friend ostream& operator << (ostream& out, Node &s){
		out<<s.r<<" "<<s.c<<" "<<s.val<<"\n";
	    return out;
	}
};

vector<Node> arr;
Node dp[N][N];
int vis[N][N],vid;
Node operator + (const Node lt,const Node rt){
	Node ret;
	ret.val = 1ll * lt.r * lt.c * rt.c + lt.val + rt.val;
	ret.r = lt.r;
	ret.c = rt.c;
	return ret;
}

Node Solve(int l,int r){
	if(l == r)
		return arr[l];
	
	Node &ret = dp[l][r];
	int &vv = vis[l][r];
	if(vv == vid) return ret;
	vv = vid;
	
	ret = arr[l] + Solve(l+1,r);
	for(int i=l;i<r;++i){
		Node xx = Solve(l,i) + Solve(i+1,r);
		if(xx.val < ret.val)
			ret = xx;
	}
	
	return ret;
}

string TO_STR(int val){
	string ans;
	
	ostringstream oss(ans);
	oss<<val;

	return oss.str();
}

string Bulid(int l,int r){
	if(l == r)
		return "A" + TO_STR(l+1);
	
	Node ret = Solve(l,r);
	
	string ans = "";
	for(int i=l;i<r;++i){
		Node xx = Solve(l,i) + Solve(i+1,r);
		if(xx.val == ret.val && xx.c == ret.c && xx.r == ret.r){
			string lt = Bulid(l,i);
			string rt = Bulid(i+1,r);
			ans = "(";
			ans += lt;
			ans += " x ";
			ans += rt;
			ans += ")"; 
			break;
		}
	}
	
	return ans;
}


int main(){
	
	int ID = 1;
	while(scanf("%d",&n), n){
		arr = vector<Node>(n);
		for(int i=0;i<n;++i)
			scanf("%d%d",&arr[i].r,&arr[i].c);

		++vid;
		Solve(0,n-1);
		printf("Case %d: %s\n",ID++,Bulid(0,n-1).c_str());
	}
	
	return 0;
}
