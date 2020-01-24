#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1010][1010], d[1010];
bool v[1010];

int main() {
	int t;
	cin >> t;
	int flag = 0;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= m; i++) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			a[x][y] = z;
			a[y][x] = z;
		}
		for (int i = 1; i <= n; i++) d[i] = a[1][i];
		memset(v, 0, sizeof(v));
		for (int i = 1; i <= n; i++) {
			int x = 0;
			int maxn = -1;
			for (int j = 1; j <= n; j++)
			{
				if (!v[j] && d[j] > maxn)
				{
					maxn = d[j];
					x = j;
				}
			}
			v[x] = 1;
			for (int y = 1; y <= n; y++)
			{
				if (!v[y] && d[y] < min(d[x], a[x][y]))
				{
					d[y] = min(d[x], a[x][y]);
				}
			}
		}
		printf("Scenario #%d:\n", ++flag);
		printf("%d\n\n", d[n]);
	}
	return 0 ;
}
