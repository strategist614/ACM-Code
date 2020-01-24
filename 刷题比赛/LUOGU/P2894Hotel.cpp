#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
struct s_tree
{
	int l;
	int r;
	int len;
	int lmax;
	int rmax;
	int sum;
	int add;
}tree[N<<2];

void pushup(int rt)
{
     if(tree[rt<<1].len == tree[rt<<1].sum)
        tree[rt].lmax = tree[rt<<1].len + tree[rt<<1|1].lmax;
     else tree[rt].lmax = tree[rt<<1].lmax;
     if(tree[rt<<1|1].len == tree[rt<<1|1].sum)
        tree[rt].rmax = tree[rt<<1|1].len+tree[rt<<1].rmax;
     else tree[rt].rmax = tree[rt<<1|1].rmax;
     tree[rt].sum = max(max(tree[rt<<1].sum,tree[rt<<1|1].sum),tree[rt<<1].rmax+tree[rt<<1|1].lmax);
}

void pushdown(int rt)
{
   if(tree[rt].add == 0) return ;
   if(tree[rt].add == 1)
   {
   	   tree[rt<<1].add = 1;
   	   tree[rt<<1|1].add = 1;
   	   tree[rt<<1].lmax = tree[rt<<1].rmax = tree[rt<<1].sum = 0;
   	   tree[rt<<1|1].lmax = tree[rt<<1|1].rmax = tree[rt<<1|1].sum = 0;
   	   tree[rt].add = 0;
   }    
   if(tree[rt].add == 2)
   {
   	  tree[rt<<1].add = 2;
   	  tree[rt<<1|1].add = 2;
   	  tree[rt<<1].lmax = tree[rt<<1].rmax = tree[rt<<1].sum = tree[rt<<1].len;
      tree[rt<<1|1].lmax = tree[rt<<1|1].rmax = tree[rt<<1|1].sum = tree[rt<<1|1].len;	  
      tree[rt].add = 0 ;
   }
}

void build(int rt,int l,int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	tree[rt].lmax = tree[rt].rmax = tree[rt].len = tree[rt].sum = r-l+1;
	if(l == r) return ;
	int mid = (l+r)>>1;
	pushdown(rt);
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}

void update(int rt,int tag,int L,int R)
{
   int l = tree[rt].l;
   int r = tree[rt].r;
   pushdown(rt);
   if(L <= l && r <= R)
   {
    if(tag == 1)
   	 tree[rt].sum = tree[rt].lmax = tree[rt].rmax = 0;
    else tree[rt].sum = tree[rt].lmax = tree[rt].rmax = tree[rt].len;
    tree[rt].add = tag;
    return ;
   }
   int mid = (l+r)>>1;
   if(L <= mid) update(rt<<1,tag,L,R);
   if(R > mid) update(rt<<1|1,tag,L,R);
   pushup(rt);
}

int query(int rt,int l,int r,int len)
{
	pushdown(rt);
    if(l == r)  return l;
    int mid = (l+r)>>1;
    if(tree[rt<<1].sum >= len) return query(rt<<1,l,mid,len);
    else if(tree[rt<<1].rmax + tree[rt<<1|1].lmax >= len) return mid-tree[rt<<1].rmax+1;
    else  return query(rt<<1|1,mid+1,r,len);
}

int main ()
{
    int n,m;
    cin>>n>>m;
    build(1,1,n);
    for(int i =1;i<=m;i++)
    {
    	int op;
    	cin>>op;
    	if(op == 1)
    	{
    		int x;
    		cin>>x;
            if(tree[1].sum >= x)
            {
            	int ans = query(1,1,n,x);
            	cout<<ans<<endl;
            	update(1,1,ans,ans+x-1);
            }
            else cout<<0<<endl;
    	}
    	else  
    	{ 
            int l,r;
            cin>>l>>r;
            update(1,2,l,l+r-1);
    	}
    }
	return 0 ;
}