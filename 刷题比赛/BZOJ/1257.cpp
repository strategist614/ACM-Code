#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int main ()
{
	  ll n,k;
    scanf("%lld %lld",&n,&k);
    ll ans = n*k;
    ll j;
    ll tmp = 0;
    for(ll i = 1;i<=n;i = j+1)
    {
    	j = k/i ? min(n,k/(k/i)):n;
      ans -= (i+j)*(j-i+1)/2*(k/i);
    }
    printf("%lld\n",ans);
	return  0;
}
/*
5 3
*/
//分块整除