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
const int N = 1e5+5;
int dp[N][12];
int cnt[N][12];
struct node
{
	int t;
	int x;
}a[N];
int main ()
{
	int n;
	while(cin>>n && n)
	{
	memset(dp,0,sizeof(dp));
	memset(cnt,0,sizeof(cnt));
	int maxn = 0;
	for(int i= 1;i<=n;i++) 
	{
       read(a[i].x);
       read(a[i].t);
	   dp[a[i].t][a[i].x]++;
	   maxn = max(maxn,a[i].t);
	}
	for(int i = maxn-1;i >= 0;i--)
	{
       for(int j= 0;j <= 10;j++)
       {
       	  dp[i][j] += max(max(dp[i+1][j-1],dp[i+1][j]),dp[i+1][j+1]);
       }
	}
	cout<<dp[0][5]<<endl;
   }
	return 0 ;
}
