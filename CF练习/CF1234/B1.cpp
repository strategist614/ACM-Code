 
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
unordered_map<int, int> mp;
deque<int> q;
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) read(a[i]);
	if (n <= k) {
		for (int i = 1; i <= n; i++)
		{
			if (!mp[a[i]])
			{
				mp[a[i]] = 1;
				q.push_front(a[i]);
			}
		}
		cout << q.size() << endl;
		while (q.size())
		{
			cout << q.front() << ' ';
			q.pop_front();
		}
	}
	else
	{
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (mp[a[i]]) continue;
			else
			{
				if ((int)q.size() == k)
				{
					mp[a[i]] = 1;
					q.push_front(a[i]);
					int _ = q.back();
					mp[_] = 0;
					q.pop_back();
				}
				else
				{
					mp[a[i]] = 1;
					q.push_front(a[i]);
				}
			}
		}
		cout << q.size() << endl;
		while (q.size())
		{
			cout << q.front() << ' ';
			q.pop_front();
		}
	}
	return 0 ;
}