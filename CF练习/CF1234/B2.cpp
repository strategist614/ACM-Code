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
int a[200005];
map<int, int> mp;
deque<int> q;
std::vector<int> v;
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n, k;
	read(n);
	read(k);
	for (int i = 1; i <= n; i++) read(a[i]);
	if (n <= k) {
		for (int i = 1; i <= n; i++)
		{
			if (!mp[a[i]])
			{
				mp[a[i]] = 1;
				v.push_back(a[i]);
			}
		}
		printf("%d\n", v.size());
		reverse(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
			printf("%d ", v[i]);
	}
	else
	{
		for (int i = 1; i <= n; i++) {
			if (!mp[a[i]])
			{
				if ((int)q.size() == k)
				{
					mp[a[i]] = 1;
					q.push_front(a[i]);
					int _ = q.back();
					mp[_] = 0;
					q.pop_back();
				}
				else if ((int)q.size() < k)
				{
					mp[a[i]] = 1;
					q.push_front(a[i]);
				}
			}
		}
		printf("%d\n", q.size());
		while ((int)q.size())
		{
			printf("%d ", q.front());
			q.pop_front();
		}
	}
	return 0 ;
}