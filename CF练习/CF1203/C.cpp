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
const int N = 4e5 + 5;
ll a[N];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++) read(a[i]);
	ll g = a[1];
	for (int i = 2; i <= n; i++)
		g = gcd(g, a[i]);
    int ans = 0;
    if(g != 1) ans += 2;
    else ans += 1;
    for(int i = 2;i <= sqrt(g);i++)
    {
    	if(g % i == 0)
    	{
    		ans ++;
    		if(g / i != i) ans ++;
    	}
    }
    cout << ans << endl;
	return 0 ;
}