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
ll a[55];
int main ()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	int t = n;
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (a[j] > a[i]) swap(a[i], a[j]);
		}
		if (a[i] == 0) {t = i - 1; break;}
        for (int k = 63; k >= 0;k--)
        {
            if(a[i] >> k & 1)
            {
            	for(int j = 1;j <= n;j++)
            	{
            		if(i != j && (a[j] >> k & 1)) a[j] ^= a[i];
            	}
            	break;
            }
        }
	}
	for(int i = 1;i <= t;i++) ans ^= a[i];
	cout<<ans<<endl;
	return 0 ;
}