#include<iostream>
#include<cstdio>
using namespace std;
int a[105];
int tot = 0;
int mod = 0;
int found = 0;
int n;
void dfs(int mod,int dep)
{
   if(dep > 19 || found) return ;
   if(mod == 0)
   {
   	  for(int i= 0;i<= dep;i++)
   	  	cout<<a[i];
   	  cout<<endl;
   	  found = 1;
   	  return ;
   }
   a[dep+1] = 1;
   dfs((mod*10+1)%n,dep+1);
   a[dep+1] = 0;
   dfs((mod*10)%n,dep+1);
}
int main ()
{
	while(scanf("%d",&n)!=EOF && n)
	{
       found = 0;
       a[0] = 1;
       dfs(1 % n,0);
	}
	return 0 ;
}