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
unsigned int cnt[N << 1], block[N], a[N];
struct Data
{
	int l;
	int r;
	int pos;
	int ans;
} b[N];
bool cmp1(Data A, Data B)
{
	return block[A.l] == block[B.l]
	       ? (block[B.l] & 1)
	       ? A.r<B.r
	       : A.r>B.r
	       : A.l < B.l;
}
bool cmp2(Data a, Data b)
{
	return a.pos < b.pos;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	register int n, q;
	read(n);
	read(q);
	for (register int i = 1; i <= n; i++) {
		read(a[i]);
		block[i] = i / 800;
		a[i]++;
	}
	//register int m;
	//read(m);
	for (register int i = 1; i <= q; i++) {
		read(b[i].l);
		read(b[i].r);
		b[i].pos = i;
	}
	sort(b + 1, b + q + 1, cmp1);
	register int l = 1;
	register int r = 0;
	register int ans = 0;
	for (register int i = 1; i <= q; i++) {
		while (l < b[i].l)ans -= !(--cnt[a[l++]]);
		while (l > b[i].l)ans += !(cnt[a[--l]]++);
		while (r > b[i].r)ans -= !(--cnt[a[r--]]);
		while (r < b[i].r)ans += !(cnt[a[++r]]++);
		b[i].ans = ans;
	}
	sort(b + 1, b + q + 1, cmp2);
	for (int i = 1; i <= q; i++)
	{
       int len = b[i].r - b[i].l + 1;
       if(b[i].ans == len) cout << "Yes"<<endl;
       else cout << "No" << endl;
	}
	return 0 ;
}