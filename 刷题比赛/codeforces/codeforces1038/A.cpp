#include<bits/stdc++.h>
using namespace std;
int a[26];
int main ()
{
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  for(int i= 0;i<s.size();i++)
  {
    a[s[i] -'A']++;
  }
  int mina = 1e9;
  for(int i = 0;i<k;i++)
  {
    if(a[i] != 0)
    {
      mina = min(a[i],mina);
    }
    else
    {
      cout<<0<<endl;
      return 0;
    }
  }
  cout<<mina*k<<endl;
  return 0;
}
