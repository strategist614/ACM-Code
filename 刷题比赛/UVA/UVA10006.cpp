/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[] = {561,1105,1729,2465,2821,6601,8911,10585,15841,29341,41041,46657,52633,62745,63973,75361};
int main ()
{
	int n;
	while(scanf("%d",&n) != EOF && n)
	{
	   int flag = 0;
       for(int i = 0;i < 16;i++)
       {
            if(n == a[i]) flag = 1;
       }
       if(flag) printf("The number %d is a Carmichael number.\n",n);
       else printf("%d is normal.\n",n); 
	}
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll mypow(ll x,ll n,ll mod)
{
	ll res = 1;
	while(n > 0)
	{
		if(n & 1) res = res*x%mod;
		x = x * x %mod;
		n >>= 1;
	}
	return res;
}
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
	   int flag = 0;
       if(miller_rabin(n)) 
       {
       	 printf("%d is normal.\n",n);
         continue;
       }
       for(int i = 1;i<=n-1;i++)
       {
       	   if(mypow(i,n,n) != i) {flag = 1;break;}
       }
       if(!flag) printf("The number %d is a Carmichael number.\n",n);
       else printf("%d is normal.\n",n);
	}
	return 0 ;
}