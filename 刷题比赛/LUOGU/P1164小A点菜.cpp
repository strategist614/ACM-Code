#include<bits/stdc++.h>
using namespace std;
int f[1005];
int v[105];
int main ()
{
    int n,m;
    cin>>n>>m;
    for(int i= 1;i<=n;i++) cin>>v[i];
    memset(f,0,sizeof(f));
    f[0] = 1;
    for(int i = 1;i <= n;i++)
      {
      	for(int j = m;j >= v[i];j--)
      		f[j] += f[j-v[i]];
      }
    cout<<f[m]<<endl;
	return 0 ;
}