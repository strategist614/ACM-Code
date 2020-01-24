#include<bits/stdc++.h>
using namespace std;
set<int> a;
set<int> b;
void Solvea(int x)
{
  for(int i = 1;i<=sqrt(x);i++)
  {
    if(x % i == 0)
    {
      a.insert(i);
      a.insert(x/i);
    }
  }
}
void Solveb(int x)
{
  for(int i =1;i<=sqrt(x);i++)
  {
    if(x % i == 0)
    {
      b.insert(i);
      b.insert(x/i);
    }
  }
}
int main ()
{
  int T;
  cin>>T;
  while(T--)
  {
    int A,B;
    cin>>A>>B;
    a.clear();
    b.clear();
    Solvea(A);
    Solveb(B);
    int ans = 0;
    for(set<int>::iterator it = b.begin();it != b.end();it++)
    {
      if(a.find(*it) != a.end()) ans++;
    }
    int x = a.size();
    int y = b.size();
    cout<<x*y - (ans*(ans-1))/2<<endl;
  }
  return 0 ;
}
