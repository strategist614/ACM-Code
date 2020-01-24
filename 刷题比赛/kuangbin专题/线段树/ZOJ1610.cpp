/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
	x = 0;
	char c = getchar();
	int sgn = 1;
	while (c < '0' || c > '9') {if (c == '-')sgn = -1; c = getchar();}
	while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
	x *= sgn;
}
template <typename T>
void out(T x)
{
	if (x < 0) {putchar('-'); x = -x;}
	if (x >= 10)out(x / 10);
	putchar(x % 10 + '0');
}
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 8005;
int vis[N];
int cnt = -1;
struct stree
{
	int l;
	int r;
	int add;
}tree[N<<2];

void pushdown(int rt)
{
	if(tree[rt].add != -1)
	{
		tree[rt<<1].add = tree[rt].add;
		tree[rt<<1|1].add = tree[rt].add;
		tree[rt].add = -1;
	}
}

void build(int rt,int l,int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	tree[rt].add = -1;
	if(l == r) 
	{
		return ;
	}
	int mid = (l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}

void update(int  rt,int L,int R,int val)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if(L <= l && r <= R) 
	{
		tree[rt].add = val;
		return ;
	}
	int mid = (l+r)>>1;
	pushdown(rt);
	if(L <= mid) update(rt<<1,L,R,val);
	if(R > mid) update(rt<<1|1,L,R,val);
}

void query(int rt,int L,int R)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
    if(l == r) 
    {
        if(tree[rt].add >= 0 && tree[rt].add != cnt) vis[tree[rt].add]++;
        cnt = tree[rt].add;
        return ;
    }
	pushdown(rt);
	int mid = (l+r)>>1;
	if(L <= mid) query(rt<<1,L,R);
	if(R > mid) query(rt<<1|1,L,R);
}

int main ()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
	   cnt = -1;
       build(1,0,8000);
       for(int i= 1;i<=n;i++)
       {
       	 int l,r,val;
       	 read(l);
       	 read(r);
       	 read(val);
       	 if(l < r)
       	 update(1,l+1,r,val);
       }
       memset(vis,0,sizeof(vis));
       query(1,0,8000);
       for(int i= 0;i<=8000;i++)
        {
        	if(vis[i])
        	{
        		cout<<i<<" "<<vis[i]<<endl;
        	}
        }
       cout<<endl;
	}
	return 0 ;
}