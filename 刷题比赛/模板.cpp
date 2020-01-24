//
//https://paste.ubuntu.com/p/P5jGg63G6j/
//https://paste.ubuntu.com/p/tSv4Ykfz85/?tdsourcetag=s_pcqq_aiomsg
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a % mod; a = a * a % mod;} return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
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
//
//快速幂
typedef long long ll;
ll mypow(ll x, ll n, ll mod)
{
	ll res = 1;
	while (n > 0)
	{
		if (n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}
ll ksm(ll x, ll n)
{
	ll res = 1;
	while (n > 0)
	{
		if (n & 1) res = res * x;
		x = x * x ;
		n >>= 1;
	}
	return res;
}
//
while (n > 0)
{
	ll ans = 1;
	if (b & 1) res = res * a % mod;
	a = a * a % mod;
	return ans;
}
loj，cf类NOIP风格题
(校内模拟几乎都是)
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
int main ()
{

	return 0 ;
}

int exgcd(int a, int b, int &x, int &y)
{
	if (b == 0) {x = 1, y = 0, return a;}
	int d = exgcd(b, a % b, x, y);
	int z = x; x = y; y = z - y * (a / b);
	return d;
}


// 堆优化Dijkstra算法，O(mlogn)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 100010, M = 1000010;
int head[N], ver[M], edge[M], Next[M], d[N];
bool v[N];
int n, m, tot;
// 大根堆（优先队列），pair的第二维为节点编号
// pair的第一维为dist的相反数（利用相反数变成小根堆，参见0x71节）
priority_queue< pair<int, int> > q;

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

void dijkstra() {
	memset(d, 0x3f, sizeof(d)); // dist数组
	memset(v, 0, sizeof(v)); // 节点标记
	d[1] = 0;
	q.push(make_pair(0, 1));
	while (q.size()) {
		// 取出堆顶
		int x = q.top().second; q.pop();
		if (v[x]) continue;
		v[x] = 1;
		// 扫描所有出边
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i], z = edge[i];
			if (d[y] > d[x] + z) {
				// 更新，把新的二元组插入堆
				d[y] = d[x] + z;
				q.push(make_pair(-d[y], y));
			}
		}
	}
}

int main() {
	cin >> n >> m;
	// 构建邻接表
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
	}
	// 求单源最短路径
	dijkstra();
	for (int i = 1; i <= n; i++)
		printf("%d\n", d[i]);
}

ll ksc(ll a, ll b, ll c) {
	ll ans = 0;
	while (b) {
		if (b & 1) ans = (ans + a) % c;
		a = a * 2 % c;
		b >>= 1;
	}
	return ans;
}

ll ksm(ll a, ll b, ll c) {
	ll ans = 1 % c;
	a %= c;
	while (b) {
		if (b & 1) ans = ksc(ans, a, c);
		a = ksc(a, a, c);
		b >>= 1;
	}
	return ans;
}

memset(phi, 0, sizeof phi);
for (int i = 2; i < n; ++i) {
	if (!phi[i]) {
		phi[i] = (i - 1);
		prime[m++] = i;
	}
	for (int j = 0; j < m && i * prime[j] < n; ++j) {
		if (i % prime[j] ) phi[i * prime[j]] = phi[i] * phi[prime[j]];
		else {
			phi[i * prime[j]] = phi[i] * prime[j];
			break;
		}
	}
}


void dfs(int x,int color){
	v[x] = color;
	for(int i = head[x];i;i = Next[i]){
		int y = ver[i];
		if(!v[y])
			dfs(y,3-color);
		else if(v[y] == color) 
		{
			flag = 1;
			return ;
		}
	}
}
