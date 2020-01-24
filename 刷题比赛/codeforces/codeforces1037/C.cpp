#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a,b;
  cin>>n;
  cin>>a>>b;
  v.push_back(0);
  for(int i = 0;i<n;i++)
  {
     if(a[i] != b[i]) v.push_back(i);
  }
  int ans = 0;
  for(int i = 1;i<=v.size() -1;)
  {
    if(v[i+1] - v[i] == 1){
      if(a[v[i+1]] != a[v[i]]) ans++,i += 2;
      else ans++,i++;
    }
    else ans++,i++;
  }
  cout<<ans<<endl;
  return 0;
}
