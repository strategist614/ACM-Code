#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
char a[9][9];
int b[10];
int ans = 0 ;
void dfs(int i,int dep)
{
	if(dep == k)
	{
		ans++;
		return ;
	}
	if(i > n) return;
	for(int j = 1;j<=n;j++)
	{
		if(!b[j] && a[i][j] == '#')
		{
            b[j] = 1;
            dfs(i+1,dep+1);
            b[j] = 0;
		}
	}
	dfs(i+1,dep);
}
int main ()
{
    while(scanf("%d %d",&n,&k) != EOF)
    {
    	if(n == -1 && k == -1) break;
        for(int i =1;i<=n;i++)
        	for(int j =1;j<=n;j++)
        		cin>>a[i][j];
        ans = 0;
        dfs(1,0);
        cout<<ans<<endl;
    }
	return 0 ;
}