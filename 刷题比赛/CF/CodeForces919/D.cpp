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
	while (c < '0' || c > '9') {if (c == '-')sgn = -1; c = getchar();}
	while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
	x *= sgn;
}
template <typename T>
void out(T x)
{
	if (x < 0) {putchar('-'); x = -x;}
	if (x >= 10)out(x / 10);
	putchar(x % 10 + '0');
}
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 3e5 + 5;
int dp[N];
int a[N], cnt =  0, tot = 0;
int ver[N], Next[N], head[N], deg[N];
int n, m;
char s[N];

void add(int x, int y)
{
	ver[++tot] = y;
	Next[tot] = head[x];
	head[x] = tot;
	deg[y]++;
}

void topsort()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (deg[i] == 0) q.push(i);
	while (q.size())
	{
		int x = q.front();
		q.pop();
		a[++cnt] = x;
		for (int i = head[x]; i; i = Next[i])
		{
			int y = ver[i];
			if (--deg[y] == 0) q.push(y);
		}
	}
}

int solve(int x)
{
	memset(dp,0,sizeof(dp));
	char c = x + 'a';
	int ans = 0;
	for(int i = cnt;i >= 1;i--)
	{
	   int u = a[i];
       for(int j = head[u];j;j = Next[j])
       {
       	  int v = ver[j];
       	  dp[u] = max(dp[u],dp[v]);
       }
       if(s[u] == c) dp[u]++;
       ans = max(ans,dp[u]);
	}
	return ans;
}

int main ()
{
	read(n);
	read(m);
	scanf("%s", s + 1);
	for(int i =1;i <= m;i++)
	{
		int x,y;
		read(x);
		read(y);
		add(x,y);
	}
	topsort();
	if(cnt < n)
	{
		cout<<-1<<endl;
		return 0;
	}
	//for(int i =1;i <= n;i++) cout<<a[i]<<endl;
	int ans = 0;
	for(int i =0;i < 26;i++)
	{
        ans = max(ans,solve(i));
	}
	cout<<ans<<endl;
	return 0 ;
}