#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N = 100010;
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
    sum(rt<<1) = (ll)add(rt)*(r(rt<<1)-l(rt<<1) + 1);
    sum(rt<<1|1) = (ll)add(rt)*(r(rt<<1|1) - l(rt<<1|1) + 1);
    add(rt<<1) = add(rt);
    add(rt<<1|1) = add(rt);
    add(rt) = 0;
  }
}

void build(int l,int r,int rt)
{
  l(rt) = l;
  r(rt) = r;
  sum(rt) = 1;
  add(rt) = 0;
  if(l == r) return ;
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
    sum(rt) = (ll)val*(r-l+1);
    add(rt) = (ll)val;
    return ;
  }
  pushdown(rt);
  int mid = (l+r)>>1;
  if(L <= mid) update(L,R,rt<<1,val);
  if(R > mid) update(L,R,rt<<1|1,val);
  pushup(rt);
}

int t,n,q;
int main ()
{
  scanf("%d",&t);
  int flag = 0;
  while(t--)
{
  scanf("%d",&n);
  build(1,n,1);
  scanf("%d",&q);
  while(q--)
  {
    int l,r,d;
    scanf("%d %d %d",&l,&r,&d);
    update(l,r,1,d);
  }
  printf("Case %d: The total value of the hook is %lld.\n", ++flag, tree[1].sum);
 }
  return 0;
}
