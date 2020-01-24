#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,d;
struct stree
{
	int l;
	int r;
	long long dat;
}tree[N<<2];
void pushup(int rt)
{
	tree[rt].dat = max(tree[rt<<1].dat,tree[rt<<1|1].dat);
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
void insert(int rt,int x,int val)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if(l == r) 
	{
		tree[rt].dat = val;
		return ;
	}
	int mid = (l+r)>>1;
	if(x <= mid) insert(rt<<1,x,val);
	else insert(rt<<1|1,x,val);
	pushup(rt);
}
long long query(int rt,int L,int R)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if(L <= l && r <= R) return tree[rt].dat;
    int mid = (l+r)>>1;
    long long maxn = 0;
    if(L <= mid) maxn = max(maxn,query(rt<<1,L,R));
    if(R > mid) maxn = max(maxn,query(rt<<1|1,L,R));
    return maxn;
}
int main ()
{
    scanf("%d %d",&n,&d);
    build(1,1,n);
    long long cnt = 0;
    int tmp = 0;
    while(n--)
    {
    	char op[20];
    	long long x;
    	scanf("%s %lld",op,&x);
    	if(op[0] == 'A')
    	{
    	   tmp++;
           x += cnt;
           x %= d;
           insert(1,tmp,x);
    	}
    	else 
    	{
           cnt = query(1,tmp-x+1,tmp);
           printf("%lld\n",cnt);          
     	}
    }
	return 0 ;
}