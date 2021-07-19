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
ll OO=1e7+7;
const int N=1e2 + 5,M = N << 1,K = 5;
char arr[N];
 
int n,m,k,cnt,SU,idx,len,T,lg;
int a,b,c,x,y;

string str,s;
vector<int> val;
vector<char> op;
void init(){
	s = "";
	val.clear();
	op.clear();
}

void Bulid(){
	int n = SZ(str);
	for(int i=0;i<n;++i){
		while(str[i] == ' ') ++i;
		int num = 0,f = 0;
		if(str[i] == '+') f = 1;
		if(str[i] == '-') f = -1;
		if(f) ++i;
		
		while(i < n && str[i] >= '0' && str[i] <= '9'){
			num *= 10;
			num += str[i] - '0';
			++i;
		}
		if(f) num *= f;
		val.push_back(num);
		while(str[i] == ' ') ++i;
		op.push_back(str[i]);
		if(str[i] == '='){
			++i;
        	while(str[i] == ' ') ++i;
        	s = str.substr(i);
        	break;
		}
		
	}
	
}

bool find(vector<char> &v){
	for(char c:v)
		if(c == '*' || c == '/')
			return true;
	return false;
}

int main(){
	
    bool flage = 0;
    while(getline(cin,str)){
        if(flage) puts("");
       
	    init();
        Bulid();
	
        while(SZ(val)){
			int n = SZ(val);
        	for(int i=0;i<n;++i){
        		if(i) printf(" ");
        		printf("%d %c",val[i],op[i]);
			}
        	printf(" %s\n",s.c_str());
        	bool pd = find(op);
        
        	
        	for(int i=0;i<n-1;++i){
        		if(pd){
        			if(op[i] != '*' && op[i] != '/') continue;
        			if(op[i] == '*') val[i] *= val[i+1];
        			if(op[i] == '/') val[i] /= val[i+1];
        			for(int j=i+1;j<n-1;++j)
        				val[j] = val[j+1];
        			while(i < n-1){
        				op[i] = op[i+1];
        				++i;
					}
					
				}else{
					if(op[i] != '+' && op[i] != '-') continue;
					if(op[i] == '+') val[i] += val[i+1];
        			if(op[i] == '-') val[i] -= val[i+1];
        			for(int j=i+1;j<n-1;++j)
        				val[j] = val[j+1];
        			while(i < n-1){
        				op[i] = op[i+1];
        				++i;
					}
				}
			}
			val.pop_back();
			op.pop_back();

		}
        
        flage = 1;
    }
	
	return 0;
}

