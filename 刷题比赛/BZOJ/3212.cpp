#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
ll a[N];
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

struct  stree
{
	int l;
	int r;
	ll sum;
	ll add;
}tree[N<<2];

void pushup(int rt)
{
	tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
}

void pushdown(int rt)
{
	if(tree[rt].add)
	{
		tree[rt<<1].sum += (ll)tree[rt].add * (tree[rt<<1].r - tree[rt<<1].l + 1);
		tree[rt<<1|1].sum += (ll)tree[rt].add * (tree[rt<<1|1].r - tree[rt<<1|1].l+1);
		tree[rt<<1].add += tree[rt].add;
		tree[rt<<1|1].add += tree[rt].add;
		tree[rt].add = 0;
	}
}

void build(int l,int r,int rt)
{
	tree[rt].l = l;
	tree[rt].r = r;
    if(l == r)
    {
       tree[rt].sum = a[l];
       tree[rt].add = 0;
       return ;
    }
    int mid = (l + r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(rt);
}

void update(int rt,int L,int R,int val)
{
   int l = tree[rt].l;
   int r = tree[rt].r;
   if(L <= l && r <= R)
   {
       tree[rt].sum += (ll)val*(tree[rt].r - tree[rt].l+1);
       tree[rt].add += val;
       return ;
   }
   int mid = (l+r)>>1;
   pushdown(rt);
   if(L <= mid) update(rt<<1,L,R,val);
   if(R > mid) update(rt<<1|1,L,R,val);
   pushup(rt);
}

ll query(int rt,int L,int R)
{
   int l = tree[rt].l;
   int r = tree[rt].r;
   if(L <= l && r <= R) return tree[rt].sum;
   pushdown(rt);
   int mid = (l + r)>>1;
   ll ans = 0;
   if(L <= mid) ans += query(rt<<1,L,R);
   if(R > mid) ans += query(rt<<1|1,L,R);
   return ans;
}

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
    build(1,n,1);
	for(int i = 1;i <= q;i++)
	{
       char op[20];
       scanf("%s",op);
       if(op[0] == 'Q')
       {
          int l,r;
          scanf("%d %d",&l,&r);
          printf("%lld\n",query(1,l,r));
       }
       else
       {
          int l,r,val;
          scanf("%d %d %d",&l,&r,&val);
          update(1,l,r,val);
       } 
	}	
	return 0 ;
}
/*
10 5
1 2 3 4 5 6 7 8 9 10
Q 4 4
Q 1 10
Q 2 4
C 3 6 3
Q 2 4
*/