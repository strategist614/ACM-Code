#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int f[N];
int w[10005];
int v[10005];
int main ()
{
    int n,m;
    cin>>n>>m;
    for(int i= 1;i <= m;i++) cin>>v[i]>>w[i];
    memset(f,0xcf,sizeof(f));
    f[0] = 0;
    for(int i = 1;i <= m;i++)
    {
    	for(int j = v[i];j <= n;j++)
    		f[j] = max(f[j],f[j-v[i]]+w[i]);
    }
    int ans = 0 ;
    for(int j = 0;j <= n;j++) ans = max(ans,f[j]);
    cout<<ans<<endl;
	return 0 ;
}