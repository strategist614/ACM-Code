#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b) { return b ?gcd(b,a%b):a;}
int main ()
{
	int x,y;
	cin>>x>>y;
    ll tmp = x*y;
    int ans = 0;
    for(int i = 1;i<=sqrt(tmp);i++)
    {
    	if(tmp % i == 0)
    	{
          ll _ = tmp/i;
          if(gcd(_,i) == x && (ll)_ * i/gcd(_,i) == y) ans++;
    	}
    }
    cout<<ans*2<<endl;
	return 0 ;
}