#include<bits/stdc++.h>
using namespace std;
char a[1500];
int n;
struct stree
{
	int l;
	int r;
	char val;
}tree[5000];
void pushup(int rt)
{
	if(tree[rt<<1].val == 'B' && tree[rt<<1|1].val == 'B') tree[rt].val = 'B';
    else if(tree[rt<<1].val == 'I' && tree[rt<<1|1].val == 'I') tree[rt].val = 'I';
    else tree[rt].val = 'F';	
}
void build(int rt,int l,int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	if(l == r)
	{ 
       tree[rt].val = a[l];
       return ;
	}
	int mid = (l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
    pushup(rt);
}
void dfs(int x)
{
	if(tree[x<<1].val != 0) dfs(x<<1);
	if(tree[x<<1|1].val != 0) dfs(x<<1|1);
	cout<<tree[x].val;
}
int main ()
{
	cin>>n;
	int sum = 0 ;
	scanf("%s",a+1);
	int size = strlen(a+1);
	for(int i =1;i<=size;i++)
		{
            if(a[i] == '1') a[i] = 'I';
            else a[i] = 'B'; 
		}
    build(1,1,pow(2,n));
    dfs(1);
    return 0 ;
}