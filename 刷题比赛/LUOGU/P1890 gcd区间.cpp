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
const int N = 1005;
int gcd(int a,int b)
{
	return b ? gcd(b,a%b):a;
}
int n,m,a[N];
struct s_tree
{
	int l;
	int r;
	int dat;
}tree[N<<2];

void pushup(int rt)
{
   tree[rt].dat = gcd(tree[rt<<1].dat,tree[rt<<1|1].dat);
}

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
	pushup(rt);
}

int ask(int rt,int L,int R)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if(L <= l && r <= R) return tree[rt].dat ;
	int mid = (l+r)>>1;
	int ans = 0;
	if(L <= mid) ans = gcd(ans,ask(rt<<1,L,R));
	if(R > mid) ans = gcd(ans,ask(rt<<1|1,L,R));
	return ans;
}

int main ()
{
    read(n);
    read(m);
    for(int i= 1;i<=n;i++) read(a[i]);
    build(1,1,n);
    while(m--)
    {
    	int l,r;
    	read(l);
    	read(r);
    	int ans = ask(1,l,r);
    	out(ans);
    	puts("");
    }

	return 0; 
}