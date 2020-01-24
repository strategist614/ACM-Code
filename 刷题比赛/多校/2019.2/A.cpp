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
const int N = 1e5 + 5;
struct node
{
	int l;
	int r;
	int ans;
	int pos;
} b[N];
int block[N], a[N];
int blocksize = 0;
bool cmp1(node a, node b)
{
	if (block[a.l] == block[b.l]) return a.r < b.r;
	else return a.l < b.l;
}
bool cmp2(node a, node b)
{
	return a.pos < b.pos;
}
bool judge(int x, int y, int z)
{
	if ((x + y > z) && (x + z > y) && (y + z > x)) return 1;
	else return 0;
}
void add(int x)
{
   
}
void del(int x)
{
    
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n;
	int q;
	while (~scanf("%d %d", &n, &q)) {
		blocksize = sqrt(n);
		for (int i = 1; i <= n; i++) {
			read(a[i]);
			block[i] = i / blocksize;
		}
		for (int i = 1; i <= q; i++)
		{
			read(b[i].l);
			read(b[i].r);
			b[i].pos = i;
		}
		sort(b + 1, b + q + 1, cmp1);
		int l = 0;
		int r = 1;
		for (int i = 1; i <= q; i++) {
			while (l < b[i].l)
			{

			}
			while (l > b[i].l)
			{

			}
			while (r > b[i].r)
			{

			}
			while (r < b[i].r)
			{

			}
		}
		sort(b + 1, b + q + 1, cmp2);
		for (int i = 1; i <= m; i++)
			printf("%d\n", b[i].ans);
	}
	return 0 ;
}