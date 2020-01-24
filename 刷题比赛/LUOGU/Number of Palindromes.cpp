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
char a[1005], s[2005];
int tot;
int hw[2005];
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
	int maxright = 0, mid = 0;
	for (int i = 2; i <= tot; i++)
	{
		if (i < maxright)
			hw[i] = min(hw[(mid << 1) - i], hw[mid] + mid - i);
		else
			hw[i] = 1;
		while (s[i + hw[i]] == s[i - hw[i]])
			++hw[i];
		if (hw[i] + i > maxright)
		{
			maxright = hw[i] + i;
			mid = i;
		}
	}
	int ans = 1;
	for (int i = 2; i <= tot; i++)
		ans += hw[i] / 2;
	printf("%d", ans - 1);
	return 0 ;
}