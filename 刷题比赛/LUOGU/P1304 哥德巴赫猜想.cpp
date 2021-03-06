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
const int N = 1e4 + 5;
int is_prime[N], prime[N];
int n, tot = 0;
struct T
{
	int x;
	int y;
};
void seive()
{
	for (int i = 1; i <= N; i++)is_prime[i] = 1;
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		if (is_prime[i])
		{
			prime[++tot] = i;
			for (int j = 2 * i; j <= N; j += i)is_prime[j] = 0;
		}
	}
}
T solve(int x)
{
	T ans;
	//cout<<is_prime[7]<<endl;
	for (int i = 1; i <= tot && prime[i] <= x / 2; i++)
	{
		if (is_prime[x - prime[i]])
		{
			ans.x = prime[i];
			ans.y = x - prime[i];
			break;
		}
	}
	return ans;
}
int main ()
{
	cin >> n;
	seive();
	for (int i = 4; i <= n; i += 2)
	{
		T ans;
		ans = solve(i);
		printf("%d=%d+%d\n", i, ans.x, ans.y);
	}
	return 0 ;
}