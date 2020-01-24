#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
vector<ll> G[100005];
vector<ll> E[100005];
bool vis[100005];
ll d[100005];
void dfs(ll u)
{
  vis[u] = 1;
  ll size = G[u].size();
  for(ll i = 0 ;i<size;i++)
  {
    ll v = G[u][i];
    if(!vis[v])
    {
      d[v] = d[u] + E[u][i];
      dfs(v);
    }
  }
}
int main()
{
  ll n;
  cin>>n;
  ll u,v,w;
  for(ll i =0;i<n-1;i++)
  {
    scanf("%lld %lld %lld",&u,&v,&w);
    G[u-1].push_back(v-1);
    E[u-1].push_back(w);
    G[v-1].push_back(u-1);
    E[v-1].push_back(w);
  }
  memset(vis,0,sizeof(vis));
  for(ll i= 0 ;i<n;i++)
   d[i] = (i == 0?0:INF);
  dfs(0);
  ll s = 0;
  ll max = -1;
  for(ll i = 0;i<n;i++)
  {
    if(d[i] > max && d[i] != INF)
    {
      max = d[i];
      s = i;
    }
  }
  memset(vis,0,sizeof(vis));
  for(ll i = 0;i<n;i++)
   d[i] = (i == s?0:INF);
  dfs(s);
  ll ans = -1;
  for(ll i =0;i<n;i++)
  {
    if(d[i] >ans &&d[i] != INF)
    {
      ans = d[i];
    }
  }
  ans = 10*ans+ ans*(ans+1)/2;
  cout<<ans<<endl;
  return 0;
}
