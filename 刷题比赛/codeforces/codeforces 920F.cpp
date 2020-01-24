#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 300010;
ll a[N];
int f(int x)
{
  int ans = 0;
  for(int i = 1;i<=sqrt(x);i++)
  {
    if(x % i == 0)
    {
      if(i != x/i)
      ans += 2;
      else ans++;
    }
  }
  return ans;
}

struct stree
{
  int l;
  int r;
  ll sum;
  int add;
}tree[N<<2];

void pushup(int rt)
{
  tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
  tree[rt].add = tree[rt<<1].add & tree[rt<<1|1].add;
}

void build(int l,int r,int rt)
{
  tree[rt].l = l;
  tree[rt].r = r;
  if(l == r)
  {
    tree[rt].sum = a[l];
    if(a[l] <= 2) tree[rt].add = 1;
    else tree[rt].add = 0;
    return;
  }
  int mid = (l+r)>>1;
  build(l,mid,rt<<1);
  build(mid+1,r,rt<<1|1);
  pushup(rt);
}

void update(int L,int R,int rt)
{
  if(tree[rt].add) return;
  int l = tree[rt].l,r = tree[rt].r;
  if(l == r)
  {
    tree[rt].sum = f(tree[rt].sum);
    if(tree[rt].sum <= 2) tree[rt].add = 1;
    return;
}
  int mid = (l + r)>>1;
  if(L <= mid) update(L,R,rt<<1);
  if(R > mid) update(L,R,rt<<1|1);
  pushup(rt);
}

ll query(int L,int R,int rt)
{
  int l = tree[rt].l, r = tree[rt].r;
  if(L <= l && r <= R) return tree[rt].sum;
  int mid = (l+r)>>1;
  ll ans = 0;
  if(L <= mid) ans += query(L,R,rt<<1);
  if(R > mid) ans += query(L,R,rt<<1|1);
  return ans ;
}

int n,m;
int main ()
{
  scanf("%d %d",&n,&m);
  for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
  build(1,n,1);
  while(m--){
    int op,l,r;
    scanf("%d %d %d",&op,&l,&r);
    if(op == 1)
    {
      update(l,r,1);
    }
    else
    {
      printf("%lld\n",query(l,r,1));
    }
  }
  return 0;
}
