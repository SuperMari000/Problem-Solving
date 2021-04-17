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
const int N=2e5 + 5,M=(1<<8) + 1;
int F[N];
char str[N],pat[N];
 
int n,m,k,T;


int Failure(int len,char c){
	while(len && pat[len] != c) len = F[len-1];
	len += (pat[len] == c);
	return len;
}

void KMP_Table(){
	F[0] = 0;
	for(int i=1;i<k;i++)
		F[i] = Failure(F[i-1],pat[i]);
}


bool KMP(){
	int len = 0;
	int n = strlen(str);
	for(int i=0;i<n;++i){
		
		while(len && str[i] != pat[len]) len = F[len-1];
		len += (str[i] == pat[len]);
		
		if(len == k)
			return true;
	}
	return false;
}


int main(){
	
	scanf("%d",&T);
	while(T--){
		scanf("%s",str);
		scanf("%d",&n);
		while(n--){
			scanf("%s",pat);
			k = strlen(pat);
			printf("%c\n",KMP() ? 'y' : 'n');
		}
	}

}

