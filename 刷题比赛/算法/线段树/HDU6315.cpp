
#include<bits/stdc++.h>
using namespace std;
const int N = 100000+5;
struct stree
{
  int sum,minb,maxa;
  int l;
  int r;
}tree[N<<2];
int b[N],add[N<<2];
char str[10];

void pushup(int rt)
{
  tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;//求和
  tree[rt].minb = min(tree[rt<<1].minb,tree[rt<<1|1].minb);//维护区间最大值
  tree[rt].maxa = max(tree[rt<<1].maxa,tree[rt<<1|1].maxa);//维护区间最小值
}

void pushdown(int rt)
{
  if(add[rt])
  {
    tree[rt<<1].maxa += add[rt];//rt的右子节点加上需要增加的值
    tree[rt<<1|1].maxa += add[rt];//rt的左子节点加上需要增加的值
    add[rt<<1] += add[rt];//右子节点打上延迟标记
    add[rt<<1|1] += add[rt];//左子节点打上延迟标记
    add[rt] = 0;
  }
}

void build(int l,int r,int rt)
{
  add[rt] = 0;
  tree[rt].l = l;
  tree[rt].r = r;
  if(l == r)
  {
    tree[rt].sum = tree[rt].maxa = 0;
    tree[rt].minb = b[l];
    return ;
  }
  int mid = (l+r)>>1;
  build(l,mid,rt<<1);
  build(mid+1,r,rt<<1|1);
  pushup(rt);
}

void update(int L,int R,int rt)
{
  if(L <= tree[rt].l && tree[rt].r <= R)
  {
    tree[rt].maxa++;
    if(tree[rt].maxa < tree[rt].minb)//区间的a最大值都比b的最小值要小，那么这段区间就不用更新了
    {
      add[rt]++;//给节点打上延迟标记，同时记录需要增加的值
      return ;
    }
    if(tree[rt].l == tree[rt].r)//更新到点
    {
      tree[rt].sum++;
      //此时已保证tree[rt].maxa >= tree[rt].minb 即为：a[rt] >= b[rt] 那么rt那个点的分子大于分母，sum值就会++
      tree[rt].minb += b[tree[rt].l];
      //minb 也就是那个点的b的值也要增加一倍，因为此时分子已经大于分母了，而sum的值每次只能更新1.
      //必须要更新分母，使得之后的add能够进行。否则maxa 始终比minb 大 就使得sum 的答案不对
      return;
    }
  }
  pushdown(rt);//向子节点下传延迟标记
  int mid = (tree[rt].r + tree[rt].l)>>1;
  if(L <= mid) update(L,R,rt<<1);
  if(R > mid) update(L,R,rt<<1|1);
  pushup(rt);
}

int query(int L,int R,int rt)
{
  if(L <= tree[rt].l && tree[rt].r <= R) return tree[rt].sum;
  int mid = (tree[rt].l+tree[rt].r)>>1;
  pushdown(rt);
  int ans = 0;
  if(L <= mid) ans += query(L,R,rt<<1);
  if(R > mid) ans += query(L,R,rt<<1|1);
  return ans;
}

int main ()
{
  int n,m,l,r;
  while(~scanf("%d %d",&n,&m))
  {
    for(int  i = 1;i<=n;i++) scanf("%d",&b[i]);
    getchar();
    build(1,n,1);
    while(m--)
    {
      scanf("%s%d%d",str,&l,&r);
      if(str[0] == 'a') update(l,r,1);
      else printf("%d\n",query(l,r,1));
    }
  }
  return  0;
}

/*
#include<bits/stdc++.h>
using namespace std;
const int N = 100000+5;
struct stree
{
  int sum,minb,maxa;
}tree[N<<2];
int b[N],add[N<<2];
char str[10];

void pushup(int rt)
{
  tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
  tree[rt].minb = min(tree[rt<<1].minb,tree[rt<<1|1].minb);
  tree[rt].maxa = max(tree[rt<<1].maxa,tree[rt<<1|1].maxa);
}

void pushdown(int rt)
{
  if(add[rt])
  {
    tree[rt<<1].maxa += add[rt];
    tree[rt<<1|1].maxa += add[rt];
    add[rt<<1] += add[rt];
    add[rt<<1|1] += add[rt];
    add[rt] = 0;
  }
}

void build(int l,int r,int rt)
{
  add[rt] = 0;
  if(l == r)
  {
    tree[rt].sum = tree[rt].maxa = 0;
    tree[rt].minb = b[l];
    return ;
  }
  int mid = (l+r)>>1;
  build(l,mid,rt<<1);
  build(mid+1,r,rt<<1|1);
  pushup(rt);
}

void update(int L,int R,int l,int r,int rt)
{
  if(L <= l && r <= R)
  {
    tree[rt].maxa++;
    if(tree[rt].maxa < tree[rt].minb)
    {
      add[rt]++;
      return ;
   }
    if(l == r && tree[rt].maxa >= tree[rt].minb)
     {
      tree[rt].sum++;
      tree[rt].minb += b[l];
      return;
    }
 }
  pushdown(rt);
  int mid = (l + r)>>1;
  if(L <= mid) update(L,R,l,mid,rt<<1);
  if(R > mid) update(L,R,mid+1,r,rt<<1|1);
  pushup(rt);
}

int query(int L,int R,int l,int r,int rt)
{
  if(L <= l && r <= R) return tree[rt].sum;
  int mid = (l+r)>>1;
  pushdown(rt);
  int ans = 0;
  if(L <= mid) ans += query(L,R,l,mid,rt<<1);
  if(R > mid) ans += query(L,R,mid+1,r,rt<<1|1);
  return ans;
}

int main ()
{
  int n,m,l,r;
  while(~scanf("%d %d",&n,&m))
  {
    for(int  i = 1;i<=n;i++) scanf("%d",&b[i]);
    build(1,n,1);
    while(m--)
    {
      scanf("%s%d%d",str,&l,&r);
      if(str[0] == 'a') update(l,r,1,n,1);
      else printf("%d\n",query(l,r,1,n,1));
    }
  }
  return  0;
}
*/
