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
const int N = 1e5;
int a[N + 5];
int block[N + 5];
struct Mo
{
	int l;
	int r;
	int ans;
	int pos;
	int x;
	int op;
} b[N + 5];
bool cmp1(Mo a, Mo b)
{
	if (block[a.l] == block[b.l]) return a.r < b.r;
	else return a.l < b.l;
}
bool cmp2(Mo a, Mo b)
{
	return a.pos < b.pos;
}
bitset<N> now1, now2;
int sum[N + 5];
inline void add(int x) {if (sum[x]++ == 0) now1[x] = 1, now2[N - x] = 1;}
inline void del(int x) {if (--sum[x] == 0) now1[x] = 0, now2[N - x] = 0;}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n, m;
	read(n);
	read(m);
	int size = sqrt(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		block[i] = i / size + 1;
	}
	for (int i = 1; i <= m; i++) {
		read(b[i].op);
		read(b[i].l);
		read(b[i].r);
		read(b[i].x);
		b[i].pos = i;
	}
	sort(b + 1, b + m + 1, cmp1);
	int l = 1;
	int r = 0;
	for (int i = 1; i <= m; i++) {
		while (l < b[i].l) {
			del(a[l++]);
		}
		while (l > b[i].l) {
			add(a[--l]);
		}
		while (r > b[i].r)
		{
			del(a[r--]);
		}
		while (r < b[i].r)
		{
			add(a[++r]);
		}
		int k = b[i].op;
		int x = b[i].x;
		if (k == 1)
		{
			if ((now1 & (now1 << x)).any())
				b[i].ans = 1;
		}
		else if (k == 2)
		{
			if ((now1 & (now2 >> (N - x))).any())
				b[i].ans = 1;
		}
		else
		{
			for (int j = 1; j <= sqrt(x); j++)
			{
				if (x % j == 0)
				{
					if (now1[j] && now1[x / j])
					{
						b[i].ans = 1;
						break;
					}
				}
			}
		}
	}
	sort(b + 1, b + m + 1, cmp2);
	for (int i = 1; i <= m; i++) {
		if (b[i].ans)
			printf("hana\n");
		else printf("bi\n");
	}
	return 0 ;
}