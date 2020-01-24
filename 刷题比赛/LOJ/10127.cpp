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
const int N = 200005;
int num[N];
int a[N];
int main ()
{
	int m,d;
	read(m);
	read(d);
	int len = 0;
	int top = 0;
	int t = 0;
	for(int i= 1;i<=m;i++)
	{
		char op[20];
        scanf("%s",op);
        int x;
        scanf("%d",&x);
        if(op[0] == 'A')
        {
            x = (x + t) % d;
            num[++len] = x;
            if(top == 0 || num[a[top]] > x) a[++top] = len;
            else 
            {
            	while(top && num[a[top]] <= x) top--;
            	a[++top] = len;
            }
        } 
        else 
        {  
           int y = lower_bound(a,a+top+1,len-x+1) - a;
           t = num[a[y]];
           printf("%d\n",t); 
        }
	}
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
struct stree
{
   int l;
   int r;
   int maxn;	
}tree[N<<2];

void pushup(int rt)
{
	tree[rt].maxn = max(tree[rt<<1].maxn, tree[rt<<1|1].maxn);
}

void build(int rt,int l,int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	if(l == r)
	{
		tree[rt].maxn = 0;
	    return ;
	}
	int mid = (l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}

void insert(int rt,int x,int val)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if(l == r)
    {
    	tree[rt].maxn = val;
    	return ;
    }
    int mid = (l+r)>>1;
    if(x <= mid) insert(rt<<1,x,val);
    else insert(rt<<1|1,x,val);
    pushup(rt); 
}

int query(int rt,int L,int R)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if(L <= l && r <= R) return tree[rt].maxn;
	int mid = (l+r)>>1;
	int ans  = 0;
	if(L <= mid) ans = max(ans,query(rt<<1,L,R));
	if(R > mid) ans = max(ans,query(rt<<1|1,L,R));
	return ans;
}
int main ()
{ 
    int m,p;
    scanf("%d %d",&m,&p);
    build(1,1,m);
    int last = 0;
    int cnt = 0;
    for(int i = 1;i<=m;i++)
    {
       char op[20];
       int x;
       scanf("%s %d",op,&x);
       if(op[0] == 'A')
       {
          cnt++;
          x = (x + last)%p;
          insert(1,cnt,x);
       }
       else 
       {
          last = query(1,cnt-x+1,cnt);
          printf("%d\n",last);
       }
    } 
	return  0;
}