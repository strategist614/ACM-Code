#include<bits/stdc++.h>
using namespace std;
char a[105][105];
int b[105][105];
int vis[105][105];
int main ()
{
	memset(vis,0,sizeof(vis));
	int n;
	cin>>n;
    for(int i =1;i<=n;i++)
    	for(int j  =1;j<=n;j++)
    		 cin>>a[i][j];
    for(int i = 1;i<=n;i++)
    	for(int j = 1;j<=n;j++)
    	{
    		if(a[i][j] == '#') b[i][j] = 1;
    		if(a[i][j] == '.') b[i][j] = 0;
    	}
    for(int i = 1;i<=n;i++)
    	for(int j = 1;j<=n;j++)
    	{
            if(!vis[i][j])
            {
            	if(b[i][j] == 1)
            	{
            		if(b[i+1][j] == 1 && b[i-1][j] == 1 && b[i][j+1] == 1 && b[i][j-1] == 1) 
            		{
            			if(!vis[i+1][j] && !vis[i-1][j] && !vis[i][j+1] && !vis[i][j-1])
            			{
            			vis[i][j] = 1;
            			vis[i+1][j] = 1;
            			vis[i-1][j] = 1;
            			vis[i][j+1] = 1;
            			vis[i][j-1] = 1;
            		}
            	   }
            	}
            }
    	}
    int ans = 0;
    for(int i = 1;i<=n;i++)
    	for(int j  =1;j<=n;j++)
    	{
    		if(!vis[i][j])
    		{
    			if(b[i][j] == 1) ans++;
     		}
    	}
    if(ans == 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
	return 0 ;
}