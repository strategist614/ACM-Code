#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10005];
vector<int> ans;
int main ()
{
  ll n;
  cin>>n;
  for(int i = 1;i <= n;i++) cin>>a[i];
  for(int i = 1;i <= n;i++)
  {
   for(int j = i+1;j<=n;j++)
   {
     if(a[j] > a[i])
     {
       ans.push_back(j);
       break;
     }
     if(j == n)
     {
       ans.push_back(0);
       break;
     }
   }
 }
  for(int i = 0;i<ans.size();i++)
   cout<<ans[i]<<" ";
  cout<<0<<endl;
  return 0;
}
