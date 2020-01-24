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
struct rec { int x, y; double z;} edge[5000010];
int fa[1000010], n, m, ans;
double a[505];
struct point
{
	int x;
	int y;
} p[1005];
bool operator <(rec a, rec b) {
	return a.z < b.z;
}
int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
double dis(int x, int y, int a, int b)
{
	return sqrt((double)(x -  a) * (x - a) + (double)(y - b) * (y - b));
}
int main() {
	read(m);
	for (int i = 1; i <= m; i++) scanf("%lf", &a[i]);
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(p[i].x);
		read(p[i].y);
	}
	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			double tmp = dis(p[i].x, p[i].y, p[j].x, p[j].y);
			edge[++tot].x = i;
			edge[tot].y = j;
			edge[tot].z = tmp;
		}
	}
	sort(edge + 1, edge + tot + 1);
	for (int i = 1; i <= tot; i++) fa[i] = i;
	std::vector<double> v;
	for (int i = 1; i <= tot; i++) {
		int x = get(edge[i].x);
		int y = get(edge[i].y);
		if (x == y) continue;
		fa[x] = y;
		v.push_back(edge[i].z);
	}
	for (int i = 1; i <= m; i++)
	{
		int flag = 0;
		for (int j = 0; j < v.size(); j++)
		{
			if (a[i] < v[j]) {flag = 1; break;}
		}
		if (!flag) ans++;
	}
	cout << ans << endl;
	return 0;
}