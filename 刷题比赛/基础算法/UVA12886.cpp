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
const int N = 2005;
const ull base1 = 133331;
const ull base2 = 233;
char a[N][N], b[N][N];
ull hasha[N][N], hashb[N][N];
ull pow1[N], pow2[N];
std::vector<ull> v;
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n, m, x, y;
	pow1[0] = pow2[0] = 1;
		for (int i = 1; i <= 2001; i++) pow1[i] = pow1[i - 1] * base1, pow2[i] = pow2[i - 1] * base2;
	while (~scanf("%d %d %d %d", &x, &y, &n, &m)) {
		v.clear();
		for (int i = 1; i <= x; i++)
		{
			scanf("%s", b[i] + 1);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%s", a[i] + 1);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				hasha[i][j] = hasha[i][j - 1] * base1 + a[i][j];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				hasha[i][j] += hasha[i - 1][j] * base2;
		}
		for (int i = x; i <= n; i++)
			for (int j = y; j <= m; j++)
				v.push_back(hasha[i][j] - hasha[i][j - y]*pow1[y] - hasha[i - x][j]*pow2[x] + hasha[i - x][j - y]*pow1[y]*pow2[x]);
		sort(v.begin(), v.end());
		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++)
				hashb[i][j] = hashb[i][j - 1] * base1 + b[i][j];
		}
		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++)
				hashb[i][j] += hashb[i - 1][j] * base2;
		}
		int ans = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (hashb[x][y] == v[i]) ans ++;
		}
		printf("%d\n", ans);
	}
	return 0 ;
}