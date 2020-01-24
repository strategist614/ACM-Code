#include<bits/stdc++.h>
using namespace std;
priority_queue<int> qmax;
priority_queue<int,vector<int>,greater<int> >qmin;
int n,m,mid;
void add(int x)
{
  if( x < mid )
  {
    qmax.push(x);
    if(qmax.size() == qmin.size() + 2)
    {
      qmin.push(mid);
      mid = qmax.top();
      qmax.pop();
    }
}
  else
  {
    qmin.push(x);
    if(qmin.size() == qmax.size() +2)
    {
      qmax.push(mid);
      mid = qmin.top();
      qmin.pop();
    }
 }
}
int main ()
{
  scanf("%d %d",&n,&mid);
  for(int i = 2;i<=n;i++)
  {
    int a;
    scanf("%d",&a);
    add(a);
    cout<<qmax.top()<<endl;
    cout<<qmin.top()<<endl;
  }
  scanf("%d",&m);
  while(m--)
  {
     char opt[20];
     scanf("%s",opt);
     if(opt[0] == 'a')
     {
       int x;
       scanf("%d",&x);
       add(x);
       cout<<qmax.top()<<endl;
       cout<<qmin.top()<<endl;
     }
     else
     {
       int ans;
       if(qmax.size() > qmin.size())
       {
         ans = qmax.top();
       }
       else  ans = mid;
     }
  }
  return 0;
}
