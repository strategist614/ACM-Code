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
struct node
{
	int x;
	int y;
	int z;
}a[200];
int dp[200];
bool cmp(node a,node b)
{
	if(a.x == b.x) return a.y > b.y;
	return a.x > b.x;
}
int main ()
{
	int n;
	int flag = 0;
	while(scanf("%d",&n)!=EOF&&n)
	{
	  memset(dp,0,sizeof(dp)); 
      int tot = 0;
      for(int i= 1;i<=n;i++)
      {
      	int x,y,z;
      	read(x);
      	read(y);
      	read(z);
        a[++tot].x = x;
        a[tot].y = y;
        a[tot].z = z;
        a[++tot].x = x;
        a[tot].y = z;
        a[tot].z = y;
        a[++tot].x = y;
        a[tot].y = x;
        a[tot].z = z;
        a[++tot].x = y;
        a[tot].y = z;
        a[tot].z = x;
        a[++tot].x = z;
        a[tot].y = x;
        a[tot].z = y;
        a[++tot].x = z;
        a[tot].y = y;
        a[tot].z = x;
      }
      int ans =0 ;
      sort(a+1,a+1+tot,cmp);
      for(int i= 1;i<=tot;i++) dp[i] = a[i].z;
      for(int i= 1;i<=tot;i++)
      {
      	for(int j= i+1;j<=tot;j++)
      	{
      		if(a[i].x > a[j].x && a[i].y > a[j].y)
      		{
      		   dp[j] = max(dp[j],(dp[i]+a[j].z));
      		}
      	}
      	ans = max(ans,dp[i]);
      }
      printf("Case %d: maximum height = %d\n",++flag,ans);
	}
	return 0 ;
}
