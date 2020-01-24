/*#include<iostream>
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
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
template <typename T>
void read(T &x)
{
  x = 0;
  char c = getchar();
  int sgn = 1;
  while(c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
  while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
  x*=sgn;
}
template <typename T>
void out(T x)
{
  if(x<0){putchar('-');x=-x;}
  if(x>=10)out(x/10);
  putchar(x%10+'0');
}
const int N = 1e5+5;
int n,m,t;
ll L[N],R[N],pos[N],sum[N],a[N],add[N];
void update(int l,int r,ll d)
{
   int p = pos[l];
   int q = pos[r];
   if(p == q)
   {
      for(int i= l;i<=r;i++) a[i] += d;
      sum[p] += d*(r-l+1);
   }
   else
   {
     for(int i = p + 1;i <= q-1;i++) add[i] += d;
     for(int i = l;i<=R[p];i++) a[i] += d;
     sum[p] += d*(R[p]-l+1);
     for(int i = L[q];i<=r;i++) a[i] += d;
     sum[q] += d*(r-L[q]+1);
   }
}
ll ask(int l,int r)
{
  int p = pos[l];
  int q = pos[r];
  ll ans = 0;
  if(p == q)
  {
    for(int i = l;i <= r;i++) ans += a[i];
    ans += add[p]*(r-l+1);
  }
  else 
  {
    for(int i = p+1;i<=q-1;i++)
    ans += sum[i]+add[i]*(R[i]-L[i]+1);
    for(int i = l;i<=R[p];i++) ans += a[i];
    ans += add[p]*(R[p]-l+1);
    for(int i = L[q];i<=r;i++) ans += a[i];
    ans += add[q]*(r-L[q]+1);
  }
  return ans;
}
int main ()
{
  read(n);
  read(m);
  for(int i = 1;i<=n;i++) read(a[i]);
  t = sqrt(n);
  for(int i = 1;i<=t;i++)
  {
    L[i] = (i-1)*sqrt(n)+1;
    R[i] = i*sqrt(n);
  }
  if(R[t] < n) t++,L[t] = R[t-1]+1,R[t] = n;
  for(int i = 1;i<=t;i++)
    for(int j = L[i];j<=R[i];j++)
    {
       pos[j] = i;
       sum[i] += a[j];
    }
  while(m--)
  {
    char op[3];
    int l,r,d;
    scanf("%s",op);
    read(l);
    read(r);
    if(op[0] == 'C')
    {
      read(d);
      update(l,r,d);
    }
    else printf("%lld\n",ask(l,r));
  }
  return 0 ;
}