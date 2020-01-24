//1
#include<bits/stdc++.h>
using namespace std;
int t,id,n,mid;
priority_queue<int,vector<int>,less<int> > qmax;
priority_queue<int,vector<int>,greater<int> > qmin;
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
  scanf("%d",&t);
  while(t--)
  {
    while(qmax.size()) qmax.pop();
    while(qmin.size()) qmin.pop();
    scanf("%d %d",&id,&n);
    printf("%d %d\n",id,n+1>>1);
    scanf("%d",&mid);
    printf("%d ",mid);
    int cnt = 1;
    for(int i = 2;i <= n;i++)
    {
      int x;
      scanf("%d",&x);
      add(x);
      if(i % 2)
      {
       ++cnt;
       int ans ;
       ans = mid;
       if(cnt % 10 == 0) printf("%d\n",ans) ;
       else printf("%d ",ans);
      }
    }
    if(cnt % 10 != 0) printf("\n");
  }
  return 0 ;
}
//2
#include<bits/stdc++.h>
using namespace std;
int t,id,n,mid;
priority_queue<int,vector<int>,less<int> > qmax;
priority_queue<int,vector<int>,greater<int> > qmin;
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
  scanf("%d",&t);
  while(t--)
  {
    int cnt = 1;
    while(qmax.size()) qmax.pop();
    while(qmin.size()) qmin.pop();
    scanf("%d %d",&id,&n);
    printf("%d %d\n",id,n+1>>1);
    for(int i = 1;i <= n;i++)
    {
      int x;
      scanf("%d",&x);
      if(qmax.empty())
      {
        qmax.push(x);
        mid = x;
        printf("%d ",x);
        continue;
      }
      add(x);
      if(i % 2)
      {
       ++cnt;
       if(qmax.size() > qmin.size()) mid = qmax.top();
       else mid = qmin.top();
       if(cnt % 10 == 0) printf("%d\n",mid);
       else printf("%d ",mid);
      }
      else mid = (qmin.top() + qmax.top()) /2;
    }
    if(cnt % 10 != 0) printf("\n");
  }
  return 0 ;
}
