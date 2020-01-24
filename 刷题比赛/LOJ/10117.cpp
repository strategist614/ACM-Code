/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
struct stree
{
    int l;
    int r;
    int add;
    int sum;	
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
	tree[rt].add = 0;
	if(l == r)
	{
		tree[rt].sum = 0;
		return ;
	}
	int mid = (l+r)>>1;
	pushdown(rt);
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
        tree[rt].sum += val*(tree[rt].r-tree[rt].l+1);
        tree[rt].add += val;
        return ;
    }
    int mid = (l+r)>>1;
    pushdown(rt);
    if(L <= mid) update(rt<<1,L,R,val);
    if(R > mid) update(rt<<1|1,L,R,val);
    pushup(rt);   
}

int query(int rt,int x)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if(l == r) return tree[rt].sum;
	int ans = 0;
	int mid = (l+r)>>1;
	pushdown(rt);
	if(x <= mid) return query(rt<<1,x);
	else return query(rt<<1|1,x);
 }

int main ()
{
	int n,m;
    scanf("%d %d",&n,&m);
    memset(a,0,sizeof(a));
    build(1,1,n);
    for(int i = 1;i<=m;i++)
    {
       int op;
       scanf("%d",&op);
       if(op == 1)
       {
       	   int l,r;
       	   scanf("%d %d",&l,&r);
           update(1,l,r,1);    
       }
       else 
       {
          int x;
          scanf("%d",&x);
          int cnt = query(1,x);
          int ans = 0;
          if(cnt % 2 == 0) ans = 0;
          else ans = 1; 
          printf("%d\n",ans);
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
const int N = 1e5+5;
int c[N];
int a[N];
int n,q;
void add(int x,int y)
{
	for(;x <= N;x += x&-x) c[x] += y;
}
int ask(int x)
{
	int ans =0 ;
	for(;x;x-=x&-x) ans += c[x];
	return ans;
}
int main ()
{
    read(n);
    read(q);
    while(q--)
     {
     	int op;
     	read(op);
     	if(op == 1)
     	{
           int l,r;
           read(l);
           read(r);
           add(l,1);
           add(r+1,-1);
     	}
     	else 
     	{
     		int x;
     	   read(x);
           int cnt = ask(x);
           int ans = 0;
           if(cnt %2 == 0) ans = 0;
           else ans = 1;
           printf("%d\n",ans); 
     	}
     }
	return 0 ;
}