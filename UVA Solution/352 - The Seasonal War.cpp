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
ll OO=1e7;
const int N=50 + 5;
char arr[N][N];


int n,m,k,T;
int a,b,c,d;
int l,r,mid;

bool valid(int x,int y){
	return ~x && ~y && x<n && y<n;
}

bool DFS(int u,int v){
	if(!valid(u,v) || arr[u][v] != '1')
		return false;
	
	arr[u][v]  ='0';
	
	for(int x=-1;x<=1;++x)
		for(int y=-1;y<=1;++y)
			DFS(u+x,v+y);
	
	return true;
}



int main(){
	
	
	while(~scanf("%d",&n)){
		for(int i=0;i<n;++i)
			scanf("%s",arr+i);
		
		int cnt = 0;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				cnt+=DFS(i,j);
			

		printf("Image number %d contains %d war eagles.\n",++T,cnt);
	}

	
	
}
