/*
独立思考
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
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
const int N = 1005;
struct node
{
	int st;
	int ed;
	int m;
}a[N];
bool cmp(node a,node b)
{
	if(a.st == b.st) return a.ed < b.ed;
	return a.st < b.st;
}
ll dp[N];
int main ()
{
	ll ans = 0;
	int n,m,r;
	cin>>n>>m>>r;
	for(int i= 1;i<=m;i++) 
	{
		read(a[i].st);
		read(a[i].ed);
		read(a[i].m);
	}
	sort(a+1,a+m+1,cmp);
	for(int i= 1;i<=m;i++) dp[i] = a[i].m;
	for(int i =1;i<=m;i++)
	{
		for(int j= i+1;j<=m;j++)
		{
           if(a[j].st >= a[i].ed + r)
           {
              dp[j] = max(dp[j],dp[i]+a[j].m);
           }
		} 
		ans = max(ans,dp[i]);
	}
    cout<<ans<<endl;
	return 0 ;
}