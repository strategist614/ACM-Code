/*
独立思考
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
map<string,int> mp;
int main ()
{
    int n,m;
    cin>>n>>m;
    for(int i= 1;i<=n;i++)
    {
    	string s;
    	cin>>s;
    	string a;
    	while(getchar() == ' ')
    	{
    		cin>>a;
    		s += a;
    	}
    	mp[s] = 1;
    }    	
    int ans = 0;
    for(int i= 1;i<=m;i++)
    {
    	string s;
    	cin>>s;
    	string a;
    	while(getchar() == ' ')
    	{
    		cin>>a;
    		s += a;
    	}
    	if(mp[s]) ans ++;
    }
    cout<<ans<<endl;
	return 0 ;
}
