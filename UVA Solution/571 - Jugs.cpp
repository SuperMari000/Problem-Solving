//        Mostafa Mounir Shehab
 
#include <bits/stdc++.h>
using namespace std;
 
#define PI  3.14159265  // PI = acos(-1)
#define EPS (1e-10)
#define endl "\n"
#define SZ(v) (int)(v.size())
typedef long long ll;
typedef long double ld;
//template <class Type>
 

inline int D(){
	int t;
	scanf("%d",&t);
	return t;
}
inline ll llD(){
	ll t;
	scanf("%lld",&t);
	return t;
}
 
 
ll MOD=1e9 + 7; 
const int N=1e2+ 5;

map<pair<int,int>,bool> mp;
map<int,string> ans;
stack<int> st;

int n,m,k,MN;
bool flage;

void DFS(pair<int,int> p,int idx,bool &flage){

	if(flage || mp[p])
		return;
		
	flage|=(p.second == k && !p.first);
	mp[p]=true;
	
	DFS({n,p.second},1,flage);
	DFS({p.first,m},2,flage);
	
	DFS({0,p.second},3,flage);
	DFS({p.first,0},4,flage);
	
	MN=min(m-p.second,p.first);
	DFS({p.first-MN,p.second+MN},5,flage);
	
	MN=min(n-p.first,p.second);
	DFS({p.first+MN,p.second-MN},6,flage);
	
	st.push(idx);
}


int main(){
	
	ans[1]="fill A";
	ans[2]="fill B";
	ans[3]="empty A";
	ans[4]="empty B";
	ans[5]="pour A B";
	ans[6]="pour B A";



	
	while(scanf("%d%d%d",&n,&m,&k) != EOF){
		mp=map<pair<int,int>,bool>();
		flage=false;
		
		DFS({0,0},-1,flage);
		
		st.pop();
		while(SZ(st)){
			printf("%s\n",ans[st.top()].c_str());
			st.pop();
		}
			
		puts("success");
		
	}

		
	
	
	

 
}
 
 
 
 
 
 
 
