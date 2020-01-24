// 有正确思路，但是实现是看题解的
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
ll a[N],b[N],fa[N],vis[N],sum[N];
int find(int x)
{
  if(x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}
void merge(int x,int y)
{
  int fx = find(x);
  int fy = find(y);
  if(fx != fy)
  {
    fa[fx] = fy;
    sum[fy] += sum[fx];
  }
}
std::vector<ll> v;
int main ()
{
  int n;
  cin>>n;
  for(int i= 1;i<=n;i++) cin>>a[i];
  for(int i= 1;i<=n;i++) cin>>b[i];
  for(int i= 1;i<=n;i++) {fa[i] = i;vis[i] = 0;}
  ll ans = 0;
  for(int i = n;i>=1;i--)
  {
    int tmp = b[i];
    sum[tmp] = a[tmp];
    vis[tmp] = 1;
    v.push_back(ans);
    if(tmp != 1&&vis[tmp-1]) merge(tmp,tmp-1);
    if(tmp != n&&vis[tmp+1]) merge(tmp,tmp+1);
    ans = max(ans,sum[find(tmp)]);
  } 
  for(int i= v.size()-1;i>=0;i--)
    cout<<v[i]<<endl;
  return 0 ;
}