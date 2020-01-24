#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int maxn = 1005;
const ull base1 = 133331;
const ull base2 = 233;
ull hasha[maxn][maxn], hashb[maxn][maxn], pow1[maxn], pow2[maxn];
char a[maxn][maxn], b[maxn][maxn];
int n, m, t, x, y;
vector<ull>v;

int main()
{
	//freopen("1.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int ans, cas = 0;
	pow1[0] = pow2[0] = 1;
	for (int i = 1; i <= 1001; i++) pow1[i] = pow1[i - 1] * base1, pow2[i] = pow2[i - 1] * base2;
	scanf("%d %d %d %d", &n, &m, &x, &y);
	v.clear();
	for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			hasha[i][j] = hasha[i][j - 1] * base1 + a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			hasha[i][j] += hasha[i - 1][j] * base2;
	for (int i = x; i <= n; i++)
		for (int j = y; j <= m; j++)
			v.push_back(hasha[i][j] - hasha[i][j - y]*pow1[y] - hasha[i - x][j]*pow2[x] + hasha[i - x][j - y]*pow1[y]*pow2[x]);
	sort(v.begin(), v.end());
	int t;
	scanf("%d", &t);
	while (t--)
	{
		for (int i = 1; i <= x; i++) scanf("%s", b[i] + 1);
		for (int i = 1; i <= x; i++)
			for (int j = 1; j <= y; j++)
				hashb[i][j] = hashb[i][j - 1] * base1 + b[i][j];
		for (int i = 1; i <= x; i++)
			for (int j = 1; j <= y; j++)
				hashb[i][j] += hashb[i - 1][j] * base2;
		int pos = lower_bound(v.begin(), v.end(), hashb[x][y]) - v.begin();
		if (pos == v.size()){
			puts("0");
			continue;
		}
		if (v[pos] == hashb[x][y])
			puts("1");
		else puts("0");
	}
	return 0;
}