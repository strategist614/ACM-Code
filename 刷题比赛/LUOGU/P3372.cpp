#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int a[N];
struct stree
{
   int l;
   int r;
   ll sum;
   int add;	
}tree[N<<2];
void pushup(int rt)
{
   tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
}
void pushdown(int rt)
{
	if(tree[rt].add)
	{
		tree[rt<<1].sum += tree[rt].add*(tree[rt<<1].r-tree[rt<<1].l+1);
		tree[rt<<1|1].sum += tree[rt].add*(tree[rt<<1|1].r-tree[rt<<1|1].l+1);
		tree[rt<<1].add += tree[rt].add;
		tree[rt<<1|1].add += tree[rt].add;
		tree[rt].add = 0; 
	}
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
void update(int rt,int L,int R,int val)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if(L <= l && r <= R)
	{
		tree[rt].sum += (ll)val*(r-l+1);
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
	int mid = (l+r)>>1;
	ll ans = 0;
	if(L <= mid) ans += query(rt<<1,L,R);
	if(R > mid) ans += query(rt<<1|1,L,R);
	return ans ;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i =1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while(m--)
    {
       int opt;
       cin>>opt;
       if(opt == 1)
       {
         int x,y,k;
         cin>>x>>y>>k;
         update(1,x,y,k);  
       }
       else  
       {
         int x,y;
         cin>>x>>y;
         cout<<query(1,x,y)<<endl;
       }
    }
	return 0 ;
}