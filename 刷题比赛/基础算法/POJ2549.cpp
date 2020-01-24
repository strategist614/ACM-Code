/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

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
const int N = 1005;
int n;
int tot = 0;
int a[N];
struct Hash
{
	int x;
	int apos, bpos;
	Hash *next;
};
Hash ha[1123456], *first[21234567];

int H(int val)
{
	return ((val << 1) + (val >> 1)) & 16777215;
}

void insert(int x, int pos1, int pos2)
{
	int _ = H(x);
	++tot;
	Hash &addhash = ha[tot];
	addhash.x = x;
	addhash.apos = pos1;
	addhash.bpos = pos2;
	addhash.next = first[_];
	first[_] = &addhash;
}

void init()
{
	tot = 0;
	memset(first, 0, sizeof(first));
}
int main ()
{
	int n;
	while (~scanf("%d", &n) && n)
	{
		init();
		for (int i = 1; i <= n; i++) read(a[i]);
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				insert(a[i] + a[j], i, j);
			}
		}
		int k = 0;
		for (int d = n; d >= 1; d--) {
			for (int c = 1; c <= n; c++) {
				if (d == c) continue;
				int tmp = a[d] - a[c];
				int ithash = H(tmp);
				for (Hash *it = first[ithash]; it; it = it->next)
				{
					if (it->x == tmp)
					{
						int ax = it->apos;
						int b = it->bpos;
						if (ax != c && ax != d && b != c && b != d) {
							printf("%d\n", a[d]);
							k = 1;
						}
						break;
					}
				}
				if (k) break;
			}
			if (k) break;
		}
		if (!k) printf("no solution\n");
	}
	return 0 ;
}