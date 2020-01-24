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
const int N = 1e6+5;
int a[N];
int root[N],cnt = 0;
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
		tree[pos].dat = a[l];
		return pos;
	}
    int mid = (l+r)>>1;
    tree[pos].l = build(l,mid);
    tree[pos].r = build(mid+1,r);
    return pos;
} 
int update(int ed,int l,int r,int x,int val)
{
	int pos = ++cnt;
    tree[pos] = tree[ed];
	if(l == r) 
	{
		tree[pos].dat = val;
		return pos;
	}
	int mid = (l+r)>>1;
	if(x <= mid) tree[pos].l = update(tree[ed].l,l,mid,x,val);
	else tree[pos].r = update(tree[ed].r,mid+1,r,x,val);
	return pos;
}
int query(int ed,int l,int r,int pos)
{
	if(l == r) return tree[ed].dat;
	int mid = (l+r)>>1;
	if(pos <= mid) return query(tree[ed].l,l,mid,pos);
	else return query(tree[ed].r,mid+1,r,pos);
}
int main ()
{
    int n,m;
    cin>>n>>m;
    for(int i =1;i<=n;i++) read(a[i]);
    root[0] = build(1,n);
    for(int i= 1;i<=m;i++)
    {
    	int ed,op,val,pos;
    	read(ed);
    	read(op);
    	read(pos);
        if(op == 1)
        {
           read(val);
           root[i] = update(root[ed],1,n,pos,val);
        }
        else 
        {
           root[i] = root[ed];
           cout<<query(root[ed],1,n,pos)<<endl;  
        } 
    }
	return 0 ;
}