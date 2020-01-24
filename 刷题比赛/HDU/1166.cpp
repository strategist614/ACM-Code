#include<iostream>
#include<cstdio>
using namespace std;
const int N = 5e5+5;
struct stree
{
  int l;
  int r;
  int sum;
}tree[N<<2];

int a[N];

void pushup(int rt)
{
	tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
}

void build(int l,int r,int rt)
{
	tree[rt].l = l;
	tree[rt].r = r;
	if(l == r)
	{
		tree[rt].sum = a[l];
		return ;
	}
	int mid = (l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	pushup(rt);
}

void change(int x,int val,int rt)
{ 
	int l = tree[rt].l;
	int r = tree[rt].r;
	if(l == r)
	{
		tree[rt].sum += val;
		return ;
	}
	int mid = (l+r)>>1;
    if(x <= mid) change(x,val,rt<<1);
    else change(x,val,rt<<1|1);
    pushup(rt); 
}

int query(int L,int R,int rt)
{
	int l = tree[rt].l,r = tree[rt].r;
	if(L <= l && r <= R) return tree[rt].sum;
	int mid = (l+r)>>1;
	int ans = 0 ;
	if(L <= mid) ans += query(L,R,rt<<1);
	if(R > mid) ans += query(L,R,rt<<1|1);
	return ans ;
}

int main ()
{
	int t;
	scanf("%d",&t);
	int flag = 0;
	while(t--)
	{
     int n;
     scanf("%d",&n);
     for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
     char s[20];
     build(1,n,1);
     printf("Case %d:\n",++flag);
     while(~scanf("%s",s))
     {
     	if(s[0] == 'E') break;
        if(s[0] == 'Q')
        {
           int l,r;
           scanf("%d %d",&l,&r);
           printf("%d\n",query(l,r,1));
        }
        else if(s[0] == 'A')
        {
           int x,val;
           scanf("%d %d",&x,&val);
           change(x,val,1);
        }
        else if(s[0] == 'S')
        {
           int x,val;
           scanf("%d %d",&x,&val);
           change(x,-val,1);
        }
     }  
   }
	return 0 ;
}