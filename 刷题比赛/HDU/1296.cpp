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
int x;
string s;
ll solve(int &i)
{
	int op = 1;
	int b = 0;
	if (s[i] == '+') i++;
	if (s[i] == '-') op *= -1, i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		b = b * 10 + s[i] - '0';
		i++;
	}
	if (b == 0) b = 1;
	int n = 0;
	if (s[i] == 'X')
	{
		i++;
		if (s[i] == '^')
		{
			i++;
			while (s[i] >= '0' && s[i] <= '9')
			{
				n = n * 10 + s[i] - '0';
				i++;
			}
		}
		else n = 1;
	}
	ll ans = 1;
	ans = (ll)op * b;
	for (int i = 1; i <= n; i++) ans *= x;
	return ans;
}
int main ()
{
	while (cin >> x >> s)
	{
		int i = 0;
		ll ans = 0;
		for (int i = 0; i < s.size();)
		{
			ans += (ll)solve(i);
		}
		cout << ans << endl;
	}
	return 0 ;
}
