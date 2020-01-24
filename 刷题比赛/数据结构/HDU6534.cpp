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
struct Mo
{
	int l;
	int r;
	int pos;
	int ans;
} b[N + 5];
map<int, int> mp;
int block[N + 5];
int num = 0;
int len;
bool cmp1(Mo a, Mo b)
{
	if (block[a.l] == block[b.l]) return a.r < b.r;
	else return a.l < b.l;
}
bool cmp2(Mo a, Mo b)
{
	return a.pos < b.pos;
}
int c[N + 5];
struct Bit
{
	void init()
	{
		memset(c,0,sizeof(c));
	}
	int ask(int x)
    {
       int ans = 0;
       for(;x;x -= x & -x) ans += c[x];
       return ans;
    }
    void add(int x,int y)
    {
    	for(;x <= len;x += x & -x) c[x] += y;
    }
}bit;
struct node
{
	int zj;
	int zb;
	int yb;
}pos[N + 5];
int lsh[N + 5];
inline void add(int x) {
	num += (bit.ask(pos[x].yb) - bit.ask(pos[x].zb - 1));
	bit.add(pos[x].zj,1);
}
inline void del(int x) {
	bit.add(pos[x].zj,-1);
	num -= (bit.ask(pos[x].yb) - bit.ask(pos[x].zb - 1));
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n, m, k;
	read(n);
	read(m);
	read(k);
	int size = sqrt(n);
	int tot = 0;
	bit.init();
	for (int i = 1; i <= n; i++) {
		read(a[i]);
        lsh[++tot] = a[i];
        lsh[++tot] = a[i] - k;
        lsh[++tot] = a[i] + k;
	}
	sort(lsh + 1,lsh + 1 + tot);
	len = unique(lsh + 1,lsh + 1 + tot) - (lsh + 1);
	for(int i= 1;i <= n;i++){
		pos[i].zj = lower_bound(lsh + 1,lsh + len + 1,a[i]) - lsh;
		pos[i].zb = lower_bound(lsh + 1,lsh + len + 1,a[i] - k) - lsh;
		pos[i].yb = lower_bound(lsh + 1,lsh + len + 1,a[i] + k) - lsh;
	}
	for (int i = 1; i <= m; i++) {
		read(b[i].l);
		read(b[i].r);
		b[i].pos = i;
		block[i] = i / size;
	}
	sort(b + 1, b + m + 1, cmp1);
	int l = 1;
	int r = 0;
	for (int i = 1; i <= m; i++) {
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
	    b[i].ans = num;
	}
	sort(b + 1, b + m + 1, cmp2);
	for (int i = 1; i <= m; i++) {
		cout << b[i].ans << endl;
	}
	return 0 ;
}