#include<bits/stdc++.h>
using namespace std;
int  gcd(int x,int y)
{
   if(y == 0) return x;
   return gcd(y,x%y);
}
int vis[45006];
int main ()
{
  int n;
  cin>>n;
  int sum = ((1+n)*n)/2;
  int ans = 0;
  for(int i = 1;i<=n;i++)
  {
    if(gcd(i,sum) > 1)
    {
      ans = i;
      vis[i]++;
      break;
    }
    if(i == n)
    {
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  cout<<1<<" "<<ans<<endl;
  cout<<n-1<<" ";
  for(int i = 1;i<=n;i++)
  {
    if(!vis[i])
    cout<<i<<" ";
  }
  return 0;
}
