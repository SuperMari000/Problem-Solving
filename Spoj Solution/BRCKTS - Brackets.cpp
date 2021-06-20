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
 
 
 
ll MOD=1e9 + 9;
int OO=1e9+7;
const int N=1e5 + 5;
int n,m,k,T;
int a,b,c,lg;
char str[N];
 
struct Node{
	int lt,rt,cnt;
	Node(){
		lt = rt = cnt = 0;
	}
	
	Node(char ch){
		lt = (ch == '(');
		rt = (ch == ')');
		cnt = 0;
	}
 
	friend ostream& operator << (ostream& out, Node &s){
		out<<s.lt<<" "<<s.rt<<" "<<s.cnt<<"\n";
	    return out;
	}
};
 
Node operator + (const Node &l,const Node &r){
	Node ret;
	int mn = min(l.lt,r.rt);
	
	ret.cnt = l.cnt + r.cnt;
	ret.cnt += mn;
	ret.lt = l.lt + r.lt - mn;
	ret.rt = l.rt + r.rt - mn;
	return ret;
}
 
struct SegmentTree{
	vector<Node> seg;
	void init(int n){
		seg = vector<Node>(n << 2);
	}
	
	void Bulid(int l,int r,int pos){
		if(l == r){
			seg[pos] = Node(str[l]);
			return;
		}
			
		int mid = (l+r) >> 1;
		Bulid(l,mid,pos << 1);
		Bulid(mid+1,r,pos << 1 | 1);
		
		seg[pos] = seg[pos << 1] + seg[pos << 1 | 1];
	}
	
	void Update(int l,int r,int pos,int idx){
		if(l == r){
			swap(seg[pos].lt,seg[pos].rt);
			return;
		}
		
		int mid = (l + r) >> 1;
		if(idx > mid)
			Update(mid + 1,r, pos << 1 | 1,idx);
		else
			Update(l,mid,pos << 1,idx);
		
		seg[pos] = seg[pos << 1] + seg[pos << 1 | 1];
	}
	
	
	bool Check(){
		return (seg[1].lt + seg[1].rt) == 0;
	}
	
} ST;
 
 
int main() {
 
	int ID = 1;
	while(~scanf("%d",&n)){
		printf("Test %d:\n",ID++);
		
		scanf("%s",str);
		ST.init(n);
		ST.Bulid(0,n-1,1);
		
		scanf("%d",&T);
		int tp;
		while(T--){
			scanf("%d",&tp);
	
			if(!tp)
				puts(ST.Check() ? "YES" : "NO");
			else
				ST.Update(0,n-1,1,tp - 1);
		}
	}
	
	return 0;
} 
