/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
int a[N];
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
    	tree[rt<<1].sum += tree[rt].add*(tree[rt<<1].r - tree[rt<<1].l+1);
    	tree[rt<<1|1].sum += tree[rt].add*(tree[rt<<1|1].r - tree[rt<<1|1].l +1);
    	tree[rt<<1].add += tree[rt].add;
    	tree[rt<<1|1].add += tree[rt].add;
    	tree[rt].add = 0 ;
    }
}

void build(int rt,int l,int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	if(l == r)
    {
    	tree[rt].sum = a[l];
    	return;
    }
    int mid = (l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
}

void update(int rt,int L,int R,int val)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if(L <= l && r <= R)
    {
        tree[rt].sum += (ll)val*(tree[rt].r-tree[rt].l+1);
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
	int mid = (l+r)>>1;
	pushdown(rt);
	ll ans = 0;
	if(L <= mid) ans += query(rt<<1,L,R);
	if(R > mid) ans += query(rt<<1|1,L,R);
	return ans;
}

int main ()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    for(int i = 1;i<=m;i++)
    {
    	int op;
    	scanf("%d",&op);
    	if(op == 1)
    	{
           int l,r,val;
           scanf("%d %d %d",&l,&r,&val);
           update(1,l,r,val);  
    	}
    	else 
    	{
           int l,r;
           scanf("%d %d",&l,&r);
           printf("%lld\n",query(1,l,r));
    	}
    }
	return 0 ;
}
*/
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
typedef long long ll;
const int N = 1e6+5;
ll a[N],c[2][N],sum[N];
int n,q;
ll ask(int k,int x)
{
    ll ans = 0;
    for(;x;x-=x&-x) ans += c[k][x];
    return ans;
}
void add(int k,int x,ll y)
{
    for(;x<=n;x += x&-x) c[k][x] += y;
}
int main ()
{
    scanf("%d %d",&n,&q);
    for(int i= 1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    while(q--)
    {
        ll op,l,r,d;
        scanf("%lld %lld %lld",&op,&l,&r);
        if(op == 1)
        {
           scanf("%lld",&d);
           add(0,l,d);
           add(0,r+1,-d);
           add(1,l,d*l);
           add(1,r+1,-d*(r+1));
        }
        else 
        {
            ll ans = sum[r]+(r+1)*ask(0,r)-ask(1,r);
            ans -= sum[l-1]+l*ask(0,l-1) - ask(1,l-1);
            printf("%lld\n",ans);
        }
    }
}
/*
5 10
2 6 6 1 1
2 1 4
1 2 5 10
2 1 3
2 2 3
1 2 2 8
1 2 3 7
1 4 4 10
2 1 2
1 4 5 6
2 3 4
*/