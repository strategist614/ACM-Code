#include<bits/stdc++.h>
using namespace std;
int n;
inline bool IsPrime(int a)
{
        if (a==0 || a==1)
               return 0;
        for (int i = 2; i <= sqrt(a); i++)
                if (a % i == 0)
                        return 0;
        return 1;
}
int ans[20];
int vis[20];
inline void dfs(int now)
{
	if(now == n && IsPrime(ans[0]+ans[n-1]))
	{
		for(int i= 0;i<n;i++)
			printf("%d ",ans[i]);
		printf("\n");
		return ;
	}
	for(int i = 2;i <= n;i++)
	{
        if(!vis[i] && IsPrime(ans[now-1]+i))
        {
        	vis[i] = 1;
        	ans[now] = i;
        	dfs(now+1);
        	vis[i] = 0;
        }
	}
}
int main ()
{
    scanf("%d",&n);
    ans[0] = 1;
    dfs(1);
	return 0 ;
}