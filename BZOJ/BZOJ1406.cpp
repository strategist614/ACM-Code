#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
set<ll> s,ans;
int main()
{
    ll n;
    cin >> n;
    if(!n)
    {
        puts("None");
        return 0;
    }
    for(int i =1;i <= sqrt(n);i++)
    {
        if(n % i == 0)
        {
            ll a = i;
            ll b = n / i;
            ll x;
            for(ll k = 0;(x = b * k + 1) < n;k++)
              if((x + 1) % a == 0)
               s.insert((x));
            for(ll k = 1;(x = b * k - 1) < n;k++)
              if((x - 1) % a == 0)
               s.insert(x);
        }
    }    
    for(set<ll>::iterator it = s.begin();it != s.end();it++)
      cout << *it << endl;
    return 0;
}