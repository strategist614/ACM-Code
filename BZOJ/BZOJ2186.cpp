#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 10000010;
int prime[MAXN];
int Prime[MAXN];
int num = 0;
ll t, mod;
ll n,m;
ll fact[MAXN], ans[MAXN];

void exgcd(ll a, ll b, ll &x, ll &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return;
    }   
    exgcd(b, a % b, y, x);
    y -= (a / b) * x;
}
ll inv(ll n)
{
    ll x, y; 
    exgcd(n, mod, x, y);
    return (x % mod + mod) % mod;
}

void make_prime()
{
    //memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = 1;
    fact[0] = fact[1] = 1;
    ans[0] = ans[1] = 1;
    for (int i = 2; i <= 10000000; i++)
    {
        fact[i] = fact[i - 1] * (ll)i % mod;  
        if (!prime[i])
        {
            Prime[++num] = i;
        }
        ans[i] = 1;
        for (int j = 1; j <= num && i * Prime[j] < 10000000; j++)
        {
            prime[i * Prime[j]] = 1;
            if (!(i % Prime[j]))
                break;
        }
    }
    for(int i = 2;i <= 10000000;i++)
    {
        if(!prime[i]) ans[i] = ans[i - 1] * (ll)(i - 1) % mod * inv(i) % mod;
        else ans[i] = ans[i - 1]; 
    } 
}

int main()
{
    //int t, mod;
    scanf("%lld %lld",&t,&mod);
    make_prime();
    //pre_work();
    while (t--)
    {
         scanf("%lld %lld",&n,&m);
         printf("%lld\n",ans[m] % mod * fact[n] % mod);  
    }
    return 0;
}