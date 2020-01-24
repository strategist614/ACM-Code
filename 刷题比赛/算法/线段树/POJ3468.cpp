#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N = 100010;
ll a[N];
struct stree
{
  int l;
  int r;
  ll sum,add;
  #define sum(x) tree[x].sum
  #define add(x) tree[x].add
  #define l(x) tree[x].l
  #define r(x) tree[x].r
}tree[N<<2];

void pushup(int rt)
{
  sum(rt) = sum(rt<<1) + sum (rt<<1|1);
}

void pushdown(int rt)
{
  if(add(rt))
  {
    sum(rt<<1) += (ll)add(rt)*(r(rt<<1)-l(rt<<1) + 1);
    sum(rt<<1|1) += (ll)add(rt)*(r(rt<<1|1) - l(rt<<1|1) + 1);
    add(rt<<1) += add(rt);
    add(rt<<1|1) += add(rt);
    add(rt) = 0;
  }
}

void build(int l,int r,int rt)
{
  l(rt) = l;
  r(rt) = r;
  add(rt) = 0;
  if(l == r)
  {
    sum(rt) = a[l];
    return ;
  }
  int mid = (l+r)>>1;
  build(l,mid,rt<<1);
  build(mid+1,r,rt<<1|1);
  pushup(rt);
}

void update(int L,int R,int rt,int val)
{
  int l = l(rt),r = r(rt);
  if(L <= l && r <= R)
  {
    sum(rt) += val*(r-l+1);
    add(rt) += val;
    return ;
  }
  pushdown(rt);
  int mid = (l+r)>>1;
  if(L <= mid) update(L,R,rt<<1,val);
  if(R > mid) update(L,R,rt<<1|1,val);
  pushup(rt);
}

ll query(int L,int R,int rt)
{
  int l = l(rt),r = r(rt);
  if(L <= l && r <= R) return sum(rt);
  pushdown(rt);
  int mid = (l + r) >> 1;
  ll ans = 0;
  if(L <= mid) ans += query(L,R,rt<<1);
  if(R > mid) ans += query(L,R,rt<<1|1);
  return ans ;
}
int t,n,q;
char op[20];
int main ()
{
  scanf("%d %d",&n,&q);
  for(int i = 1;i<=n;i++) scanf("%lld",&a[i]);
  build(1,n,1);
  while(q--)
  {
    scanf("%s",op);
    if(op[0] == 'Q')
    {
      int a,b;
      scanf("%d %d",&a,&b);
      printf("%lld\n",query(a,b,1));
    }
    else
    {
      int a,b,c;
      scanf("%d %d %d",&a,&b,&c);
      update(a,b,1,c);
    }
  }
  return 0;
}
