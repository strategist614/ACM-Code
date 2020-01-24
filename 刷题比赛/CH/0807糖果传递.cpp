#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
int a[N];
ll sum = 0;
ll f[N];
int main ()
{
    int n;
    cin>>n;
    for(int i= 1;i<=n;i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    sum /= n;
    for(int i= 1;i<=n;i++)
    {
    	a[i] -= sum; 
    }
    for(int i= 1;i<=n;i++)
    	f[i] = f[i-1]+a[i];
    sort(f+1,f+n+1);
    ll mid = 0;
    if(n % 2)
    {
    	 mid = f[n/2+1];
    }
    else mid = (f[n/2+1]+f[n/2])/2;
    ll ans=  0;
    for(int i= 1;i<=n;i++)
    {
    	ans += abs(f[i]-mid);
    }
    cout<<ans<<endl;
	return 0 ;
}