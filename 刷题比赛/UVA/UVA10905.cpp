/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
	x = 0;
	char c = getchar();
	int sgn = 1;
	while(c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=sgn;
}
template <typename T>
void out(T x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>=10)out(x/10);
	putchar(x%10+'0');
}
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b ?gcd(b,a%b):a;}
string s[55];
string str[55];
int tot = 0;
std::vector<char> v;
map<char,int> mp;
bool cmp(string a,string b){ 
	return a > b;
}

int main ()
{
	int n;
	while(~scanf("%d",&n) && n){
		v.clear();
		mp.clear();
		tot = 0;
		for(int i =1;i <=n;i++){
			cin>>s[i];
			if(s[i].size() == 1) 
			{
				v.push_back(s[i][0]);
			}
			else str[++tot] = s[i];
		}
		sort(s+1,s+n+1,cmp);
        for(int i = 0; i < v.size();i++)
        {
        	mp[v[i]]++;
        }
        for(int i = 1;i <= n;i++){
            if(s[i].size() == 1){
                  
            }
        }  
        //cout<<ans<<endl;
	}
	return 0 ;
}