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
typedef pair<int, int> pii;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 2e5 + 5;
char a[N], s[N];
int hw[N], l[N], r[N];
int mid, rx, tot;
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	scanf("%s", a);
	int n = strlen(a);
	s[++tot] = '$';
	s[++tot] = '#';
	for (int i = 0; i < n; i++)
	{
		s[++tot] = a[i];
		s[++tot] = '#';
	}
	s[++tot] = '\0';
	for (int i = 1; i <= tot; i++)
	{
		hw[i] = i < rx ? min(hw[(mid << 1) - i], rx - i) : 1;
		while (s[i + hw[i]] == s[i - hw[i]])
			hw[i] ++;
		if (i + hw[i] > rx)
		{
			rx = i + hw[i];
			mid = i;
		}
		l[i + hw[i] - 1] = max(l[i + hw[i] - 1], hw[i] - 1);
		r[i - hw[i] + 1] = max(r[i - hw[i] + 1], hw[i] - 1);
	}
	for (int i = 2; i <= tot; i += 2) r[i] = max(r[i], r[i - 2] - 2);
	for (int i = tot; i >= 2; i -= 2) l[i] = max(l[i], l[i + 2] - 2);
    int ans = 0;
	for(int i = 2;i <= tot;i += 2) if(r[i] && l[i]) ans = max(ans,l[i] + r[i]);
	printf("%d\n", ans);
	return 0 ;
}