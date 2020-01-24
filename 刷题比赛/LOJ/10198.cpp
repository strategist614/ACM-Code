/*
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
vector<ll> ans; 
vector<pair<ll,ll>> v;
int main ()
{
    ll n;
    cin>>n;
    for(int i = 2;i<=sqrt(n);i++)  {
    	if(n%i == 0){
    	v.push_back(make_pair(i,n/i));
    }
}   
    for(int i = 0;i<v.size();i++)
    {
    	ll x = v[i].first;
    	ll y = v[i].second;
    	if(miller_rabin(x) && miller_rabin(y)) 
    	{
    		ans.push_back(x);
    		ans.push_back(y);
    	}
    }
    sort(ans.begin(),ans.end());
    ll x = ans[ans.size()-1];
    cout<<x<<endl;
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
std::vector<ll> v;
int main ()
{
	ll n;
	cin>>n;
    for(int i = 2;i<=sqrt(n);i++)
    {
    	if(n%i == 0)
    	{
    		v.push_back(i);
    		v.push_back(n/i);
    	}
    }
    sort(v.begin(),v.end());
    ll x = v[v.size()-1];
    cout<<x<<endl;
	return 0 ;
}
