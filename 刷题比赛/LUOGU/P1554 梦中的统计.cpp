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
string ans;
int vis[15];
int main ()
{
    int n,m;
    cin >> n>>m;
    for(int i= n;i<=m;i++)
    ans += to_string(i);
    for(int i= 0;i<ans.size();i++)
      vis[ans[i]-'0']++;
    for(int i= 0;i<=9;i++)
     cout<<vis[i]<<" ";	
	return 0 ;
}
