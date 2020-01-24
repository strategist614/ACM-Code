#include<iostream>
#include<cstdio>
#include<algorithm>
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
int a[N],n,m,cnt = 0,root[N],b[N],tot = 0;
struct ps_tree
{
   int l;
   int r;
   int dat;	
}tree[N*40];
int build(int l,int r)
{
	int pos = ++cnt;
	if(l == r)
	{
		tree[pos].dat = 0;
		return pos;
	}
	int mid = (l+r)>>1;
	tree[pos].l = build(l,mid);
	tree[pos].r = build(mid+1,r);
	return pos;
}

int update(int ed,int l,int r,int val)
{
	int pos = ++cnt;
	tree[pos] = tree[ed];
	if(l == r)
	{
		tree[pos].dat++;
		return pos;
	}
	int mid = (l+r)>>1;
	if(val <= mid) tree[pos].l = update(tree[ed].l,l,mid,val);
	else tree[pos].r = update(tree[ed].r,mid+1,r,val);
	tree[pos].dat = tree[tree[pos].l].dat + tree[tree[pos].r].dat;
	return pos;
}

int query(int p,int q,int l,int r,int k)
{
	if(l == r) return l;
	int mid = (l+r)>>1;
	int lcnt = tree[tree[p].l].dat-tree[tree[q].l].dat;
	if(k <= lcnt) return query(tree[p].l,tree[q].l,l,mid,k);
	else return query(tree[p].r,tree[q].r,mid+1,r,k-lcnt);
}

int main ()
{
	read(n);
	read(m);
	for(int i= 1;i<=n;i++) 
	{
		read(a[i]);
		b[++tot] = a[i];
	}
	sort(b+1,b+tot+1);
	tot = unique(b+1,b+tot+1)-(b+1);
	root[0] = build(1,tot);
	for(int i= 1;i<=n;i++)
	{
		int pos = lower_bound(b+1,b+tot+1,a[i])-b;
		root[i] = update(root[i-1],1,tot,pos);
	}
    for(int i= 1;i<=m;i++)
	{
		int l,r,k;
		read(l);
		read(r);
		read(k);
        int ans = b[query(root[r],root[l-1],1,tot,k)];
        out(ans);
        puts("");
	}
	return 0 ;
}