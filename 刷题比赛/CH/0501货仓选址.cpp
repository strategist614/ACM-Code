#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int a[N];
int main ()
{
	int n;
	cin>>n;
	for(int i= 1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int mid = 0;
    if(n%2) mid = (a[n/2]+a[n/2+1])/2;
    else mid = a[n/2+1];
    ll ans = 0;
    for(int i= 1;i<=n;i++)
    {
       ans += abs(mid-a[i]);
    }
    printf("%lld\n",ans);
	return 0 ;
}