#include<bits/stdc++.h>
using namespace std;
int a[200050];
int main ()
{
  int n;
  cin>>n;
  for(int i = 1;i<=n;i++)
  cin>>a[i];
  int x = *min_element(a+1,a+n+1);
  vector<int> v;
  for(int i = 1;i<=n;i++)
  {
    if(a[i] == x)
    {
      v.push_back(i);
    }
  }
  int tmp = 0;
  int minn = 2e9;
  for(int i = 0;i<v.size()-1;i++)
  {
    tmp = v[i+1]-v[i];
    minn = min(minn,tmp);
  }
  cout<<minn<<endl;
  return 0 ;
}
