#include<bits/stdc++.h>
using namespace std;
int a[104];
int vis[104];
int main ()
{   
	int n;
	cin>>n;
	for(int i= 1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
      if(!vis[i])
       { 
        int tmp = a[i];
        int last = a[i];
        vis[i] = 1;
        int cnt = 1;
        for(int j = i;j<=n;j++)
        {
           if(!vis[j])
           {
           	  if(cnt <= last)
          	  {
           	   if(a[j] >= last)
               {
                  vis[j] = 1;
                  last = a[j];
                  cnt++;
               }
           	}
           	 else 
           	  {
                if(a[j] > last)
                {
                	vis[j] = 1;
                	last = a[j];
                	cnt++;
                }
           	  }
           }     
        }
        ans++;
      }
    }
   cout<<ans<<endl;
	return 0 ;
}