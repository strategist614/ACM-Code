/*
#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int f[1005][1005];
int main ()
{
	int n;
	cin>>n;
	for(int i= 1;i<=n;i++)
      for(int j =1;j<=i;j++)
      	 cin>>a[i][j];
    f[1][1] = a[1][1];
    for(int i= 2;i <= n;i++)
    	for(int j= 1;j <= i;j++)
    	{
           f[i][j] += max(f[i-1][j-1],f[i-1][j])+a[i][j];
    	}
    int ans = 0;
    for(int i= 1;i<=n;i++)
      ans = max(ans,f[n][i]);
    cout<<ans<<endl;
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int f[1005][1005];
int main ()
{
	int n;
	cin>>n;
	for(int i= 1;i<=n;i++)
		for(int j= 1;j<=i;j++)
           cin>>a[i][j];
    for(int i= 1;i<=n;i++)
    	f[n][i] = a[n][i];
    for(int i = n-1;i>=1;i--)
    	for(int j =1;j<=i;j++)
    		f[i][j] = max(f[i+1][j],f[i+1][j+1])+a[i][j];
    cout<<f[1][1]<<endl;
	return 0 ;
}