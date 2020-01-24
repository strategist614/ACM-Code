#include<bits/stdc++.h>
using namespace std;
char a[105][105];
std::vector<char> v;
int vis[105];
int b[105];
int main ()
{
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j<=m;j++)
            cin>>a[i][j];
    int ans = 0; 
    for(int i =1;i <= m;i++)
     {
     	int judge = 0;
     	for(int j = 1;j <= n-1;j++)
     	{
           if(b[j] == 1) continue;
           if(a[j+1][i] < a[j][i]) judge = 1;
     	}
     	if(judge == 1) vis[i] = 1;
     	else 
     	{
     		for(int j = 1;j <= n-1;j++)
     			if(a[j+1][i] > a[j][i]) b[j] = 1;
     	}
    }
    for(int i = 1;i<=m;i++) if(vis[i] == 1) ans++;
    cout<<ans<<endl;
	return 0 ;
}