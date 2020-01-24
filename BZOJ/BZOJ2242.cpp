#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll power(ll a,ll b,ll mod)
{
    ll ans = 1 % mod;
    while(b)
    {
        if(b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans % mod;
}
ll baby_step_giant_step(ll a, ll b, ll p) {
	map<ll, ll> hash;
	hash.clear();
    b %= p;
    ll t = (ll)sqrt(p) + 1;
    for (int j = 0; j < t; j++) {
    	ll val = (long long)b * power(a, j, p) % p; // b*a^j
		hash[val] = j;
	}
    a = power(a, t, p); // a^t
    if (a == 0) return b == 0 ? 1 : -1;
    for (ll i = 0; i <= t; i++) {
    	ll val = power(a, i, p); // (a^t)^i
        ll j = hash.find(val) == hash.end() ? -1 : hash[val];
        if (j >= 0 && i * t - j >= 0) return i * t - j;
    }
    return -1;
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1, y = 0; return a; }
    ll d = exgcd(b, a%b, x, y);
    ll z = x; x = y; y = z - y * (a / b);
    return d;
}


int main ()
{
    int t,k;
    scanf("%d %d",&t,&k);
    if(k == 1)
    {
      while(t--)
      {
          ll y,z,p;
          scanf("%lld %lld %lld",&y,&z,&p);
          printf("%lld\n",power(y,z,p));
      }
    }
    else if(k == 2)
    {
      while(t--)
      {
          ll x,y;
          ll a,b,p;
          scanf("%lld %lld %lld",&a,&b,&p);
          ll gcd = exgcd(a,p,x,y);
          if(b % gcd != 0) {printf("Orz, I cannot find x!\n");continue;}
          x = x * b / gcd;
          ll mod = p / gcd;
          printf("%lld\n",(x % p + p) % p); 
      }   
    }
    else 
    {
       while(t--)
       {
           ll a,b,p;
           scanf("%lld %lld %lld",&a,&b,&p);
           ll ans = baby_step_giant_step(a,b,p);
           if(ans == -1)
           {
               printf("Orz, I cannot find x!\n");
           }
           else printf("%lld\n",ans);
       }
    }
    return 0;
}