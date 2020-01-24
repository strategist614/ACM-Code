#include<bits/stdc++.h>
using namespace std;
struct node
{
	double x;
	double y;
}a[17];

double dis(node a,node b)
{
	double ans = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	return ans;
}

double minn = 1e9+0.5;
double ans = 0.0;
int vis[20];
int n;
void dfs(int dep,int now)
{
   if(ans > minn) return ;
   if(ans <= minn && dep == n)
   {
   	 minn = ans;
   	 return; 
   } 
   for(int i = 1;i <= n;i++)
   {
   	  if(!vis[i])
   	  {
   	  	 vis[i] = 1;
   	  	 ans += dis(a[now],a[i]);
   	  	 dfs(dep+1,i);
   	  	 ans -= dis(a[now],a[i]);
   	  	 vis[i] = 0;
   	  }
   }
}

int main ()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
    dfs(0,0);
    printf("%.2f\n",minn);
	return 0 ;
}