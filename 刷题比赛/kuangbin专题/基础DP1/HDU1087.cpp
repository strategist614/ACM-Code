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
const int N = 1005;
int a[N];
int cnt = 0;
int n;
void dfs(int dep,int ans)
{
	if(dep == n){cnt = max(ans,cnt);return;}
	for(int i= dep+1;i<=n;i++)
	{
		if(a[i] > a[dep]){
			dfs(i,ans+a[i]);
		}
	}
	cnt = max(ans,cnt);
	return ;
}
int main ()
{
	//int n;
    while(scanf("%d",&n)!=EOF && n)
    {
    	cnt = 0;
    	for(int i= 1;i<=n;i++) read(a[i]);
        dfs(0,0);
        cout<<cnt<<endl;
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
const int N = 1005;
int a[N];
int dp[N];
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		memset(dp,0,sizeof(dp));
		for(int i= 1;i<=n;i++) read(a[i]);
		int ans = 0;
		for(int i= 0;i<=n;i++)
		{
			for(int j= i+1;j<=n;j++)
		    {
		    	if(a[i] < a[j])
		    	{
		    		dp[j] = max(dp[j],dp[i]+a[j]);
		    	}
		    }
		    ans = max(ans,dp[i]);
		}
		cout<<ans<<endl;
	}
	return 0 ;
}
	