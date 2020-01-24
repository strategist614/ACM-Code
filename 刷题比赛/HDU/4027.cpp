#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100010;
ll a[N];
int n,q;

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

void build(int rt,int l,int r)
{
  tree[rt].l = l;
  tree[rt].r = r;
  if(l == r)
  {
    tree[rt].sum = a[l];
    if(a[l] <= 1) tree[rt].add = 1;
    else tree[rt].add = 0;
    return;
  }
  int mid = (l+r)>>1;
  build(rt<<1,l,mid);
  build(rt<<1|1,mid+1,r);
  pushup(rt);
}

void update(int rt,int L,int R)
{
  if(tree[rt].add) return ;
  int l = tree[rt].l,r = tree[rt].r;
  if(l == r)
  {
    tree[rt].sum = (ll)sqrt(tree[rt].sum);
    if(tree[rt].sum <= 1) tree[rt].add = 1;
    return;
}
  int mid = (l + r)>>1;
  if(L <= mid) update(rt<<1,L,R);
  if(R > mid) update(rt<<1|1,L,R);
  pushup(rt);
}

ll query(int rt,int L,int R)
{
  int l = tree[rt].l, r = tree[rt].r;
  if(L <= l && r <= R) return tree[rt].sum;
  int mid = (l+r)>>1;
  ll ans = 0;
  if(L <= mid) ans += query(rt<<1,L,R);
  if(R > mid) ans += query(rt<<1|1,L,R);
  return ans ;
}

int main ()
{
  int flag = 0;
  while(~scanf("%d",&n))
  {
  for(int i = 1;i<=n;i++) scanf("%lld",&a[i]);
  build(1,1,n);
  scanf("%d",&q);
  printf("Case #%d:\n",++flag);
  while(q--)
  {
    int opt,x,y;
    scanf("%d %d %d",&opt,&x,&y);
    if(x > y) swap(x,y);
    if(opt == 0)
    {
      update(1,x,y) ;
    }
    else
    {
      printf("%lld\n",query(1,x,y));
    }
  }
  printf("\n");
}
  return 0 ;
}
