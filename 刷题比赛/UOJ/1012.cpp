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
typedef long long ll;
const int N = 200005;
struct stree
{
	int l;
	int r;
	int maxn;
}tree[N<<2];

void pushup(int rt)
{
	tree[rt].maxn = max(tree[rt<<1].maxn,tree[rt<<1|1].maxn);
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

int query(int L,int R,int rt)
{
  int r = tree[rt].r,l = tree[rt].l;
  if(L <= l && r <= R) return tree[rt].maxn;
  int mid = (l+r)>>1;
  int ans = 0;
  if(L <= mid) ans = max(ans,query(L,R,rt<<1));
  if(R > mid) ans = max(ans,query(L,R,rt<<1|1));
  return ans;
}

ll cnt;
int main ()
{
    int m,d;
    scanf("%d %d",&m,&d);
    build(1,1,m);
    int last = 0;
    for(int i = 1;i <= m;i++)
    {
    	char op[20];
    	scanf("%s",op);
    	int x;
    	if(op[0] == 'A')
    	{
    	   cnt++;
    	   scanf("%d",&x);
           x = (x + last)%d;
           insert(1,cnt,x); 
    	}
    	else 
        {
          
         scanf("%d",&x);
         last = query(cnt-x+1,cnt,1);
         printf("%d\n",last);
        }
    }
	return 0 ;
}
*/
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
int main ()
{
	
	return 0 ;
}