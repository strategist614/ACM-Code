#include<bits/stdc++.h>
using namespace std;
const int N = 5000;
int vis[N];
int a[N];
int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		int n;
		cin>>n;
		int x;
		cin>>x;
		for(int i= 1;i<=x;i++) cin>>a[i];
		for(int i= 1;i<=n;i++)
		{
			 for(int j= 1;j<=x;j++)
			 { 
               if(i >= a[j] && i % a[j] == 0)
               {
               	   
                   if((i+1) % 7 != 0 && i % 7 != 0)
                   	vis[i] = 1;
               }
			}
		}
		int ans = 0;
		for(int i= 1;i <= n;i++) if(vis[i]) ans++;
		cout<<ans<<endl;
	}
	return 0 ;
}