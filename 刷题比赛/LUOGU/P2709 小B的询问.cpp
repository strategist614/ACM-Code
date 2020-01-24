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
const int N = 5e5 + 5;
unsigned int block[N];
int a[N];
ll cnt[N];
struct Data
{
	int l;
	int r;
	int pos;
	ll ans;
} b[N];
bool cmp1(Data A, Data B)
{
	return block[A.l] == block[B.l] ? A.r < B.r : A.l < B.l;
}
bool cmp2(Data a, Data b)
{
	return a.pos < b.pos;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	register ll n, m, k;
	read(n);
	read(m);
	read(k);
	ll blocksize = (ll)sqrt(n);
	for (register ll i = 1; i <= n; i++) {
		read(a[i]);
		block[i] = i / blocksize;
	}
	for (register int i = 1; i <= m; i++) {
		read(b[i].l);
		read(b[i].r);
		b[i].pos = i;
	}
	sort(b + 1, b + m + 1, cmp1);
	memset(cnt, 0, sizeof(cnt));
	register int l = 1;
	register int r = 0;
	register ll ans = 0;
	for (register int i = 1; i <= m; i++) {
		while (l > b[i].l) l--, cnt[a[l]]++, ans += 2 * cnt[a[l]] - 1;
		while (r < b[i].r) r++, cnt[a[r]]++, ans += 2 * cnt[a[r]] - 1;
		while (l < b[i].l) cnt[a[l]]--, ans -= 2 * cnt[a[l]] + 1, l++;
		while (r > b[i].r) cnt[a[r]]--, ans -= 2 * cnt[a[r]] + 1, r--;
		b[i].ans = ans;
	}
	sort(b + 1, b + m + 1, cmp2);
	for (int i = 1; i <= m; i++)
		out(b[i].ans), puts("");
	return 0 ;
}
/*
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
const int N = 5e5 + 5;
unsigned int block[N];
int a[N];
ll cnt[N];
ll ans ;
struct Data
{
	int l;
	int r;
	int pos;
	ll ans;
} b[N];
bool cmp1(Data A, Data B)
{
	return block[A.l] == block[B.l] ? A.r < B.r : A.l < B.l;
}
bool cmp2(Data a, Data b)
{
	return a.pos < b.pos;
}
void add(int x){
   ans += 2 * cnt[a[x]] + 1;
   cnt[a[x]]++;
}
void del(int x){
   cnt[a[x]]--;
   ans -= 2 * cnt[a[x]] + 1;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	register ll n, m, k;
	read(n);
	read(m);
	read(k);
	ll blocksize = (ll)sqrt(n);
	for (register ll i = 1; i <= n; i++) {
		read(a[i]);
		block[i] = i / blocksize;
	}
	for (register int i = 1; i <= m; i++) {
		read(b[i].l);
		read(b[i].r);
		b[i].pos = i;
	}
	sort(b + 1, b + m + 1, cmp1);
	memset(cnt, 0, sizeof(cnt));
	register int l = 1;
	register int r = 0;
	for (register int i = 1; i <= m; i++) {
		while (l < b[i].l) {
			del(l++);
		}
		while (l > b[i].l) {
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
		b[i].ans = ans;
	}
	sort(b + 1, b + m + 1, cmp2);
	for (int i = 1; i <= m; i++)
		out(b[i].ans), puts("");
	return 0 ;
}
*/