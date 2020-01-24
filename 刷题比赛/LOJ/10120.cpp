
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int inf = 0x3f3f3f3f;
int a[N];
struct  stree
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

int querymax(int rt,int L,int R)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
    if(L <= l && r <= R) return tree[rt].maxn;
	int mid = (l+r)>>1;
	int ans = -inf;
	if(L <= mid) ans = max(ans,querymax(rt<<1,L,R));
	if(R > mid) ans = max(ans,querymax(rt<<1|1,L,R));
	return ans ; 
}


int querymin(int rt,int L,int R)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
    if(L <= l && r <= R) return tree[rt].minn;
	int mid = (l+r)>>1;
	int ans = inf;
	if(L <= mid) ans = min(ans,querymin(rt<<1,L,R));
	if(R > mid) ans = min(ans,querymin(rt<<1|1,L,R));
	return ans ; 
}

int main ()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
    build(1,1,n);
	for(int i = 1; i+k-1 <= n;i++)
	{
        printf("%d %d\n",querymax(1,i,i+k-1),querymin(1,i,i+k-1));
	} 
	return 0 ;
}
/*
#include<cstdio>
#include<deque>
using namespace std;
deque <pair<int,int> > big,small;
int main()
{
	int n,k,a;
	scanf("%d %d",&n,&k);
	for (int i=1;i<k;i++)
	{
		scanf("%d",&a);
		while (!big.empty() && big.back().first<a) big.pop_back();
		big.push_back(make_pair(a,i));
		while (!small.empty() && small.back().first>a) small.pop_back();
		small.push_back(make_pair(a,i));
	}
	for (int i=k;i<=n;i++)
	{
		scanf("%d",&a);
		while (!big.empty() && big.back().first<a) big.pop_back();
		big.push_back(make_pair(a,i));
		while (!small.empty() && small.back().first>a) small.pop_back();
		small.push_back(make_pair(a,i));
		if (i-big.front().second==k) big.pop_front();
		if (i-small.front().second==k) small.pop_front();
		printf("%d %d\n",big.front().first,small.front().first);
	}
	return 0;
}
*/