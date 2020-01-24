void divide(int n)
{
   m = 0;
   memset(p,0,sizeof(p));
   memset(c,0,sizeof(c));
   for(int i= 2;i<=sqrt(n);i++)
   {
   	if(n % i == 0)
   	{
   		p[++m] = i;c[i] = 0;
   		while(n % i == 0) n /= i,c[m]++;
   	}
   }
   if(n > 1) p[++m] = n,c[m] = 1;
}

int gcd(int a,int b)
{
  return b ? gcd(b % a,a):a;
}

int mypow(int a,int b,int mod)
{
   int res = a % mod;
   while(b)
   {
      if(b & 1) res = res * a %mod;
      b >>= 1;
      a = a * a %mod;
   }
   return res ;
}

int prime[MAXN];
int is_prime[MAXN];
int sieve(int n)
{
   int p = 0;
   for(int i= 0;i<=n;i++) is_prime[i] = 1;
   is_prime[0] = is_prime[1] = 0;
   for(int i= 2;i<=n;i++)
   {
      if(is_prime[i])
      {
         prime[++p] = i;
         for(int j = 2*i;j<=n;j+=i) is_prime[j] = 0;
      }
   }
   return p;
}

void divid(int n)
{
   m = 0;
   for(int i= 2;i<=sqrt(n);i++)
   {
      if(n % i == 0) 
      {
         p[++m] = i,c[m] = 0;
         while(n % i == 0) n/=i,c[m]++;
      } 
   }
   if(n > 1) 
      p[++m] = n,c[m] = 1;
}
/*
独立思考
*/
#include<bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
   x = 0;
   char c = getchar();
   int sgn = 1;
   while(c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
   while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
   x*=sgn;
}
template <typename T>
void out(T x)
{
   if(x<0){putchar('-');x=-x;}
   if(x>=10)out(x/10);
   putchar(x%10+'0');
}
typedef long long ll;
typedef unsigned long long ull;
int main ()
{
   
   return 0 ;
}