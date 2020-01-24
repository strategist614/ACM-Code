#include<bits/stdc++.h>
using namespace std;
int n;
int vis[1000];
int a[1000];
void dfs(int k)
{
   if(k == n+1)
   {
      for(int i= 1;i<=n;i++)
      {
      	 printf("%5d",a[i]);
      }
      printf("\n");
      return ;
   } 
   for(int i =1;i<=n;i++)
   {
       if(vis[i]) continue;
       vis[i] = 1;
       a[k] = i;
       dfs(k+1);
       a[k] = 0;
       vis[i] = 0;
   }  
}
int main ()
{
	cin>>n;
    dfs(1);
	return 0 ;
}