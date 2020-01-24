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
const int N = 5e4 + 5;
int a[N];
map<int, int> mp;
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int t;
	read(t);
	while (t--)
	{
		mp.clear();
		int n;
		read(n);
		for (int i = 1; i <= n; i++)
			read(a[i]);
		for (int i = 1; i <= n; i++)
		{
			if (!mp[a[i]])
			{
				printf("%d ", a[i]);
				mp[a[i]] = 1;
			}
			else continue;
		}
		puts("");
	}
	return 0 ;
}
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
const int P = 1e5 + 7;
const int N = 5e6 + 5;
std::vector<int> v[N];
int a[N];
int H(int x)
{
	return (x % P) + 1;
}
bool insert(int x)
{
	int val = H(x);
	for (int i = 0; i < v[val].size(); i++)
		if (v[val][i] == x) return 1;
	v[val].push_back(x);
	return 0;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int t;
	read(t);
	while (t--)
	{
		int n;
		read(n);
		for (int i = 1; i <= n; i++) read(a[i]);
		for (int i = 1; i <= P + 1; i++) v[i].clear();
		for (int i = 1; i <= n; i++) {
			if (insert(a[i])) continue;
			else printf("%d ", a[i]);
		}
		puts("");
	}
	return 0 ;
}