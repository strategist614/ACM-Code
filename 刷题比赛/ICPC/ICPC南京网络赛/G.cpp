#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
const int INF = 0x3f3f3f3f;
int n,m,q;
int a[N];
int ans1[N],ans2[N];

struct stree
{
  int l;
  int r;
  int sum;
}tree[N<<2];
void pushup(int rt)
{
  tree[rt].sum = min(tree[rt<<1].sum,tree[rt<<1|1].sum);
}

void build(int l,int r,int rt)
{
  tree[rt].l = l;
  tree[rt].r = r;
  if(l == r)
  {
    tree[rt].sum = a[l];
    return ;
  }
  int mid = (l+r)>>1;
  build(l,mid,rt<<1);
  build(mid+1,r,rt<<1|1);
  pushup(rt);
}

void update(int rt,int val)
{
  if(tree[rt].l == tree[rt].r){
    tree[rt].sum = INF;
    return;
  }
  int mid = (tree[rt].l+tree[rt].r)>>1;
  if(val <= mid) update(rt<<1,val);
  else update(rt<<1|1,val);
  pushup(rt);
}

int query(int rt,int val)
{
  if(tree[rt].l == tree[rt].r)
  {
    return tree[rt].l;//返回房间编号
    //tree[rt].l 就是区间到了一个叶节点上就是其中的一个房间编号
  }
  int mid = (tree[rt].l+tree[rt].r)>>1;
  if(tree[rt<<1].sum <= val) return query(rt<<1,val);//查询时优先查询左边最小值小于val的区间
  if(tree[rt<<1|1].sum <=val) return query(rt<<1|1,val);
  return -1;
}

int main ()
{
  while(~scanf("%d %d",&n,&m))
 {
  for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
  build(1,n,1);
  int ansa = 0,ansb = 0;
  for(int i =1;i<=100000;i++)
  {
    if(ansa < n)
    {
      ansb += m;
      while(1)
      {
        int tt = query(1,ansb);//得到编号
        if(tt != -1) ansb -= a[tt],ansa++,update(1,tt);
        //如果存在房间满足条件4
        else break;
      }
    }
    ans1[i] = ansa,ans2[i] = ansb;
  }
  scanf("%d",&q);
  while(q--)
  {
    int p;
    scanf("%d",&p);
    printf("%d %d\n",ans1[p],ans2[p]);
  }
}
  return 0;
}
