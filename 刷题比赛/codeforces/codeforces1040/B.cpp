#include<bits/stdc++.h>
using namespace std;
int main ()
{
  int n,k;
  cin>>n>>k;
  if(k == 0)
  {
    cout<<n<<endl;
    for(int i= 1;i<=n;i++)
    cout<<i<<" ";
  }
  else
  {
    int tmp = 2*k+1;
    if(n % tmp == 0)
    {
      int cnt = n/tmp;
      int ans = k+1;
      cout<<cnt<<endl;
      for(int i = 1;i<=cnt;i++)
      {
        cout<<ans<<" ";
        ans += tmp;
      }
      return 0;
    }
    if(n % tmp > k)
    {
      int cnt = n / tmp;
      int ans = k+1;
      cout<<cnt+1<<endl;
      for(int i = 1;i<=cnt+1;i++)
      {
        cout<<ans<<" ";
        ans += tmp;
      }
    }
    else
    {
      int cnt = n/tmp;
      int mp = n %tmp;
      cout<<cnt+1<<endl;
      int ans = 1;
      for(int i = 1;i<=cnt+1;i++)
      {
        cout<<ans<<" ";
        ans += tmp;
      }
  }
}
  return 0;
}
