#include<bits/stdc++.h>
using namespace std;
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
int gcd(int a,int b)
{
  return b?gcd(b,a%b):a;
}
const int N = 5e5+5;
int ans,n,m,a[N],x;
struct segment_tree
{
  int l;
  int r;
  int dat;
}tree[N<<2];

void pushup(int rt)
{
  tree[rt].dat = gcd(tree[rt<<1].dat,tree[rt<<1|1].dat);
}

void build(int rt,int l,int r)
{
    tree[rt].l = l;
    tree[rt].r = r;
    if(l == r)
    {
      tree[rt].dat = a[l];
      return ;
    }
    int mid = (l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
}

void update(int rt,int x,int val)
{
   int l = tree[rt].l;
   int r = tree[rt].r;
   if(l == r) {tree[rt].dat = val;return;}
   int mid = (l+r)>>1;
   if(x <= mid) update(rt<<1,x,val);
   else update(rt<<1|1,x,val);
   pushup(rt);
}

void query(int rt,int L,int R)
{
  int l = tree[rt].l;
  int r = tree[rt].r;
  if(ans > 1) return ;
  if(l == r) {ans++;return;}
  int mid = (l+r)>>1;
  if(L <= mid && tree[rt<<1].dat % x != 0) query(rt<<1,L,R);
  if(R > mid && tree[rt<<1|1].dat % x != 0) query(rt<<1|1,L,R); 
}

int main ()
{
  cin>>n;
  for(int i =1;i<=n;i++) read(a[i]);
  build(1,1,n);
  cin>>m;
  while(m--)
  {
    int op;
    read(op);
    if(op == 1)
    {
      ans = 0;
      int l,r;
      read(l);
      read(r);
      read(x);
      query(1,l,r);
      if(ans <= 1) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
    else 
    {
      int l,r;
      read(l);
      read(r);
      update(1,l,r);
    }
  }
  return 0 ;
}