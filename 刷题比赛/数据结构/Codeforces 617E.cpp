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
const int N = 1e6 + 5;
int a[N];
int block[N];
int sum[N];
int n, m, k;
ll num;
ll tmp[N << 2];
struct Mo
{
	int l;
	int r;
	int pos;
	ll ans;
} b[N];
bool cmp1(Mo a, Mo b) {
	if (block[a.l] == block[b.l]) return a.r < b.r;
	else return a.l < b.l;
}
bool cmp2(Mo a, Mo b) {
	return a.pos < b.pos;
}
void del(int x) {
	tmp[sum[x]]--;
	num -= tmp[sum[x] ^ k];
}
void add(int x) {
	num += tmp[sum[x] ^ k];
	tmp[sum[x]]++;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	//int n, m, k;
	read(n);
	read(m);
	read(k);
	int size = sqrt(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	sum[0] = 0;
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] ^ a[i];
	for (int i = 1; i <= m; i++) {
		read(b[i].l);
		read(b[i].r);
		block[i] = i / size;
		b[i].pos = i;
	}
	sort(b + 1, b + m + 1, cmp1);
	int l = 1;
	int r = 0;
	for (int i = 1; i <= m; i++) {
		while (l < b[i].l - 1) {
			del(l++);
		}
		while (l > b[i].l - 1) {
			add(--l);
		}
		while (r > b[i].r)
		{
			del(r--);
		}
		while (r < b[i].r)
		{
			add(++r);
		}
		b[i].ans = num;
	}
	sort(b + 1, b + m + 1, cmp2);
	for (int i = 1; i <= m; i++) {
          printf("%lld\n",b[i].ans);  
	}
	return 0 ;
}