#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
typedef long long ll;
ll n,m,a[N],p;
struct  segment_tree
{
	int l;
	int r;
	ll add;
	ll mul;
	ll sum;
}tree[N<<2];

 void pushup(int rt)
    {
        tree[rt].sum = (tree[rt<<1].sum + tree[rt<<1|1].sum)%p;
    }

void pushdown(int rt)
{
    tree[rt<<1].sum = (tree[rt<<1].sum*tree[rt].mul+tree[rt].add*(tree[rt<<1].r-tree[rt<<1].l+1))%p;
    tree[rt<<1|1].sum = (tree[rt<<1|1].sum*tree[rt].mul+tree[rt].add*(tree[rt<<1|1].r-tree[rt<<1|1].l+1))%p;
    tree[rt<<1].mul = (tree[rt<<1].mul*tree[rt].mul)%p;
    tree[rt<<1|1].mul = (tree[rt<<1|1].mul*tree[rt].mul)%p;
    tree[rt<<1].add = (tree[rt<<1].add*tree[rt].mul+tree[rt].add)%p;
    tree[rt<<1|1].add = (tree[rt<<1|1].add*tree[rt].mul+tree[rt].add)%p;
    tree[rt].add = 0;
    tree[rt].mul = 1;
}
void build(int rt,int l,int r)
    {
        tree[rt].l = l;
        tree[rt].r = r;
        tree[rt].add = 0;
        tree[rt].mul = 1;
        if(l == r)
        {
            tree[rt].sum = a[l]%p;
            return ;
        }
        int mid = (l+r)>>1;
        build(rt<<1,l,mid);
        build(rt<<1|1,mid+1,r);
        pushup(rt);
    }

void updateadd(int rt,int L,int R,int val)
    {
        int l = tree[rt].l;
        int r = tree[rt].r;
        if(L <= l && r <= R)
        {
           tree[rt].sum += (val*(tree[rt].r - tree[rt].l+1)%p)%p;
           tree[rt].sum %= p;
           tree[rt].add += val;
           tree[rt].add %= p;
           return ;
        }
        int mid = (l+r)>>1;
        pushdown(rt);
        if(L <= mid) updateadd(rt<<1,L,R,val);
        if(R > mid) updateadd(rt<<1|1,L,R,val);
        pushup(rt);
    }

void updatemul(int rt,int L,int R,int val)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if(L <= l && r <= R)
	{
		    tree[rt].sum *= val;
            tree[rt].sum %= p;
            tree[rt].mul *= val;
            tree[rt].mul %= p;
            tree[rt].add *= val;
            tree[rt].add %= p;
		return ;
	}
	int mid = (l+r)>>1;
	pushdown(rt);
	if(L <= mid) updatemul(rt<<1,L,R,val);
	if(R > mid) updatemul(rt<<1|1,L,R,val);
	pushup(rt);
}

ll query(int rt,int L,int R)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if(L <= l && r <= R)
	{
		return tree[rt].sum%p;
	}
	int mid = (l+r)>>1;
    pushdown(rt);
	ll ans = 0;
	if(L <= mid)
		{ans += query(rt<<1,L,R);ans %= p;}
    if(R > mid)
    	{ans += query(rt<<1|1,L,R);ans %= p;}
    return ans % p;
    pushup(rt);
}


int main ()
{
    cin>>n>>m>>p;
    for(int i =1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while(m--)
    {
        int op;
        cin>>op;
        if(op == 1)
        {
           int x,y,k;
           cin>>x>>y>>k;
           updatemul(1,x,y,k);
        }
        else if(op == 2)
        {
           int x,y,k;
           cin>>x>>y>>k;
           updateadd(1,x,y,k);
        }
        else 
        {
            int x,y;
            cin>>x>>y;
            cout<<query(1,x,y)%p<<endl;
        }
    } 
	return 0 ;
}