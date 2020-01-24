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
const int N = 2005;
int n, m, p;
int a[N][N];
int ans[N][N];
ll comb[N][N];

void pre_work()
{
	for (int i = 0; i <= 2000; i++)comb[i][0] = comb[i][i] = 1;
	for (int i = 1; i <= 2000; i++)
		for (int j = 1; j <= i; j++) {
			comb[i][j] = ((comb[i - 1][j - 1] % p) + (comb[i - 1][j] % p)) % p;
		}
	for (int i = 0; i <= 2000; i++)
		for (int j = 0; j <= 2000; j++)
		{
			ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
			if (!comb[i][j] && i >= j) ans[i][j]++;
		}
}

int main ()
{
	int t;
	read(t);
	read(p);
	pre_work();
	while (t--)
	{
		int n, m;
		read(n);
		read(m);
		if (m > n) m = n;
		cout << ans[n][m] << endl;
	}
	return 0;
}
*/
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
const int N = 2005;
int n, m, p;
int a[N][N];
int ans[N][N];
ll comb[N][N];

void pre_work()
{
	for (int i = 0; i <= 2000; i++)comb[i][0] = comb[i][i] = 1;
	for (int i = 1; i <= 2000; i++)
		for (int j = 1; j <= i; j++) {
			comb[i][j] = ((comb[i - 1][j - 1] % p) + (comb[i - 1][j] % p)) % p;
		}
	for (int i = 0; i <= 2000; i++)
		for (int j = 0; j <= 2000; j++)
		{
			if(!comb[i][j] && i >= j) a[i][j] = 1;
		}
	for (int i= 0;i <= 2000;i++)
	{
		for(int j= 0;j <= 2000;j ++)
		{
			ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1] + a[i][j];
		}
	}
}

int main ()
{
	int t;
	read(t);
	read(p);
	pre_work();
	while (t--)
	{
		int n, m;
		read(n);
		read(m);
		if (m > n) m = n;
		cout << ans[n][m] << endl;
	}
	return 0;
}