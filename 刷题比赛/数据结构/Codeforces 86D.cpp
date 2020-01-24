/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
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
const int N = 1e6 + 5;
int a[N];
int block[N];
ll ans = 0;
int sum[N];
struct Mo
{
	int l;
	int r;
	ll ans;
	int pos;
} b[N];
bool cmp1(Mo a, Mo b) {
	if (block[a.l] == block[b.l]) return a.r < b.r;
	else return a.l < b.l;
}
bool cmp2(Mo a, Mo b) {
	return a.pos < b.pos;
}
void add(int x) {
    ans = ans + (ll)a[x] * (sum[a[x]] * 2 + 1);
    sum[a[x]]++; 
}
void del(int x) {
    ans = ans - (ll)a[x] * (sum[a[x]] * 2 - 1); 
    --sum[a[x]];
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n, q;
	read(n);
	read(q);
	for (int i = 1; i <= n; i++) read(a[i]);
	int size = sqrt(n);
	for (int i = 1; i <= q; i++) {
		read(b[i].l);
		read(b[i].r);
		block[i] = i / size;
		b[i].pos = i;
	}
	sort(b + 1, b + q + 1, cmp1);
	int l = 1;
	int r = 0;
	for (int i = 1; i <= q; i++) {
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
		b[i].ans = ans ;
	}
	sort(b + 1, b + q + 1, cmp2);
	for (int i = 1; i <= q; i++)
		printf("%lld\n", b[i].ans);
	return 0 ;
}
*/
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
ll ans = 0;
int sum[N];
struct Mo
{
	int l;
	int r;
	ll ans;
	int pos;
} b[N];
bool cmp1(Mo a, Mo b) {
	if (block[a.l] == block[b.l]) return a.r < b.r;
	else return a.l < b.l;
}
bool cmp2(Mo a, Mo b) {
	return a.pos < b.pos;
}
void add(int x) {
    ans = ans + (ll)a[x] * (sum[a[x]] * 2 + 1);
    sum[a[x]]++; 
}
void del(int x) {
	--sum[a[x]];
    ans = ans - (ll)a[x] * (sum[a[x]] * 2 + 1); 
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n, q;
	read(n);
	read(q);
	for (int i = 1; i <= n; i++) read(a[i]);
	int size = sqrt(n);
	for (int i = 1; i <= q; i++) {
		read(b[i].l);
		read(b[i].r);
		block[i] = i / size;
		b[i].pos = i;
	}
	sort(b + 1, b + q + 1, cmp1);
	int l = 1;
	int r = 0;
	for (int i = 1; i <= q; i++) {
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
		b[i].ans = ans ;
	}
	sort(b + 1, b + q + 1, cmp2);
	for (int i = 1; i <= q; i++)
		printf("%lld\n", b[i].ans);
	return 0 ;
}