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
char s[105];
void  Headshot()
{
	int a = 0, b = 0, n;
	n = strlen(s);
	for (int i = 0; i < n; i++) {
		if (s[i] == '0' && s[(i + 1)%n] == '0') a++;
	    if (s[i] == '0') b++;
	}
	int _ = b * b;
	int __ = a * n ;
    if(__ > _) printf("SHOOT\n");
    else if(__ == _) printf("EQUAL\n");
    else printf("ROTATE\n");
}
int main ()
{
	while (scanf("%s", s) != EOF)
	{
		Headshot();
	}
	return 0 ;
}