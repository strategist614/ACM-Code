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
const int N =   1e7 + 5;
int prime[N/10];
bool is_prime[N];
int tot = 0;
void sieve()
{
  for (int i = 1; i <= N; i++) is_prime[i] = 1;
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i <= N; i++)
  {
    if (is_prime[i])
    {
      prime[++tot] = i;
      for (int j = 2 * i; j <= N; j += i) is_prime[j] = 0;
    }
  }
}
ll solve(ll n)
{
  ll ans = 1;
  for (int i = 1; i <= tot && n > 1; i++)
  {
    if (n % prime[i] == 0)
    {
      int c = 0;
      while (n % prime[i] == 0)
      {
        n /= prime[i];
        c++;
      }
      ans *= (2 * c + 1);
    }
  }
  if (n > 1) ans *= 3;
  ans = (ans + 1) / 2;
  return ans;
}
int main ()
{
  int t;
  int flag = 0;
  read(t);
  sieve();
  while (t--)
  {
    ll n;
    read(n);
    printf("Case %d: %lld\n", ++flag, solve(n));
  }
  return 0 ;
}