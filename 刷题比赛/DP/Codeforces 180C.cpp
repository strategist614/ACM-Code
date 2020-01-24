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
char s[100005];
int l[N];
int r[N];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	for (int i = 1; i <= len; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z') l[i] = l[i - 1] + 1;
		else l[i] = l[i - 1];
	}
	for (int i = len; i >= 1; i--)
	{
		if (s[i] >= 'A' && s[i] <= 'Z') r[i] = r[i + 1] + 1;
		else r[i] = r[i + 1];
	}
	int minn = 1e9;
	int maxn = 0;
	for (int i = 1; i <= len; i++) {
		minn = min(minn, l[i] + r[i] - 1);
	}
	cout << minn << endl;
	return 0 ;
}