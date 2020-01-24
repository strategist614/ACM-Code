/*
#include<bits/stdc++.h>
using namespace std;
int main ()
{
  int n;
  scanf("%d",&n);
  int ans = 0;
  priority_queue<int,vector<int>,greater<int> > qmin;
  for(int i =1;i<=n;i++)
  {
    int a;
    scanf("%d",&a);
    qmin.push(a);
  }
  while(qmin.size() != 1)
  {
    int x = qmin.top();
    qmin.pop();
    int y = qmin.top();
    qmin.pop();
    ans += x+y;
    qmin.push(x+y);
  }
  cout<<ans<<endl;
  return 0 ;
}
*/
