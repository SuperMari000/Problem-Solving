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
 
 
 
ll MOD=1e9;
int OO=1e8;
const int N=1e4 + 5,M= N << 1;

int n,m,k,SU,idx,len,MN,MX,T;
int l,r,mid,ans;
int a,b,c;



struct Node{
	int n,m;
	vector<vector<ll>> arr;
	Node(){
	}
	Node(int n,int m){
		arr = vector<vector<ll>>(n,vector<ll>(m));
		this->n = n;
		this->m = m;
	}
	Node(vector<vector<ll>> v){
		arr = v;
		n = v.size();
		m = v.front().size();
	}
	
	void IDE(){
		for(int i=0;i<n;++i){
			arr[i] = vector<ll>(m,0);
			arr[i][i] = 1;
		}
	}
	
	
	friend ostream& operator << (ostream& out, Node &s){
		out<<s.arr[0][0];
	    return out;
	}
};


Node operator * (const Node lt,const Node rt){
	Node ret = Node(lt.n,rt.m);
	for(int i=0;i<lt.n;++i){
		for(int j=0;j<rt.m;++j){
			for(int k=0;k<lt.m;++k){
				ret.arr[i][j] += lt.arr[i][k] * rt.arr[k][j];
				ret.arr[i][j] %= MOD;
			}
		}
	}
	return ret;
}

Node Power(Node n,ll m,int MOD){
	
	Node ret = Node(n.n,n.m);
	ret.IDE();
	
	while(m > 0){
		if(m&1)
			ret =  n * ret;
		
		n = n * n;
		m >>= 1ll;
	}
	
	return ret;
}



int main(){
	IO
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	cin>>T;
	while(T--){
		cin>>k;
		Node ret = Node(k,k);
		Node B = Node(k,1);
		for(int i=0;i<k;++i)
			cin>>B.arr[k-i-1][0];
		for(int i=0;i<k;++i)
			cin>>ret.arr[0][i];
		cin>>n;
		
		
		for(int i=1;i<k;++i)
			ret.arr[i][i-1] = 1;
		
		if(n <= k){
			cout<<B.arr[n-1][0]<<endl;
			continue;
		}
		ret = Power(ret,n-k,MOD);

		ret = ret * B;
		
		cout<<ret<<endl;
		
	}
	
	return 0;
}

