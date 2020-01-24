/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200010;
ll m,d;
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

void build(int l,int r,int rt)
{
  tree[rt].l = l;
  tree[rt].r = r;
  if(l == r)
  {
    tree[rt].maxn = 0;
    return;
  }
  int mid = (l + r) >> 1;
  build(l,mid,rt<<1);
  build(mid+1,r,rt<<1|1);
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

void insert(int rt,int x,int val)
{
  int r = tree[rt].r,l = tree[rt].l;
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
ll cnt;
int main ()
{
  scanf("%lld %lld",&m,&d);
  int last = 0;
  build(1,m,1);
  for(int i = 1;i <= m;i++)
  {
    char s[20];
    int x;
    scanf("%s",&s);
    if(s[0] == 'A')
    {
      cnt++;
      scanf("%d",&x);
      x = (x + last)%d;
      insert(1,cnt,x);//给最后面加上x
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
/*
5 100
A 96
Q 1
A 97
Q 1
Q 2
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
const int N = 200010;
int a[N];
int num[N];
int top,len,t;
int main ()
{
  int n,d;
  cin>>n>>d;
  int p = 0;
  for(int i= 1;i<=n;i++)
  {
    char s[20];
    int x;
    scanf("%s %d",s,&x);
    if(s[0] == 'A')
    {
        x = (x+t)%d;
        num[++len] = x;
        while(top && num[a[top]] <= x) top--;
        a[++top] = len;
    }
    else 
    {
       int y = lower_bound(a+1,a+top+1,len-x+1) -a;
       t = num[a[y]];
       printf("%d\n",t );
    }
  }
  return 0;
}
*/
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
int main ()
{
  
  return 0 ;
}