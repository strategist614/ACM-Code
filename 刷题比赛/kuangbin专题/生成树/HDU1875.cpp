#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
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
struct rec { int x, y; double z;};
vector<rec> v;
const double eps = 1e-6;
int fa[110], n, m;
struct node
{
	int x;
	int y;
} a[105];
bool operator <(rec a, rec b) {
	return a.z - b.z < eps;
}
int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
double dis(node a, node b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
	{
		v.clear();
		scanf("%d", &n);
		double ans = 0.0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d", &a[i].x, &a[i].y);
		}
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
			{
				double z = dis(a[i], a[j]);
				v.push_back(rec{i,j,z});
			}
		int k = n;
		sort(v.begin(),v.end());
		for (int i = 1; i <= n; i++) fa[i] = i;
		for (int i = 0; i <= v.size(); i++) {
			rec _ = v[i];
			if(_.z < 10 || _.z > 1000) continue;
			int x = get(_.x);
			int y = get(_.y);
			if (x == y) continue;
			fa[x] = y;
			ans += _.z;
			k--;
		}
		if (k == 1)
			printf("%.1f\n", ans*100.0);
		else printf("oh!\n");
	}
	return 0;
}