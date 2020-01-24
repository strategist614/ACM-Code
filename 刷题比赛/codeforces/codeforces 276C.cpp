#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int b[N],a[N];
int tot;
struct  stree
{
	int l;
	int r;
	ll sum;
	int add;
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
		tree[rt<<1|1].sum += tree[rt].add*(tree[rt<<1|1].r - tree[rt<<1|1].l +1); 
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
	pushdown(rt);
	int mid = (l+r)>>1;
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
		tree[rt].sum += val * (tree[rt].r-tree[rt].l+1);
		tree[rt].add += val ;
		return ;
	}
	pushdown(rt);
	int mid = (l+r)>>1;
	if(L <= mid) update(rt<<1,L,R,val);
	if(R > mid) update(rt<<1|1,L,R,val);
	pushup(rt);
}
void query(int rt,int L,int R)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if(tree[rt].sum == 0) return ;
	if(l == r) {b[++tot] = tree[rt].sum;return;} 
	pushdown(rt);
	query(rt<<1,L,R);
	query(rt<<1|1,L,R);
	pushup(rt); 
}
int main ()
{
    int n,q;
    cin>>n>>q;
    for(int i= 1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while(q--)
    {
    	int l,r;
    	cin>>l>>r;
        update(1,l,r,1);
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    ll ans = 0;
    for(int i = n;i>=1;i--)
    {
       ans += (ll)b[i]*(ll)a[i];
    }
    cout<<ans<<endl;
	return 0 ;
}

/*
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long a[N];
long long c[N];
long long sum[N];
int main ()
{
	int n,q;
	cin>>n>>q;
	for(int i= 1;i<=n;i++) cin>>a[i];
	while(q--)
	{
       int l,r;
       cin>>l>>r;
       c[l] += 1;
       c[r+1] -= 1;
	}
	for(int i = 1;i<=n;i++) sum[i] = sum[i-1]+c[i];
	sort(a+1,a+n+1);
    sort(sum+1,sum+n+1);
    long long ans = 0;
    for(int i= n;i>=1;i--)
    {
       ans = ans + (long long)sum[i]*(long long)a[i];
    }
    cout<<ans<<endl;
	return 0 ;
}
*/