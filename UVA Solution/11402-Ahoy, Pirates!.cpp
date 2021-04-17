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
const int N=1e5 + 10,M=10;
int arr[N][M],pre[M];
 
 
int n,m,k,T;
int a,b,c,d;
string str,s;
int ID;
 
struct Node{
	int one,zero;
	pair<int,int> rev,clr;
	Node(){
		one = zero = 0;
		rev = clr = make_pair(-1,0);
	}
	
	Node(char vv){
		one = (vv == '1');
		zero = (vv == '0');
		rev = clr = make_pair(-1,0);
	}
	
	void addLazyclr(int l,int r,pair<int,int> pp){
		if(pp.second){
			one = (r - l + 1);
			zero = 0;
		}else{
			one = 0;
			zero = (r - l + 1);
		}
		clr = pp;
	}
	
	void addLazyrev(int id){
		swap(one,zero);
		if(clr.first != rev.first && clr.first > rev.first && clr.first < id)
			rev.second = 1;
		else
			rev.second ^= 1;
		
		rev.first = id;
	}

	
	friend ostream& operator << (ostream& out, Node &s1){
		out<<s1.one<<" "<<s1.zero<<" Clr -> "<<s1.clr.first<<"\n";
	    return out;
	}
};

Node operator + (const Node lt,const Node rt){
	Node cur;
	cur.one = lt.one + rt.one;
	cur.zero = lt.zero + rt.zero;
	return cur;
}
 
 
struct SegmetTree{
	vector<Node> seg;
	void init(int n){
		seg.resize(4*n);
	}
	
	void PushDown(int pos,int l,int r){
		Node &cur = seg[pos];
		if(l == r || (cur.clr.first == -1 && !cur.rev.second)) return;
		int mid = (l+r) >> 1;
		if(cur.clr.first == -1){
			seg[2*pos].addLazyrev(cur.rev.first);
			seg[2*pos+1].addLazyrev(cur.rev.first);
		}else if(!cur.rev.second){
			seg[2*pos].addLazyclr(l,mid,cur.clr);
			seg[2*pos+1].addLazyclr(mid+1,r,cur.clr);
		}else if(cur.clr.first != -1 && cur.rev.second){
			if(cur.clr.first < cur.rev.first){
				seg[2*pos].addLazyclr(l,mid,cur.clr);
				seg[2*pos+1].addLazyclr(mid+1,r,cur.clr);
				seg[2*pos].addLazyrev(cur.rev.first);
				seg[2*pos+1].addLazyrev(cur.rev.first);
			}else{
				seg[2*pos].addLazyclr(l,mid,cur.clr);
				seg[2*pos+1].addLazyclr(mid+1,r,cur.clr);
			}
		}
		
		cur.rev = cur.clr = make_pair(-1,0);
	}
	
	void Bulid(int l,int r,int pos){
		
		if(l == r){
			seg[pos] = Node(str[l]);
			return;
		}
			
		int mid = (l+r) >> 1;
		Bulid(l,mid,2*pos);
		Bulid(mid+1,r,2*pos+1);
		
		seg[pos] = seg[2*pos] + seg[2*pos+1];
	}
	
	void Print(int l,int r,int pos){
		PushDown(pos,l,r);
		cout<<"["<<l<<" , "<<r<<"] ";
		cout<<seg[pos];
		
		if(l == r)
			return;
		
		int mid = (l+r) >> 1;
		Print(l,mid,2*pos);
		Print(mid+1,r,2*pos+1);
	}
	
	void UpdateClr(int l,int r,int pos,int st,int en,int v){
		if(st > r || en < l || st > en)
			return;
		
		PushDown(pos,l,r);
		if(l >= st && r <= en){
			seg[pos].addLazyclr(l,r,make_pair(ID,v));
			return;
		}
		
		int mid = (l+r)>>1;
		
		UpdateClr(l,mid,2*pos,st,en,v);
		UpdateClr(mid+1,r,2*pos+1,st,en,v);
		
		seg[pos] = seg[2*pos] + seg[2*pos+1];
 
	}
	
	void UpdateRev(int l,int r,int pos,int st,int en){
		if(st > r || en < l || st > en)
			return;
		
		PushDown(pos,l,r);
		if(l >= st && r <= en){
			seg[pos].addLazyrev(ID);
			return;
		}
		
		int mid = (l+r)>>1;
		
		UpdateRev(l,mid,2*pos,st,en);
		UpdateRev(mid+1,r,2*pos+1,st,en);
		
		seg[pos] = seg[2*pos] + seg[2*pos+1];
 
	}
	
	int Query(int l,int r,int pos,int st,int en){
		if(st > r || en < l || l > r)
			return 0;
		PushDown(pos,l,r);
		if(l >= st && r <= en)
			return seg[pos].one;
		
		int mid = (l+r)>>1;
		int lt = Query(l,mid,pos<<1,st,en);
		int rt = Query(mid+1,r,pos<<1 | 1,st,en);

		return lt + rt;
	}
	
} ST;



int main(){
	
	IO
	cin>>T;
	for(int ll=0;ll<T;++ll){
		cout<<"Case "<<ll+1<<":\n";
		str = s = "";
		ID=0;
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>k;
			cin>>s;
			while(k--)
				str += s;
		}
		n = SZ(str);
		ST.init(n);
		ST.Bulid(0,n-1,1);

		cin>>k;
		int a,b;char c;
		int lvl = 0;
		while(k--){
			++ID;
			cin>>c>>a>>b;
			switch(c){
				case 'F' :
					ST.UpdateClr(0,n-1,1,a,b,1);
					break;
				case 'E' :
					ST.UpdateClr(0,n-1,1,a,b,0);
					break;
				case 'I' :
					ST.UpdateRev(0,n-1,1,a,b);
					break;
				case 'S' :
					cout<<"Q"<<++lvl<<": "<<ST.Query(0,n-1,1,a,b)<<endl;
					break;
			}
		}
	}
 
	return 0;
}
 
  
