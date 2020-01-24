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
const int N = 2750131;
int prime[N + 5];
int is_prime[N + 5];
int tot = 0;
void sieve() {
	for (int i = 0; i <= N; i++) is_prime[i] = 1;
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i <= N; i++) {
		if (is_prime[i])
		{
			prime[++tot] = i;
			for (int j = i * 2; j <= N; j += i) is_prime[j] = 0;
		}
	}
}
int a[N];
map<int, int> mp;
std::vector<int> ans;
int solve(int x)
{
	int maxn = 0;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0)
		{
			maxn = max(maxn, i);
			if (x / i != i) maxn = max(maxn, x / i);
		}
	}
	return maxn;
}
int main ()
{
	int n;
	cin >> n;
	int tmp = n << 1;
	sieve();
	for (int i = 1; i <= tmp; i++)
	{
		int x;
		cin >> x;
		a[x]++;
	}
	for (int i = 1; i <= tot; i++) {
		mp[prime[i]] = i;
	}
	for (int i = 2750131; i >= 2; i--) {
		if (a[i] > 0) {
			if (is_prime[i])
			{
				if (a[i] > a[mp[i]])
				{
					for (int j = 1; j <= a[mp[i]]; j++)
						ans.push_back(mp[i]);
					a[i] -= a[mp[i]];
					a[mp[i]] = 0;
				}
				else
				{
					for (int j = 1; j <= a[i]; j++)
						ans.push_back(mp[i]);
					a[mp[i]] -= a[i];
					a[i] = 0;
				}
			}
			else
			{
				int _ = solve(i);
				if (a[i] > a[_])
				{
					for (int j = 1; j <= a[i]; j++)
						ans.push_back(i);
					a[i] -= a[mp[i]];
					a[_] = 0;
				}
				else
				{
					for (int j = 1; j <= a[i]; j++)
						ans.push_back(i);
					a[_] -= a[i];
					a[i] = 0;
				}
			}
		}
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0 ;
}