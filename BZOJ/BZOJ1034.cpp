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
int a[N];
int b[N];
int n;
int solve(int a[], int b[])
{
	int la = 1;
	int ra = n;
	int lb = 1;
	int rb = n;
	int ans = 0;
	while (la <= ra && lb <= rb)
	{
		if (a[la] > b[lb]) {ans += 2; la++; lb++;}
		else if (a[ra] > b[rb]) {ans += 2; ra--; rb--;}
		else {
			ans += (a[la] == b[rb]);
			la++;
			rb--;
		}
	}
	return ans;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	//int n;
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++)
		read(b[i]);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	cout << solve(a, b) <<" "<< 2 * n - solve(b, a) << endl;
	return 0 ;
}