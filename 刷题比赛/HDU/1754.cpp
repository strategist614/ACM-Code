#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
struct  stree
{
   int l;
   int r;
   int dat;
}tree[N<<2];

int a[N];

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
	tree[rt].dat = max(tree[rt<<1].dat,tree[rt<<1|1].dat);
}

void update(int rt,int x,int val)
{
    if(tree[rt].l == tree[rt].r)
    {
    	tree[rt].dat = val;
    	return ; 
    }
    int mid = (tree[rt].l + tree[rt].r)>>1;
    if(x <= mid) update(rt<<1,x,val);
    else update(rt<<1|1,x,val); 
    tree[rt].dat = max(tree[rt<<1].dat,tree[rt<<1|1].dat);
}

int query(int rt,int L,int R)
{
	if(L <= tree[rt].l && tree[rt].r <= R) return tree[rt].dat;
	int mid = (tree[rt].l + tree[rt].r)>>1;
	int ans = -(1<<30);
	if(L <= mid) ans = max(ans,query(rt<<1,L,R));
	if(R > mid) ans = max(ans,query(rt<<1|1,L,R));
	return ans ; 
}

int n,m;
int main ()
{
    while(~scanf("%d %d",&n,&m))
    {
     for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
     build(1,1,n);
     for(int i = 1;i <= m;i++)
     {
    	char op[20];
    	scanf("%s",op);
    	if(op[0] == 'Q')
    	{
           int l,r;
           scanf("%d %d",&l,&r);
           printf("%d\n",query(1,l,r)); 
    	}
    	else 
    	{
    	   int x,val;
    	   scanf("%d %d",&x,&val);
           update(1,x,val);
    	}
    }
}
	return 0 ;
}