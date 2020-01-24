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
const int N = 1300000;
int p = 0;
int prime[N];
bool is_prime[N];
void sieve() {
	for (int i = 0; i <= N; i++)is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= N; i++) {
		if (is_prime[i]) {
			prime[++p] = i;
			for (int j = 2 * i; j <= N; j += i)is_prime[j] = false;
		}
	}
}
int t;
int main ()
{
	int n;
	sieve();
	while (scanf("%d", &n) != EOF && n)
	{
		int tmp = lower_bound(prime + 1, prime + p + 1, n) - prime;
        if(prime[tmp] == n)
        {
        	cout<<0<<endl;
        }
        else 
        {
        	cout<<prime[tmp]-prime[tmp-1]<<endl;
        }
	}
	return 0 ;
}