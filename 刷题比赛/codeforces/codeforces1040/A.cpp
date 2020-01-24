#include<bits/stdc++.h>
using namespace std;
int x[25];
int main ()
{
  int n,a,b;
  cin>>n>>a>>b;
  for(int i = 1;i<=n;i++) cin>>x[i];
  int my = min(a,b);
  int ans = 0;
  if(n%2)
 {
  for(int i = 1;i <=n/2+1;i++)
  {
    if(x[i] == x[n-i+1])
    {
      if(i == n/2+1)
      {
        if(x[i] == 2) {ans += my;break;}
        else continue;
      }
      if(x[i] == 1) continue;
      else if(x[i] == 0) continue;
      else  ans += my*2;
     }
    else
    {
      if(x[i] == 0)
      {
        if(x[n-i+1] == 1)
        {
          cout<<-1<<endl;
          return 0;
        }
        else ans += a;
      }
      else if(x[i] == 1)
      {
        if(x[n-i+1] == 0)
        {
          cout<<-1<<endl;
          return 0;
        }
        else
        {
          ans += b;
        }
      }
      else
      {
        if(x[n-i+1] == 0) ans += a;
        else ans +=  b;
      }
    }
  }
}
 else
 {
   for(int i =1;i<=n/2;i++)
   {
     if(x[i] == x[n-i+1])
     {
       if(x[i] == 1) continue;
       else if(x[i] == 0) continue;
       else ans += my*2;
     }
     else
     {
       if(x[i] == 1)
       {
         if(x[n-i+1] == 0) {
           cout<<-1<<endl;
           return 0;
         }
         else ans += b;
       }
       else if(x[i] == 0)
       {
         if(x[n-i+1] == 1)
         {
           cout<<-1<<endl;
           return 0;
         }
         else ans += a;
       }
       else
       {
         if(x[n-i+1] == 1) ans += b;
         else ans += a;
       }
     }
   }
 }
  cout<<ans<<endl;
  return 0;
}
