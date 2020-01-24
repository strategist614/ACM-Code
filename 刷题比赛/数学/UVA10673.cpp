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
ll c, k;
ll a, b, x, y;

void exgcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) { x = 1, y = 0; return ; }
	exgcd(b, a % b, x, y);
	int z = x; x = y; y = z - y * (a / b);
}

int main ()
{
	int t;
	read(t);
	while (t--)
	{
		read(c);
		read(k);
		a = c / k;
		b = ceil((double)c / k);
		exgcd(a, b, x, y);
		x = x * c / gcd(a, b);
		y = y * c / gcd(a, b);
        cout<<x<<" "<<y<<endl;
	}
	return 0 ;
}