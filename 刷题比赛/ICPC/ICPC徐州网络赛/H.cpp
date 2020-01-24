#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100010;
ll a[N];
ll t1[N<<2],t2[N<<2];
int n,m;

void pushup(int rt,ll t[])
{
  t[rt] = t[rt<<1] + t[rt<<1|1];
}

void build1(int l,int r,int rt,ll t[])
{
  if(l == r)
  {
    t[rt] = a[l];
    return ;
  }
  int mid = (l+r)>>1;
  build1(l,mid,rt<<1,t);
  build1(mid+1,r,rt<<1|1,t);
  pushup(rt,t);
}

void build2(int l,int r,int rt,ll t[])
{
  if(l == r)
  {
    t[rt] = l * a[l];
    return ;
  }
  int mid = (l+r)>>1;
  build2(l,mid,rt<<1,t);
  build2(mid+1,r,rt<<1|1,t);
  pushup(rt,t);
}

void update1(int l,int r,int rt,int x,ll val,ll t[])
{
  if(l == r)
  {
    t[rt] = val;
    return ;
  }
  int mid = (l+r)>>1;
  if(x <= mid) update1(l,mid,rt<<1,x,val,t);
  else update1(mid+1,r,rt<<1|1,x,val,t);
  pushup(rt,t);
}

void update2(int l,int r,int rt,int x,ll val,ll t[])
{
   if(l == r)
   {
     t[rt] = val * l;
     return ;
   }
   int mid = (l+r)>>1;
   if(x <= mid) update2(l,mid,rt<<1,x,val,t);
   else update2(mid+1,r,rt<<1|1,x,val,t);
   pushup(rt,t);
}

ll query(int l,int r,int rt,int L,int R,ll t[])
{
  if(L <= l && r <= R) return t[rt];
  int mid = (l+r)>>1;
  ll ans = 0;
  if(L <= mid) ans += query(l,mid,rt<<1,L,R,t);
  if(R > mid) ans += query(mid+1,r,rt<<1|1,L,R,t);
  return ans;
}

int main ()
{
  scanf("%d %d",&n,&m);
  for(int i = 1;i <= n;i++)
    scanf("%lld",&a[i]);
  build1(1,n,1,t1);
  build2(1,n,1,t2);
  while(m--)
  {
    int op;
    ll x,y;
    scanf("%d %lld %lld",&op,&x,&y);
    if(op == 1)
    {
      ll ans = (y+1)*query(1,n,1,x,y,t1)-query(1,n,1,x,y,t2);
      printf("%lld\n",ans);
    }
    else
    {
      update1(1,n,1,x,y,t1);
      update2(1,n,1,x,y,t2);
    }
  }
  return 0;
}
