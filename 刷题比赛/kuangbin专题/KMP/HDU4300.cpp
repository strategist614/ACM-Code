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
int ex[N], Next[N];
char a[N], b[N];
void getNext()
{
	int i = 1;
	int n = strlen(b + 1);
	Next[1] = n;
	while (b[i] == b[i + 1] && i < n)
		i++;
	Next[2] = i - 1;
	int po = 2;
	for (int i = 3; i <= n; i++)
	{
		if (Next[i - po + 1] + i + 1 <= Next[po] + po)
			Next[i] = Next[i - po + 1];
		else
		{
			int j = Next[po] + po - i;
			if (j < 0) j = 0;
			while (i + j <= n && b[j + 1] == b[j + i])
				j++;
			Next[i] = j;
			po = i;
		}
	}
}
void ExKmp()
{
	int n = strlen(a + 1);
	int m = strlen(b + 1);
	int i = 0;
	while (a[i + 1] == b[i + 1] && i < n && i < m)
		i ++ ;
	ex[1] = i;
	int po = 1;
	getNext();
	for (int i = 2; i <= n; i++)
	{
		if (Next[i - po + 1] + i + 1 <= ex[po] + po)
			ex[i] = Next[i - po + 1];
		else
		{
			int j = ex[po] + po - i;
			if (j < 0) j = 0;
			while (i + j <= n && j + 1 <= m && a[j + i] == b[j + 1]) j ++;
			ex[i] = j;
			po = i;
		}
	}
}
int main ()
{
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	ExKmp();
	int n = strlen(a + 1);
	int m = strlen(b + 1);
	for (int i = 1; i <= n; i ++) cout << ex[i] << " ";
	return 0 ;
}
/*
aaaabba
aaaa
*/
