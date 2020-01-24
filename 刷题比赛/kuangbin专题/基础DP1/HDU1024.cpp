/*
独立思考
*/
/*
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
const int N = 1e6+6;
const int INF = 0x7fffffff;
int dp[N];
int maxx[N];
int a[N];
int main ()
{
	int n,m;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		memset(maxx,0,sizeof(maxx));
        for(int i= 1;i<=n;i++) read(a[i]);
        int maxn = 0;
        for(int i= 1;i<=m;i++)
        {
           maxn = -INF;
           for(int j= i;j<=n;j++)
           {
           	  dp[j] = max(dp[j-1]+a[j],maxx[j-1]+a[j]);
           	  maxx[j-1] = maxn;
           	  maxn = max(maxn,dp[j]);
           }
        }
        cout<<maxn<<endl;
	}
	return 0 ;
}
*/
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
const int N = 1e6+6;
const int INF = 0x7fffffff;
int dp[N];
int maxx[N];
int a[N];
int main ()
{
	int n,m;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		memset(maxx,0,sizeof(maxx));
        for(int i= 1;i<=n;i++) read(a[i]);
        int maxn = 0;
        for(int i= 1;i<=m;i++)
        {
           maxn = -INF;	
           for(int j= i;j<=n;j++)
           {
           	  dp[j] = max(dp[j-1]+a[j],maxx[j-1]+a[j]);
           	  maxx[j-1] = maxn;
           	  cout<<maxx[j-1]<<endl;
           	  maxn = max(maxn,dp[j]);
           }
        }
	}
	return 0 ;
}
/*
  i = 1:
  j = 1
  dp[1] = -1
  pre[0] = -inf
  maxn = -1 
  j = 2
  dp[2] = 4	
  pre[1] = -1
  maxn = 4
  j = 3
  dp[3] = 2
  pre[2] = 4
  maxn = 4
  j = 4
  dp[4] = 5
  pre[3] = 4
  maxn = 5
  j = 5
  dp[5] = 3
  pre[4] = 5
  maxn = 5
  j = 6
  dp[6] = 6
  pre[5] = 5
  maxn = 6
  i = 2
  j = 2
  dp[2] = 3
  pre[1] = -inf
  maxn = 3
  j = 3
  dp[3] = 2
  pre[2] = 3
  maxn = 3
  j = 4
  dp[4] = 7
  pre[3] = 3
  maxn = 7
  j = 5
  dp[5] = 5
  pre[4] = 7
  maxn = 7
  j = 6
  dp[6] = 8
  pre[5] = 7
  maxn = 8
*/