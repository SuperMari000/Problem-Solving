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
 
 
ll MOD=998244353ll; 
const int N=1e1+ 1;
char arr[N][N];

int n,m,k;




string str="@IEHOVA#";
string mp[3]={"forth","left","right"};
int vec[N];


bool valid(int i,int j){
	return i>-1 && i<n && j>-1 && j<m;
}

void DFS(int u,int v,int idx){
	
	if(!valid(u,v) || str[idx] != arr[u][v])
		return;
		
	if(str[idx] == '#'){
		
		for(int i=0;i<idx;++i){
			if(i)
				printf(" ");
			printf("%s",mp[vec[i]].c_str());
		}
		
		puts("");
		return;
	}
	
	
	
	
	
	
	
	vec[idx]=0;
	DFS(u-1,v,idx+1);
	
	vec[idx]=1;
	DFS(u,v-1,idx+1);
	
	vec[idx]=2;
	DFS(u,v+1,idx+1);
	
	
}




int main(){

	int T=D();
	while(T--){
		
		scanf("%d%d",&n,&m);
		
		for(int i=0;i<n;++i)
			scanf("%s",arr+i);
			
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				if(arr[i][j] == '@')
					DFS(i,j,0);
		
	
	}
	
	
	
	

 
}
 
 
 
 
 
 
 
