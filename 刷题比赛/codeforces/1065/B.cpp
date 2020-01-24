#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main ()
{
	ll n,m;
	cin>>n>>m;
	if(m == 0){
		cout<<n<<" "<<n<<endl;
        return 0;
	}
    ll minn,maxn;
    ll ans = 0;
    for(int i= 1;i<=n;i++)
    {
        ans = (ll)((ll)(i-1)*(ll)i)/2;
        if(ans >= m)
        {
        	maxn = i;
        	break;
        }
    }
    if(maxn != 0) maxn = n-maxn;
    else maxn = 0;
    if(n > (ll)(m*2))
    {
         minn = (ll)(n- (ll)m*2);
    }
    else 
    {
         minn = 0;
    }
    cout<<minn<<" "<<maxn<<endl;
	return 0 ;
}