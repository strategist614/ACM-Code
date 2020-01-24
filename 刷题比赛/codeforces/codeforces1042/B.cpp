#include<bits/stdc++.h>
using namespace std;
pair<int,string> p[1005];
int main ()
{
  int n;
  cin>>n;
  set<pair<int,string>> s;
  set<pair<int,string>> s1;
  set<pair<int,string>> s2;
  set<pair<int,string>> s3;
  set<pair<int,string>> s4;
  set<pair<int,string>> s5;
  set<pair<int,string>> s6;
 for(int i  =1;i<=n;i++)
  {
    cin>>p[i].first>>p[i].second;
    string tmp = p[i].second;
    if(tmp.size() == 3) s.insert(p[i]);
  }
  for(int i  = 1;i <= n ; i++)
  {
    string tmp = p[i].second;
    if(tmp.size() == 1)
    {
      if(tmp == "A")
      {
        s1.insert(p[i]);
      }
      else if(tmp == "B")
      {
        s2.insert(p[i]);
      }
      else
      {
        s3.insert(p[i]);
      }
    }
    if(tmp.size() == 2)
    {
      if(tmp == "AB" || tmp == "BA")
      {
        s4.insert(p[i]);
      }
      if(tmp == "BC" || tmp == "CB")
      {
        s5.insert(p[i]);
      }
      if(tmp == "AC" || tmp == "CA")
      {
        s6.insert(p[i]);
      }
    }
  }
  int minx = (*s.begin()).first;
  int ans = 0;
  int minn = 2e9;
  if(minx != 0) minn = min(minx,minn);
  if(s1.size() != 0 && s2.size() != 0&& s3.size() != 0)
  {
    ans = (*s1.begin()).first + (*s2.begin()).first+(*s3.begin()).first;
    minn = min(minn,ans);
  }
  if(s1.size() != 0)
  {
    if(s5.size() != 0)
    {
      ans = (*s1.begin()).first+ (*s5.begin()).first;
      minn = min(minn,ans);
    }
  }
  if(s2.size() != 0)
  {
    if(s6.size() != 0)
    {
      ans = (*s2.begin()).first +(*s6.begin()).first;
      minn = min(minn,ans);
    }
  }
  if(s3.size() != 0)
  {
    if(s4.size() != 0)
    {
      ans = (*s3.begin()).first + (*s4.begin()).first ;
      minn = min(minn,ans);
    }
  }
  if(s4.size()  != 0){
    if(s5.size() != 0)
    {
      ans = (*s4.begin()).first + (*s5.begin()).first;
      minn = min(minn,ans);
    }
  }
  if(s5.size() != 0)
  {
    if(s6.size() != 0)
    {
      ans = (*s5.begin()).first + (*s6.begin()).first;
      minn = min(minn,ans);
    }
  }
  if(s4.size() != 0){
    if(s6.size() != 0 )
    {
      ans = (*s4.begin()).first + (*s6.begin()).first;
      minn = min(minn,ans);
    }
  }
  if(minn == 2e9)
  {
    cout<<-1<<endl;
    return  0;
  }
  cout<<minn<<endl;
  return 0 ;
}
