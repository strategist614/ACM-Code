/*
#include<bits/stdc++.h>
using namespace std;
int a[104];
int n,m;
int solve(int mid)
{
  int sum = m;
  for(int i = 1;i <= n;i++)
  {
    int tmp = mid - a[i];
    sum -= tmp;
  }
  if(sum <= 0) return 1;
  else return 0;
}
int main ()
{
  cin>>n>>m;
  for(int i = 1;i<=n;i++) cin>>a[i];
  int maxn =*max_element(a+1,a+n+1);
  if(n == 1)
  {
    cout<<maxn + m<<" "<<maxn+m<<endl;
    return 0;
  }
  int ans = 0;
  for(int i = maxn;i <= maxn+m;i++)
  {
    if(solve(i))
    {
      ans = i;
      break;
    }
  }
  cout<<ans<<" "<<maxn+m<<endl;
  return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
int a[104];
int n,m;
int solve(int mid)
{
  int sum = m;
  for(int i = 1;i <= n;i++)
  {
    int tmp = mid - a[i];
    sum -= tmp;
  }
  if(sum <= 0) return 1;
  else return 0;
}
int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 1;i<=n;i++) cin>>a[i];
  int maxn =*max_element(a+1,a+n+1);
  if(n == 1)
  {
    cout<<maxn + m<<" "<<maxn+m<<endl;
    return 0;
  }
  int l = maxn;
  int r = maxn +m;
  while(l<r)
  {
    int mid = (l+r)>>1;
    if(solve(mid)) r = mid;
    else l = mid+1;
  }
  cout<<l<<" "<<maxn+m<<endl;
  return 0 ;
}
