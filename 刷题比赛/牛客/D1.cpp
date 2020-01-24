#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
ll a[N];
int main ()
{
	ll n;
	scanf("%lld",&n);
	for(int i = 1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
    ll ans = 0;
    for(int i = 2;i<=n;i++) ans += (ll)a[i];
    ans += (ll)(n-1)*a[1];
    printf("%lld\n",ans);
	return 0 ;
}