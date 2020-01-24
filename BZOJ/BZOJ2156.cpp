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
typedef pair<int, int> pii;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 100010, M = 1000010;
int head[N], ver[M], edge[M], Next[M], d[N];
int n, m, tot;
queue<int> q;
bool v[N];
int a[N];
std::map<pair<int, int>, int> mp;
void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

void spfa(int st) {
	memset(d, 0x3f, sizeof(d));
	memset(v, 0, sizeof(v));
	d[st] = 0; v[st] = 1;
	q.push(st);
	while (q.size()) {
		int x = q.front(); q.pop();
		v[x] = 0;
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i], z = edge[i];
			if (d[y] > d[x] + z) {
				d[y] = d[x] + z;
				if (!v[y]) q.push(y), v[y] = 1;
			}
		}
	}
}

int main() {
	read(n);
	read(m);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		mp[make_pair(x, y)] = z;
	}
	int p;
	read(p);
	for (int i = 1; i <= p; i++) read(a[i]);
    int _ = 0;
    for (int i = 1; i <= p - 1; i++)
    	_ += mp[make_pair(a[i],a[i + 1])];
    spfa(a[1]);
    int __ = d[a[p]];
    cout << abs(_ - __) << endl;
	return 0;
}
