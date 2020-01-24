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
	int n, tot = 0;
	while (scanf("%d", &n) != EOF && n)
	{
		tot = 0;
		ans = 0;
		for (int i = 1; i < n; i++)
		{
			char c;
			cin >> c;
			int x = c - 'A' + 1;
			int m;
			cin >> m;
			for (int i = 1; i <= m; i++)
			{
				char tmp;
				int y;
				cin >> tmp >> y;
				//<<_<<endl;
				int _ = tmp - 'A' + 1;
				edge[++tot].x = x;
				edge[tot].y = _;
				edge[tot].z = y;
			}
		}
		for (int i = 1; i <= n; i++) fa[i] = i;
		sort(edge + 1, edge + tot + 1);
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
/*
cin >> n >> m;
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].z);
	sort(edge + 1, edge + m + 1);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int x = get(edge[i].x);
		int y = get(edge[i].y);
		if (x == y) continue;
		fa[x] = y;
		ans += edge[i].z;
	}
	cout << ans << endl;
*/
