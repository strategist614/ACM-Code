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
const int N = 1005;
struct node
{
	int w;
	int v;
	int id;
} a[N];
bool cmp(node a, node b)
{
	if (a.w == b.w) return a.v > b.v;
	return a.w < b.w;
}
int dp[N];
std::vector<int> v;
int vis[N];
int main ()
{
	memset(dp,0,sizeof(dp));
	memset(vis,-1,sizeof(vis));
	int tot = 1;
	while(scanf("%d %d",&a[tot].w,&a[tot].v)!=EOF)
	{
		a[tot].id = tot;
		tot++;
	}
	sort(a + 1, a + tot + 1, cmp);
	int ans = 0;
	int st = 0;
	for (int i = 1; i <= tot; i++) {
		dp[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (a[i].v < a[j].v && a[i].w != a[j].w)
			{
				if(dp[j] + 1 > dp[i])
				{
					dp[i] = dp[j]+1;
			        vis[i] = j;		
				}
			}
		}
		if(dp[i] > ans)
		{
			ans = dp[i];
			st = i;
		}
	}
	while(st != -1)
	{
		v.push_back(a[st].id);
		st = vis[st];
	}
	cout<<ans<<endl;
	for(int i = v.size()-1;i >= 0;i--)
		cout<<v[i]<<endl;
	return 0;
}