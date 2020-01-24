#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int a[N];
struct stree
{
   int l;
   int r;
   int dat;
}tree[N<<2];
void pushup(int rt,int ok)
{
	if(ok)
    tree[rt].dat = tree[rt<<1].dat | tree[rt<<1|1].dat;
    else 
    tree[rt].dat = tree[rt<<1].dat ^ tree[rt<<1|1].dat;
}
void build(int rt,int l,int r,int ok)
{
	tree[rt].l = l;
	tree[rt].r = r; 
	if(l == r)
	{
	    tree[rt].dat = a[l];
		return ;
	}
	int mid = (l + r)>>1;
    build(rt<<1,l,mid,!ok);
    build(rt<<1|1,mid+1,r,!ok);
    pushup(rt,ok);
}
void update(int rt,int x,int val,int ok)
{
   int l = tree[rt].l;
   int r = tree[rt].r;
   if(l == r) {tree[rt].dat = val;return;}
   int mid = (l+r)>>1;
   if(x <= mid) update(rt<<1,x,val,!ok);
   else update(rt<<1|1,x,val,!ok);
   pushup(rt,ok);
}
int main ()
{
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=pow(2,n);i++) cin>>a[i];
	int ok = n & 1;
	build(1,1,pow(2,n),ok);
    for(int i =1;i<=7;i++) cout<<tree[i].dat<<" ";
	while(m--)
	{
		int l,r;
		cin>>l>>r;
		update(1,l,r,ok);
     	cout<<tree[1].dat<<endl;
	} 
	return 0 ;
}