#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
set<pair<int,int>> s;
int ans[N],a[N],n,m,d;
int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m>>d;
  for(int i =1;i<=n;i++)
  {
    cin>>a[i];
    s.insert({a[i],i});
  }
  int cnt = 0;
  while(!s.empty())
  {
    cnt++;
    int pos = s.begin()->second;
    ans[pos] = cnt;
    s.erase(s.begin());
    while(1){
       auto it = s.lower_bound({a[pos]+d+1,0});
       if(it == s.end()) break;
       pos = it->second;
       s.erase(it);
       ans[pos] = cnt;
    }
  }
  cout<<cnt<<endl;
  for(int i = 1;i<=n;i++)
   cout<<ans[i]<<" ";
  return 0 ;
}
