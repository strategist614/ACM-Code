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
const int N = 1005;
char a[N], b[N];
int f[N], Next[N];
std::vector<int> v;
void solve()
{
	v.clear();
	memset(Next, 0, sizeof(Next));
	memset(f, 0, sizeof(f));
	int n = strlen(a + 1);
	int m = strlen(b + 1);
	Next[1] = 0;
	for (int i = 2, j = 0; i <= n; i++)
	{
		while (j > 0 && a[i] != a[j + 1]) j = Next[j];
		if (a[i] == a[j + 1]) j++;
		Next[i] = j;
	}
	for (int i = 1, j = 0; i <= m; i++)
	{
		while (j > 0 && (j == n || b[i] != a[j + 1])) j = Next[j];
		if (b[i] == a[j + 1]) j++;
		f[i] = j;
		if (f[i] == n) v.push_back(i - n + 1);
	}
	if (v.size() == 0) cout << 0 << endl;
	else {
		int ans = 1;
		int st = v[0];
		for (int i = 1; i < v.size(); i++)
		{
			if (v[i] < st + n) continue;
			if (v[i] >= st + n) {st = v[i]; ans++;}
		}
		cout << ans << endl;
	}
}
int main ()
{
	while (scanf("%s", b + 1) != EOF)
	{
		if (b[1] == '#') break;
		scanf("%s", a + 1);
		solve();
	}
	return 0 ;
}