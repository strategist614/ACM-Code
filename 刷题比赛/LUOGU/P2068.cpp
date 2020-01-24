#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
struct stree
{
	int l;
	int r;
	int dat;
}tree[N<<2];
void pushup(int rt)
{
	tree[rt].dat = tree[rt<<1].dat + tree[rt<<1|1].dat;
}
void build(int rt,int l,int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	if(l == r)
	{
		tree[rt].dat = 0;
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
	if(l == r) {tree[rt].dat += val;return;}
	int mid = (l+r)>>1;
	if(x <= mid) update(rt<<1,x,val);
	else update(rt<<1|1,x,val);
	pushup(rt);
}
ll query(int rt,int L,int R)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if(L <= l && r <= R) return tree[rt].dat;
	int mid = (l+r)>>1;
	ll ans = 0;
	if(L <= mid) ans += query(rt<<1,L,R);
	if(R > mid) ans += query(rt<<1|1,L,R);
	return ans; 
}
int main ()
{
    int n,w;
    scanf("%d %d",&n,&w);
    build(1,1,n);
    while(w--)
    {
       int a,b;
       char op[20];
       scanf("%s",op);
       scanf("%d %d",&a,&b);	
       if(op[0] == 'x')
       {
           update(1,a,b);
       } 
       else	
       {
          printf("%lld\n",query(1,a,b));
       }
    }
	return 0 ;
}