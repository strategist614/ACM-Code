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
const int N =  11000005;
int p[N << 1];
char a[N], s[N << 1];
int tot = 0;
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	scanf("%s", a + 1);
	int n = strlen(a + 1);
	s[++tot] = '$';
	s[++tot] = '#';
	for (int i = 1; i <= n; i++)
	{
		s[++tot] = a[i];
		s[++tot] = '#';
	}
	int rx = 0, mid = 0;
	for (int i = 2; i <= tot; i++)
	{
		p[i] = i < rx ? min(p[(mid << 1) - i], rx - i) : 1;
		while (s[i - p[i]] == s[i + p[i]])
			p[i]++;
        if(i + p[i] > rx)
        {
        	rx = i + p[i];
        	mid =  i;
        } 
	}
	int ans = 0;
	for(int i = 2;i <= tot;i++)
	{
		ans = max(ans,p[i] - 1);
	}
	cout << ans << endl;
	return 0 ;
}