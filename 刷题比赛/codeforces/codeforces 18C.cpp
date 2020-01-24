#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
int sum[N];
int main ()
{
	int n;
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<=n;i++) sum[i] = sum[i-1]+a[i];
    int ans = 0;
    for(int i = 1;i<=n-1;i++)
    {
    	if(sum[i]-sum[0] == sum[n] -sum[i])
    		ans++;
    }
    cout<<ans<<endl;
	return 0 ;
}