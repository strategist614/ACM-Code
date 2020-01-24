/*
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
const int N = 5e5+5;
int a[N];
int b[N];
long long cnt = 0;
void merge(int l, int mid, int r) {
	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++)
		if (j > r || i <= mid && a[i] < a[j]) b[k] = a[i++];
		else b[k] = a[j++],cnt += mid - i + 1;
	for (int k = l; k <= r; k++) a[k] = b[k];
}
void mergesort(int l,int r)
{
	if(l < r)
	{
		int mid = (l+r)>>1;
		mergesort(l,mid);
		mergesort(mid+1,r);
		merge(l,mid,r);
	}
}
int main ()
{
    int n;
    read(n);
    for(int i = 1;i<=n;i++) read(a[i]);
    mergesort(1,n);
    out(cnt);
    puts("");
    //for(int i = 1;i<=n;i++) cout<<a[i]<<" ";
	return 0 ;
}
*/
/*
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
const int N = 5e5+5;
struct s_tree 
{
   int l;
   int r;
   long long dat;
}tree[N<<2];
void pushup(int rt)
{
	tree[rt].dat = tree[rt<<1].dat + tree[rt<<1|1].dat ;
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

void update(int rt,int x)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if(l == r)
	{
		tree[rt].dat++;
		return ;
	}
	int mid = (l+r)>>1;
	if(x <= mid) update(rt<<1,x);
	else update(rt<<1|1,x);
	pushup(rt);
}

long long query(int rt,int L,int R)
{
   int l = tree[rt].l;
   int r = tree[rt].r;
   if(L <= l && r <= R) return tree[rt].dat ;
   int mid = (l+r)>>1;
   long long ans = 0 ;
   if(L <= mid)  ans += query(rt<<1,L,R);
   if(R > mid) ans += query(rt<<1|1,L,R);
   return ans ;
}
int n;
int a[N],b[N],c[N];
int main ()
{
    cin>>n;
    for(int i= 1;i <= n;i++) read(a[i]),b[i] = a[i];
    sort(b+1,b+n+1);
    int m = unique(b+1,b+n+1)-(b+1);
    for(int i = 1;i <= n;i++)
    {
    	int pos = lower_bound(b+1,b+m+1,a[i])-b;
    	c[i] = pos;
    } 
    long long ans = 0;
    build(1,1,N);
    for(int i = 1;i<=n;i++)
    {
        ans += query(1,c[i]+1,N);
        update(1,c[i]);
    }
    cout<<ans<<endl;
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
const int N = 7e6+5;
struct s_tree
{
	int lc;
	int rc;
	int dat;
}tree[N];
int root,tot;

int build()
{
	tot++;
	tree[tot].lc = tree[tot].rc = tree[tot].dat = 0 ;
	return tot;
}

void update(int p,int l,int r,int pos)
{
   if(l == r) 
   {
   	 tree[p].dat++;
   	 return ;
   }
   int mid = (l+r)>>1;
   if(pos <= mid) {
   	 if(!tree[p].lc) tree[p].lc = build();
   	 update(tree[p].lc,l,mid,pos);
   }
   else 
   {
   	 if(!tree[p].rc) tree[p].rc = build();
   	 update(tree[p].rc,mid+1,r,pos);
   }
   tree[p].dat = tree[tree[p].lc].dat + tree[tree[p].rc].dat;
}

long long query(int p,int l,int r,int L,int R)
{
	if(L <= l && r <= R) return tree[p].dat ;
	int mid = (l+r)>>1;
	long long ans = 0;
	if(L <= mid) ans += query(tree[p].lc,l,mid,L,R);
	if(R > mid) ans += query(tree[p].rc,mid+1,r,L,R);
	return ans ;
}

int main ()
{
    tot = 0;
    root = build();
    int n;
    cin>>n;
    long long ans = 0; 
    for(int i =1;i<=n;i++)
    {
    	int x;
    	read(x);
    	ans += query(1,1,1e9,x+1,1e9);
    	update(1,1,1e9,x);
    }
    cout<<ans<<endl;
	return 0 ;
}