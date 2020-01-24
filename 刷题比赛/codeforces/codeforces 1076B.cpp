#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool notprime[100003];
ll prime[100003], cnt;
inline void getPrime() {
    prime[1] = 2; cnt = 1;
    for(int i = 3; i <= 1e6; i += 2) {
        if(notprime[i]) continue;
        prime[++cnt] = i;
        for(int j = 2; i * j < 1e6; ++j)
            notprime[i * j] = 1;
    }
}
inline ll fj(ll n)
{
	ll ans = 0;
	for(int i = 2;i <= cnt;i++)
	{
		if(n % prime[i] == 0) 
		{
			ans = prime[i];
			break;
		}
	}
	return ans;
}
const int S = 8;
ll mult_mod(ll a,ll b,ll c)
{
	a %= c;
	b %= c;
	ll ret = 0;
	ll tmp = a;
	while(b)
	{
		if(b & 1)
		{
			ret += tmp;
			if(ret > c) ret -= c;
		}
		tmp <<= 1;
		if(tmp > c) tmp -= c;
		b >>= 1;
	}
	return ret;
}
ll pow_mod(ll a,ll n,ll mod)
{
   ll ret = 1;
   ll temp = a % mod;
   while(n)
   {
   	if(n&1) ret = mult_mod(ret,temp,mod);
   	temp = mult_mod(temp,temp,mod);
   	n>>=1;
   } 
  return ret; 
}
bool check(ll a,ll n, ll x ,ll t)
{
	ll ret = pow_mod(a,x,n);
	ll last = ret;
	for(int i  =1;i<=t;i++)
	{
		ret = mult_mod(ret,ret,n);
		if(ret == 1 && last != 1&&last != n-1) return true;
		last = ret;
	}
	if(ret != 1) return true;
	else return false;
}
bool miller_rabin(ll n)
{
	if(n <2) return false;
	if(n == 2) return true;
	if((n&1) == 0) return false;
	ll x = n-1;
	ll t = 0 ;
	while((x&1) == 0){x >>= 1;t++;}
	srand(time(NULL));
	for(int i = 0;i<S;i++)
	{
		ll a = rand()%(n - 1)+1;
		if(check(a,n,x,t))
			return 	false;
	}
	return true;
}
int main ()
{
    ll n;
    cin>>n;
    getPrime();
    int ans = 0;
    if(miller_rabin(n))
    {
    	cout<<1<<endl;
    	return 0;
    }
    if(n % 2 == 0)
    {
    	cout<<n/2<<endl;
    	return 0;
    }
    else 
    {
    	ll ans = fj(n);
    	ll tmp = 0;
    	tmp++;
    	n -= ans;
    	tmp += n/2;
    	cout<<tmp<<endl;
    }
	return 0 ;
}