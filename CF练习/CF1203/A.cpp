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
typedef pair<int, int> pii;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
int sum[405];
int a[405];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int q;
	cin >> q;
	while (q--)
	{
		memset(sum, 0, sizeof(sum));
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int _ = (1 + n) * n / 2;
		for (int i = 1; i <= n; i++)
			a[n + i] = a[i];
		int flag = 0;
		for(int i =1;i <= 2 * n;i++)
		{
			if(a[i] == 1)
			{
				int _ = 0;
				for(int j = i;j <= i + n - 2;j++)
				{
					if(a[j] + 1 != a[j + 1]) _ = 1; 
				}
				if(!_) flag = 1;
			}  
			if(a[i] == n)
			{
				int _ = 0;
				for(int j = i;j <= i + n - 2;j++)
				{
					if(a[j] - 1 != a[j + 1]) _ = 1;
 				}
 				if(!_) flag = 1;
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0 ;
}