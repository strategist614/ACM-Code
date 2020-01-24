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
int cnt[40];
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(cnt,0,sizeof(cnt));
		for(int i= 1;i<=n;i++)
		{
			int x;
			read(x);
			bitset<32> b(x);			
			for(int i= 0;(1<<i)<=x;i++)
			{
				if(b[i] == 1)
                   cnt[i]++;
			}
		}
		int ans = 0;
		for(int i =0;i<32;i++)
		{
			if(cnt[i] >= (n+1)/2)
	         ans += 1 << i;
		}
		cout<<ans<<endl;
	}
	return 0 ;
}
*/
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
int main ()
{
	int n;
    while(cin>>n)
    {
    int ans = 0;
    int count = 0;
    for(int i= 1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(count == 0)
        {
       	   ans = x;
       	   count = 1;
        }
        else 
        {
       	 if(ans == x) count++;
         else count--;
        }
    }
    cout<<ans<<endl;
}
	return 0 ;
}
*/
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
const int N = 1e6+5;
//std::vector<pair<int,int>> vis(N);
int vis[N];
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(vis,0,sizeof(vis));
		int maxn = 0;
		for(int i =1;i<=n;i++) 
		{
			int x;
			read(x);
			vis[x]++;
		}
		for(int i =1;i<=N;i++)
		{
			if(vis[i] >= (n+1)/2)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0 ;
}
*/
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
const int N = 1e6+5;
int dp[N];
int vis[N];
int a[N];
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		for(int i = 1;i<=n;i++) read(a[i]);
		for(int i = 1;i<=n;i++)
		{
			vis[a[i]]++;
			dp[i] = max(dp[i-1],vis[a[i]]);
		}
		cout<<dp[n]<<endl;
 	}
	return 0 ;
}
*/
