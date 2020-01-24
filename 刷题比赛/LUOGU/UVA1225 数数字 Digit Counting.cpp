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
int vis[10];
int main ()
{
	int t;
    read(t);
    while(t--)
    {
    	int n;
    	cin>>n;
    	string s;
    	memset(vis,0,sizeof(vis));
    	for(int i= 1;i<=n;i++) 
    	{
    		s += to_string(i);
    	}
    	for(int i= 0;i<s.size();i++)
    	{
    		vis[s[i]-'0']++;
    	}
    	for(int i=0 ;i<10;i++)
    	{
    		if(i != 9) cout<<vis[i]<<" ";
    		else cout<<vis[i]<<endl;
    	}
    }
	return 0 ;
}
