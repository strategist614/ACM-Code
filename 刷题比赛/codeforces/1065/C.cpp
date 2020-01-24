/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
ll a[N];
ll sum[N];
ll c[N];
int main ()
{
    int n,k;
    cin>>n>>k;
    for(int i= 0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    reverse(a,a+n);
    if(n == 1)
    {
        cout<<0<<endl;
        return 0 ;
    }
    ll ans = 0;
    ll cost = 0;
    for(int i = a[0],p = 1;p <= n;i--)
    {
        while(a[p] == i && p <= n) p++;
        if(p == n) break;
        if(cost + p > k)
        {
           ans++;
           cost = p;
        }
        else cost += p;
    }
    if(cost != 0) ans++;
    cout<<ans<<endl;
    return 0 ;
}
*/
