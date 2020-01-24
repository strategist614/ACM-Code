#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
  int t;
  ll n,a;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%lld %lld",&n,&a);
    if(n == 1)
    {
      printf("1 %lld",a+1);
    }
    else if(n == 2)
    {
      if(a %2 )
      {
        printf("%lld %lld\n",(a*a-1)/2,(a*a+1)/2);
      }
      else
      {
        printf("%lld %lld\n",(a*a-4)/4,(a*a+4)/4);
      }
    }
    else
    {
      printf("-1 -1\n");
    }
  }
  return 0;
}
