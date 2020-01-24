/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<cstdio>
#include<cstring>

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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b ?gcd(b,a%b):a;}
const int N = 5e4+5;
const int INF = 0x7fffffff;
int a[N];
struct stree 
{
	int l;
	int r;
	int minn;
	int maxn;
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
		tree[rt].minn = tree[rt].maxn = a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}

int query_min(int rt,int L,int R)
{
     int l = tree[rt].l;
     int r = tree[rt].r;
     if(L <= l && r <= R) return tree[rt].minn;
     int ans = INF;
     int mid = (l+r)>>1;
     if(L <= mid) ans = min(ans,query_min(rt<<1,L,R));
     if(R > mid) ans = min(ans,query_min(rt<<1|1,L,R));
     return ans; 
}

int query_max(int rt,int L,int R)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if(L <= l && r <= R) return tree[rt].maxn ;
    int ans = 0;
    int mid = (l+r)>>1;
    if(L <= mid) ans = max(ans,query_max(rt<<1,L,R));
    if(R > mid) ans = max(ans,query_max(rt<<1|1,L,R));
    return ans ;
}

int main ()
{
	int n,q;
	read(n);
	read(q);
	for(int i= 1;i<=n;i++) read(a[i]);
    build(1,1,n);
    while(q--)
    {
    	int l,r;
    	read(l);
    	read(r);
    	int maxn = query_max(1,l,r);
    	int minn = query_min(1,l,r);
    	out(maxn-minn);
    	puts("");
    }
	return 0 ;
}