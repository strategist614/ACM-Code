#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
typedef long long ll;
int judge(int n)
{
  int sum = 0;
  if(n == 0) return 0;
  while(n)
  {
    sum++;
    n /= 10;
  }
  if(sum == 2) return 2;
  if(sum == 1) return 1;
}
int main ()
{
  ll T;
  scanf("%lld",&T);
  while(T--)
  {
    ll n;
    char c;
    scanf("%lld %c",&n,&c);
    string s;
    cin>>s;
    int cnt = s.size();
    int ans = 0;
    int tmp = abs(s[0] - c);
    if(judge(tmp) == 2) {printf("%d\n",cnt*2);}
    else if(judge(tmp) == 1)  {printf("%d\n",cnt*2 - 1);continue;}
    else
    {
    int ans = cnt*2 - 2;
    for(int i = 1;i<cnt;i++)
    {
      int x = abs(s[i] - c);
      if(judge(x) == 0) ans -= 2;
      else if(judge(x) == 2) break;
      if(judge(x) == 1)
      {
        ans -= 1;
        break;
     }
    }
    if(ans == 0) ans = 1;
    printf("%d\n",ans);
   }
  }
  return 0;
}
