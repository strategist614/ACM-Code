#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include<math.h>
using namespace std;
const double eps = 1e-6;
struct rec { int x, y; double z;} edge[500010];
struct node
{
	double x;
	double y;
	double z;
	double r;
} a[105];
double dis(node a, node b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}
int fa[100010], n, m;
bool operator <(rec a, rec b) {
	return a.z - b.z < eps;
}
int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
int main() {
	int n;
	while (cin >> n && n) {
		int tot = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z >> a[i].r;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				double tmp = dis(a[i], a[j]);
				if (a[i].r + a[j].r - tmp > eps)
				{
                    edge[++tot].x = i;
                    edge[tot].y = j;
                    edge[tot].z = 0.0; 
				}
				else 
				{
					edge[++tot].x = i;
					edge[tot].y = j;
					edge[tot].z = tmp-a[i].r-a[j].r;
				}
			}
		}
		sort(edge + 1, edge + tot + 1);
		double ans = 0.0;
		for (int i = 1; i <= n; i++) fa[i] = i;
		for (int i = 1; i <= tot; i++) {
			int x = get(edge[i].x);
			int y = get(edge[i].y);
			if (x == y) continue;
			fa[x] = y;
			ans += edge[i].z;
			//printf("%.3f\t", edge[i].z);
		}
		printf("%.3f\n", ans);
	}
	return 0;
}