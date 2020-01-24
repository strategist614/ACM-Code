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
int n;
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	read(n);
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
		read(v[i]);
	rotate(v.begin(), max_element(v.begin(), v.end()), v.end());
	v.push_back(v[0]);
	std::vector<int> le(n + 5);
	std::vector<int> ri(n + 5);
	std::vector<int> same(n + 5, 0);
	stack<int> s;
	s.push(0);
	le[0] = -1;
	for (int i = 1; i < n; i++) {
		while (!s.empty() && v[s.top()] <= v[i])
		{
			if (v[s.top()] == v[i])
				same[i] = same[s.top()] + 1;
			s.pop();
		}
		if (s.size()) le[i] = s.top();
		else le[i] = -1;
		s.push(i);
	}
	while (s.size()) s.pop();
	ri[n] = n;
	s.push(n);
	for (int i = n - 1; i >= 1; i--)
	{
		while (!s.empty() && v[s.top()] <= v[i])
			s.pop();
		if (s.size()) ri[i] = s.top();
		else ri[i] = n + 1;
		s.push(i);
	}
	ll ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (le[i] != -1)
			ans++;
		if (ri[i] != n + 1)
			ans++;
		if (le[i] == 0 && ri[i] == n)
			ans--;
		ans += same[i];
	}
	cout << ans << endl;
	return 0 ;
}
/*
4
1178 1178 2577 2577
*/
