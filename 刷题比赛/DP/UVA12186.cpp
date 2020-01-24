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
const int N = 1e5 + 5;
int n, T;
std::vector<int> g[N];
int f[N];
void add(int x, int y)
{
	g[x].push_back(y);
}
void dp(int x)
{
	if(g[x].size() == 0) {
	    f[x] = 1;
		return;
	}
	int size = g[x].size();
	std::vector<int> v;
	for(int i = 0;i < g[x].size();i++)
	{
        int y = g[x][i];
        dp(y);
        v.push_back(f[y]);
	}
	int c = (size * T - 1) / 100 + 1;
	sort(v.begin(),v.end());
	for(int i= 0;i < c;i++)
		f[x] += v[i];
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	while (~scanf("%d %d", &n, &T))
	{
		memset(f,0,sizeof(f));
		for(int i= 0;i <= n;i++)
              g[i].clear();
		if (n == 0 && T == 0) break;
		for (int i = 1; i <= n; i++)
		{
			int fa;
			read(fa);
			add(fa, i);
		}
		dp(0);
		printf("%d\n",f[0]);
	}
	return 0 ;
}