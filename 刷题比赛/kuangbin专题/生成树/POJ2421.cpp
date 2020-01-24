#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct rec { int x, y, z; } edge[500010];
int fa[100010], n, m, ans;
int d[105][105];
bool operator <(rec a, rec b) {
	return a.z < b.z;
}
int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
int tot = 0;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> d[i][j];
		}
	int q;
	cin >> q;
	while (q--)
	{
		int a, b;
		cin >> a >> b;
		d[a][b] = d[b][a] = 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			edge[++tot].x = i;
			edge[tot].y = j;
			edge[tot].z = d[i][j];
		}
	sort(edge + 1, edge + tot + 1);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= tot; i++) {
		int x = get(edge[i].x);
		int y = get(edge[i].y);
		if (x == y) continue;
		fa[x] = y;
		ans += edge[i].z;
	}
	cout << ans << endl;
	return 0;
}