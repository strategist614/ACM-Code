#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<ll> p;
priority_queue<ll> q;

int main ()
{
  ll n;
  cin>>n;
  for(ll i= 1;i<=n;i++)
  {
    p.push(0);
    q.push(0);
  }
  for(ll i= 1;i<=n;i++)
  {
    ll a;
    cin>>a;
    p.push(a);
  }
  for(ll i =1;i<=n;i++)
  {
    ll b;
    cin>>b;
    q.push(b);
  }
  ll ansa = 0;
  ll ansb = 0;
  for(ll i = 1;i<=n;i++)
  {
    ll x = p.top();
    ll y = q.top();
    if(x >= y)
    {
      ansa += x;
      p.pop();
    }
    else q.pop();
    ll s = p.top();
    ll d = q.top();
    if(d >= s)
    {
      ansb += d;
      q.pop();
    }
    else p.pop();
  }
  cout<<ansa - ansb<<endl;
  return 0;
}
