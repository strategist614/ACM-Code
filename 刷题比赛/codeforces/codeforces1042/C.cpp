#include<bits/stdc++.h>
using namespace std;
int a[200010];
vector<int> ans;
vector<pair<int,int>> ansv;
vector<pair<int,int>> ansm;
int main ()
{
  int n;
  cin>>n;
  for(int i= 1;i<=n;i++) cin>>a[i];
  for(int i =1;i<=n;i++)
  {
    if(a[i] == 0)
    ans.push_back(i);
    else if(a[i] < 0) ansv.push_back(make_pair(a[i],i));
    else ansm.push_back(make_pair(a[i],i));
  }
  if(ans.size() != 0)
  {
    if(ansm.size() != 0)
    {
    if(ans.size() != 1)
    {
      for(int i= 1;i <= n -1;i++)
      {
        cout<<1<<" "<<i<<" "<<i+1<<endl;
      }
    }
    else
    {
     cout<<2<<" "<<ans[0]<<endl;
     int last = ansv[0].second;
     for(int i = 0;i<ansv.size() - 1;i++)
     {
       cout<<1<<" "<<last<<" "<<ansv[i+1].second<<endl;
       last = ansv[i+1].second;
     }
   }
 }
   if(ansv.size() != 0)
   {
     if(ans.size() == 1)
     {
       if(ansv.size() % 2 == 0)
       {
         cout<<2<<" "<<ans[0]<<endl;
         int last = ansm[0].second;
         for(int i = 0;i<ansm.size() - 1;i++)
         {
           cout<<1<<" "<<last<<" "<<ansm[i+1].second<<endl;
           last = ansm[i+1].second;
         }
       }
       else
       {
         for(int i= 1;i <= n -1;i++)
         {
           cout<<1<<" "<<i<<" "<<i+1<<endl;
         }
       }
     }
     else
     {
       for(int i= 1;i <= n -1;i++)
       {
         cout<<1<<" "<<i<<" "<<i+1<<endl;
       }
     }
   }
}

 return 0;
}
