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
const int N = 5e5+5;
int qtot, rtot;
int block[N], sum[N << 2], a[N];
int ans = 0;
int now = 0;
int n,m;
struct change
{
	int p;
	int val;
} c[N];
struct Mo
{
	int l;
	int r;
	int id;
	int ans;
	int t;
} b[N];
bool cmp1(Mo a, Mo b) {
	if (block[a.l] == block[b.l])
	{
		if (block[a.r] == block[b.r])
			return a.t < b.t;
		else return a.r < b.r;
	}
	else return a.l < b.l;
}
bool cmp2(Mo a, Mo b) {
	return a.id < b.id;
}
void del(int x) {
	if (--sum[x] == 0)
		ans --;
}
void add(int x) {
	if (sum[x]++ == 0)
		ans ++;
}
void update(int i, int ti)
{
	if (b[i].l <= c[ti].p && c[ti].p <= b[i].r)
	{
		del(a[c[ti].p]);
		add(c[ti].val);
	}
	swap(a[c[ti].p], c[ti].val);
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	read(n);
	read(m);
	char op[20];
	for (int i = 1; i <= n; i++) read(a[i]);
	int size = pow(n, 0.666666);
	for (int i = 1; i <= m; i++) {
		scanf("%s", op);
		int l, r;
		read(l);
		read(r);
		if (op[0] == 'Q')
		{
			++qtot;
			b[qtot].l = l;
			b[qtot].r = r;
			b[qtot].id = qtot;
			b[qtot].t = rtot;
			block[qtot] = qtot / size;
		}
		else
		{
			++rtot;
			c[rtot].p = l;
			c[rtot].val = r;
		}
	}
	sort(b + 1, b + qtot + 1, cmp1);
	int l = 1;
	int r = 0;
	for (int i = 1; i <= qtot; i++) {
		while (l < b[i].l){
			del(a[l++]);
		}
		while (l > b[i].l){
			add(a[--l]);
		}
		while (r > b[i].r){
			del(a[r--]);
		}
		while (r < b[i].r){
			add(a[++r]);
		}
		while (now < b[i].t)
		{
			update(i,++now);
		}
		while (now > b[i].t)
		{
			update(i,now--);
		}
		b[i].ans = ans;
	}
	sort(b + 1, b + qtot + 1, cmp2);
	for (int i = 1; i <= qtot; i++) {
          printf("%d\n",b[i].ans); 
	} 
	return 0 ;
}