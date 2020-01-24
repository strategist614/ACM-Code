#include<cstdio>
using namespace std;
const int maxn = 303;
struct arr {int l, r;} map[maxn];
int f[maxn], N, n, i, ans;
bool flag[maxn];
int get(int u) {if (u == f[u]) return u; return f[u] = get(f[u]);}
void search(int k, int sta)
{
	if (k == n + 1)
	{
		ans++;
		return;
	}
	int temp[maxn];
	for (int i = sta + 1; i <= N; i++)
		if (!flag[i])
		{
			int t1 = get(map[i].l), t2 = get(map[i].r);
			if (t1 == t2) continue;
			for (int j = 0; j <= n; j++) temp[j] = f[j]; //这里我就不考虑时间了，想想并查集很难回溯，浪费点吧。
			flag[i] = true; f[t1] = t2;
			search(k + 1, i);
			for (int j = 0; j <= n; j++) f[j] = temp[j];
			flag[i] = false;
		}
}
int main()
{
	for (n = 1; n <= 15; n++)
	{
		for (i = 1; i < n; i++)
			map[i].l = i, map[i].r = i + 1;
		map[n].l = n; map[n].r = 1;
		for (i = n + 1; i <= n + n; i++)
			map[i].l = 0, map[i].r = i - n;
		N = 2 * n;
		for (i = 0; i <= n; i++) f[i] = i;
		search(1, 0);
		printf("%d  ", ans);
		ans = 0;
	}
	return 0;
}