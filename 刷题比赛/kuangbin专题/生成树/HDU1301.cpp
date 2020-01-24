#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct rec { int x, y, z; } edge[500010];
int fa[100010], n, m, ans;
bool operator <(rec a, rec b) {
	return a.z < b.z;
}
int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF && n) {
		int tot = 0;
		ans = 0;
		for (int i = 1; i <= n-1; i++)
		{
			char c;
			int x;
			cin >> c >> x;
			int st = c - 'A' + 1;
			for (int j = 1; j <= x; j++)
			{
				char tmp;
				int _;
				cin >> tmp >> _;
				int ed = tmp - 'A' + 1;
				edge[++tot].x = st;
				edge[tot].y = ed;
				edge[tot].z = _;
			}
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
	}
	return 0;
}