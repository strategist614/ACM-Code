/*
#include<bits/stdc++.h>
using namespace std;
int a[50];
int vis[1005];
int aim = 0;
int f = 0;
int dfs(int st,int ed,int k)
{
	if(st == ed && k >= 2)
	{
		return 1;
	}
    for(int i = 1;i<=aim;i++)
    {
    	if(!vis[i])
    	{
    		vis[i] = 1;
    		if(dfs(st+a[i],ed,k+1)) return 1;
    		vis[i] = 0;
     	} 
    }
    return 0;
}
int main ()
{
	int n;
	int flag = 0;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i =1;i<=n;i++) cin>>a[i];
        int i;
        for(i =2;i<=n;i++)
        {
        	memset(vis,0,sizeof(vis));
        	aim = i-1;
            f = 0;
        	if(dfs(0,a[i],0)) 
        	{
        		break;
        	}
        }
        printf("Case #%d: ",++flag);
        for(int i =1;i<=n;i++)
        {
        	if(i == n) cout<<a[i];
        	else cout<<a[i]<<" ";
        }
        cout<<endl;
        if(i > n) cout<<"This is an A-sequence."<<endl;
        else cout<<"This is not an A-sequence."<<endl;
	}
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
int main ()
{
	
	return 0 ;
}