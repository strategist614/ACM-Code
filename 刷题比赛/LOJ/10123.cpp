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
const int INF = 0x3f3f3f3f;
const int N = 5e4+5;
int n,q;
int a[N];
struct stree
{
	int l;
	int r;
	int maxn;
	int minn;
}tree[N<<2];
void pushup(int rt)
{
	tree[rt].maxn = max(tree[rt<<1].maxn,tree[rt<<1|1].maxn);
	tree[rt].minn = min(tree[rt<<1].minn,tree[rt<<1|1].minn);
}

void build(int rt,int l,int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	if(l == r)
	{
		tree[rt].maxn = a[l];
		tree[rt].minn = a[l];
		return ;
	}
	int mid = (l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}

int queryx(int rt,int L,int R)
{
	int l= tree[rt].l;
	int r= tree[rt].r;
	if(L <= l && r <= R) return tree[rt].maxn;
	int mid = (l+r)>>1;
	int ans = -INF;
	if(L <= mid) ans = max(ans,queryx(rt<<1,L,R));
	if(R > mid) ans = max(ans,queryx(rt<<1|1,L,R));
	return ans ;
}

int queryn(int rt,int L,int R)
{
	int l= tree[rt].l;
	int r= tree[rt].r;
	if(L <= l && r <= R) return tree[rt].minn;
	int mid = (l+r)>>1;
	int ans = INF;
	if(L <= mid) ans = min(ans,queryn(rt<<1,L,R));
	if(R > mid) ans = min(ans,queryn(rt<<1|1,L,R));
	return ans ;
}

int main ()
{
	read(n);
	read(q);
	for(int i =1;i<=n;i++) read(a[i]);
	build(1,1,n);
    while(q--)
    {
    	int l,r;
    	read(l);
    	read(r);
    	int maxn = queryx(1,l,r);
    	int minn = queryn(1,l,r);
    	int ans = maxn-minn;
    	out(ans);
    	puts("");
    }
	return 0 ;
 }