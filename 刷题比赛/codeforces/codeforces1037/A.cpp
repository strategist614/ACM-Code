#include<bits/stdc++.h>
using namespace std;
int main ()
{
  int sum = 0;
  int ans = 0;
  int n,s;
  cin>>n>>s;
  for(int i = 1;i<=n;i *= 2)
  {
    sum += i;
    ans++;
    if(sum>=n) break;
}
  cout<<ans<<endl;
  return 0;
}
