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
typedef unsigned long long u64;

const int MaxN = 100000;
char s[MaxN];
inline int hash_handle(const char *s, const int &n, const int &l, const int &base)
{
	const int Mod = 1000000007;

	u64 hash_pow_l = 1;
	for (int i = 1; i <= l; i++)
		hash_pow_l = (hash_pow_l * base) % Mod;

	int li_n = 0;
	static int li[MaxN];

	u64 val = 0;
	for (int i = 0; i < l; i++)
		val = (val * base + s[i] - 'a') % Mod;
	li[li_n++] = val;
	for (int i = l; i < n; i++)
	{
		val = (val * base + s[i] - 'a') % Mod;
		val = (val + Mod - ((s[i - l] - 'a') * hash_pow_l) % Mod) % Mod;
		li[li_n++] = val;
	}

	sort(li, li + li_n);
	li_n = unique(li, li + li_n) - li;
	return li_n;
}
int main()
{
    int n,l;
    cin>>n>>l;
    scanf("%s",s);
    cout << hash_handle(s,n,l,1331) << endl;
	return 0;
}
*/
/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include <ctime>
#include <cstdio>
#include <cstdlib>

int main()
{
    srand((unsigned)time(0)),puts("100000 20");
    for(int i=100000;i;--i)putchar(rand()%26+97);
    return 0;
}