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
struct rec { int x, y, z; } edge[50010];
int fa[1010], n, m, ans;
bool operator <(rec a, rec b) {
	return a.z < b.z;
}
double dis(rec a, rec b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
int main() {
	int t;
	read(t);
	{
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
	}
	return 0;
}