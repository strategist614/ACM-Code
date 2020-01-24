#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
ll a[N];
struct stree
{
   int l;
   int r;
   ll sum;	
}tree[N<<2];

void pushup(int rt)
{
	tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
}

void build(int rt,int l,int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	if(l == r)
	{
		tree[rt].sum = a[l];
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
	if(l == r)
	{
		tree[rt].sum += val;
		return ;
	}
	int mid = (l+r)>>1;
	if(x <= mid) update(rt<<1,x,val);
	else update(rt<<1|1,x,val);
	pushup(rt);
}

ll query(int rt,int L,int R)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if(L <= l && r <= R) return tree[rt].sum;
	int mid = (l+r)>>1;
	ll ans = 0;
	if(L <= mid) ans += query(rt<<1,L,R);
	if(R > mid) ans += query(rt<<1|1,L,R);
	return ans;
}

int main ()
{
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i  =1;i<=n;i++) scanf("%lld",&a[i]);
    build(1,1,n);
    while(q--)
    {
    	int op,l,r;
    	scanf("%d %d %d",&op,&l,&r);
    	if(op == 1)
    	{
          update(1,l,r);
    	}
    	else 
    	{
           printf("%lld\n", query(1,l,r));
    	}
    }
	return 0 ;
}