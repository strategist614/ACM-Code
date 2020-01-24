/*#include<bits/stdc++.h>
using namespace std;
int f[30][30005];
int w[30];
int v[30];
int main ()
{
	int n,m;
	cin>>n>>m;
    memset(f,0xcf,sizeof(f));
    f[0][0] = 0;
    for(int i= 1;i<=m;i++)
    {
    	int x;
        cin>>v[i];
        cin>>x;
    	w[i] = x*v[i];
    }
    for(int i= 1;i<=m;i++)
    {
    	for(int j =0;j<=n;j++)
    		f[i][j] = f[i-1][j];
        for(int j = v[i];j<=n;j++)
        	f[i][j] = max(f[i][j],f[i-1][j-v[i]]+w[i]);
    }
    int ans = 0;
    for(int j = 0;j <= n;j++) ans = max(ans,f[m][j]);
    cout<<ans<<endl;
	return 0; 
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int f[30][30005];
int w[30];
int v[30];
int main ()
{
	int n,m;
	cin>>n>>m;
    memset(f,0xcf,sizeof(f));
    f[0][0] = 0;
    for(int i= 1;i<=m;i++)
    {
    	int x;
        cin>>v[i];
        cin>>x;
    	w[i] = x*v[i];
    }
    for(int i= 1;i<=m;i++)
    {
    	for(int j =0;j<=n;j++)
    		f[i & 1][j] = f[(i-1) & 1][j];
        for(int j = v[i];j<=n;j++)
        	f[i&1][j] = max(f[i&1][j],f[(i-1)&1][j-v[i]]+w[i]);
    }
    int ans = 0;
    for(int j = 0;j <= n;j++) ans = max(ans,f[m&1][j]);
    cout<<ans<<endl;
	return 0; 
}
*/
#include<bits/stdc++.h>
using namespace std;
int f[30005];
int w[35];
int v[35];
int main ()
{
    int n,m;
    cin>>n>>m;
    for(int i= 1;i<=m;i++)
    {
        int x;
        cin>>v[i];
        cin>>x;
        w[i] = v[i] * x;
    }
    f[0] = 0;
    for(int i= 1;i<=m;i++)
    {
        for(int j = n;j >= v[i];j--)
            f[j] = max(f[j],f[j-v[i]]+w[i]);
    }
    int ans = 0;
    for(int i = 0;i<=n;i++) ans = max(ans,f[i]);
    cout<<ans<<endl;
    return 0 ;
}