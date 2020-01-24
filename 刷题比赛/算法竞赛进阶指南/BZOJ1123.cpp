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
const int M = 5e5 + 5;
int head[N], ver[M * 2], Next[M * 2];
int low[N], dfn[N], tot, num;
int n, m;
int size[N];
ll ans[N];
bool cut[N];

void add(int x, int y) {
	ver[++tot] = y;
	Next[tot] = head[x];
	head[x] = tot;
}

void tarjan(int x) {
	low[x] = dfn[x] = ++num;
	size[x] = 1;
	int flag = 0;
	ll sum = 0;
	for (int i = head[x]; i; i = Next[i]) {
		int y = ver[i];
		if (!dfn[y]) {
			tarjan(y);
			low[x] = min(low[x], low[y]);
			size[x] += size[y];
			if (low[y] >= dfn[x]) {
				flag ++;
				ans[x] += (ll)size[y] * (n - size[y]);
				sum += size[y];
				if (i != 1 || flag > 1) cut[x] = true;
			}
		}
		else low[x] = min(low[x], dfn[y]);
	}
	if (cut[x]) ans[x] += 1ll * (n - 1) + (n - 1 - sum) * (1 + sum);
	else ans[x] = 2 * (n - 1);
}

int main ()
{
    read(n);
    read(m);
    tot = 1;
    for(int i =1;i <= m;i++){
    	int x,y;
    	read(x);
    	read(y);
    	if(x == y) continue;
    	add(x,y);
    	add(y,x);
    }
    tarjan(1);
    for(int i = 1;i <= n;i++)
    	printf("%lld\n",ans[i]);
	return 0 ;
}