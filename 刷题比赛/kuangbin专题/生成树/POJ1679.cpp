#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <queue>
#include <new>
#include <set>
#include <map>

using namespace std;

const int maxn = 1000;
int p[maxn], x[maxn], y[maxn], n, m;
struct edge
{
	int u, v, cost;
	bool operator < (const edge& b) const
	{
		return cost < b.cost;
	}
};
vector<edge> edges;
vector<int> mst_edges;

int find_root(int x)
{
	if (p[x] == -1) return x;
	return p[x] = find_root(p[x]);
}

void kruskal()
{
	memset(p, -1, sizeof(p));
	sort(edges.begin(), edges.end());

	mst_edges.clear();
	int cost = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		int x = edges[i].u, y = edges[i].v;
		int rx = find_root(x);
		int ry = find_root(y);
		if (rx != ry)
		{
			p[rx] = ry;
			cost += edges[i].cost;
			mst_edges.push_back(i);
		}
	}

	bool ok = false;
	for (int i = 0; i < mst_edges.size(); i++)
	{
		memset(p, -1, sizeof(p));
		int ans = 0, k = 0;
		for (int j = 0; j < edges.size(); j++)
		{
			if (mst_edges[i] == j) continue;
			int x = edges[j].u, y = edges[j].v;
			int rx = find_root(x);
			int ry = find_root(y);
			if (rx != ry)
			{
				p[rx] = ry;
				ans += edges[j].cost;
				k++;
			}
		}

		if (ans == cost && k == n - 1)
		{
			ok = true;
			break;
		}
	}

	if (!ok) printf("%d\n", cost);
	else printf("Not Unique!\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &n, &m);
		edges.clear();
		for (int i = 1; i <= m; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back(edge{x, y, z});
		}
		kruskal();
	}
	return 0;
}