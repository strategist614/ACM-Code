#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
typedef long long ll;
ll a[N];
struct stree
{
   int l;
   int r;
   ll add;
   ll sum;	
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
		if(a[l] <= 1) tree[rt].add = 1;
		else tree[rt].add = 0;
		tree[rt].sum = a[l];
		return ;
	}
	int mid = (l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
}

void update(int rt,int L,int R)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if(tree[rt].add) return;
	if(l == r)
	{
		tree[rt].sum = (ll)sqrt(tree[rt].sum);
		if(tree[rt].sum <= 1) tree[rt].add = 1;
		return ;
	}
	int mid = (l+r)>>1;
	if(L <= mid) update(rt<<1,L,R);
	if(R > mid) update(rt<<1|1,L,R);
	pushup(rt);
 }

ll query(int rt,int L,int R)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if(L <= l && r <= R)  return tree[rt].sum;
	int mid = (l+r)>>1;
	ll ans = 0;
	if(L <= mid) ans += query(rt<<1,L,R);
	if(R > mid) ans += query(rt<<1|1,L,R);
	return ans; 
}

int main ()
{
    int n;
    scanf("%d",&n);
    for(int i =1;i<=n;i++) scanf("%lld",&a[i]);
    int m;
    build(1,1,n);
    scanf("%d",&m);
    for(int i = 1;i<=m;i++)
    {
    	int op,l,r;
    	scanf("%d %d %d",&op,&l,&r);
    	if(op == 1)
    	{
            printf("%lld\n",query(1,l,r));
    	}
    	else 
    	{
    		update(1,l,r);
    	}
    }
	return 0 ;	
}