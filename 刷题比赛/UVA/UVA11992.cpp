#include<bits/stdc++.h>
using namespace std;
const int N = 1000010;
const int INF = 0x3f3f3f3f;

struct stree
{
  int l;
  int r;
  int minn;
  int maxn;
  int addv;
  int setv;
  int sum;
}tree[N<<2];

void pushup(int rt)
{
  tree[rt].maxn = max(tree[rt<<1].maxn,tree[rt<<1|1].maxn);
  tree[rt].minn = min(tree[rt<<1].minn,tree[rt<<1|1].minn);
  tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
}

void pushdown(int rt)
{
  if(tree[rt].setv)
  {
    tree[rt<<1].addv = 0;
    tree[rt<<1|1].addv = 0;
    tree[rt<<1].setv = tree[rt].setv;
    tree[rt<<1|1].setv = tree[rt].setv;
    tree[rt<<1].sum = tree[rt].setv*(tree[rt<<1].r - tree[rt<<1].l +1);
    tree[rt<<1|1].sum = tree[rt].setv*(tree[rt<<1|1].r - tree[rt<<1|1].l+1);
    tree[rt<<1].maxn = tree[rt].setv;
    tree[rt<<1].minn = tree[rt].setv;
    tree[rt<<1|1].maxn = tree[rt].setv;
    tree[rt<<1|1].minn = tree[rt].setv;
    tree[rt].setv = 0;
  }
  if(tree[rt].addv)
  {
    tree[rt<<1].sum += tree[rt].addv*(tree[rt<<1].r - tree[rt].l +1);
    tree[rt<<1|1].sum += tree[rt].addv*(tree[rt<<1|1].r - tree[rt<<1|1].l+1);
    tree[rt<<1].maxn += tree[rt].addv;
    tree[rt<<1].minn += tree[rt].addv;
    tree[rt<<1|1].maxn += tree[rt].addv;
    tree[rt<<1|1].minn += tree[rt].addv;
    tree[rt<<1].addv += tree[rt].addv;
    tree[rt<<1|1].addv += tree[rt].addv;
    tree[rt].addv = 0;
  }
}

void build(int l,int r,int rt)
{
  tree[rt].l = l;
  tree[rt].r = r;
  if(l == r)
  {
    tree[rt].minn = 0;
    tree[rt].maxn = 0;
    tree[rt].sum = 0;
    tree[rt].addv = 0;
    tree[rt].setv = 0;
    return ;
  }
  int mid = (l+r)>>1;
  build(l,mid,rt<<1);
  build(mid+1,r,rt<<1|1);
  pushup(rt);
}

void update_add(int L,int R,int rt,int val)
{
  int l = tree[rt].l,r = tree[rt].r;
  if(L <= l && r <= R)
  {
    tree[rt].sum += val*(r-l+1);
    tree[rt].addv += val;
    tree[rt].maxn += val;
    tree[rt].minn += val;
    return;
  }
  int mid = (l+r)>>1;
  pushdown(rt);
  if(L <= mid) update_add(L,R,rt<<1,val);
  if(R > mid) update_add(L,R,rt<<1|1,val);
  pushup(rt);
}

void update_set(int L,int R,int rt,int val)
{
  int l = tree[rt].l,r = tree[rt].r;
  if(L <= l && r <= R)
  {
    tree[rt].sum = val*(r-l+1);
    tree[rt].setv = val;
    tree[rt].maxn = val;
    tree[rt].minn = val;
    tree[rt].addv = 0;
    return;
  }
  int mid = (l+r)>>1;
  pushdown(rt);
  if(L <= mid) update_set(L,R,rt<<1,val);
  if(R > mid) update_set(L,R,rt<<1|1,val);
  pushup(rt);
 }

stree query(int L,int R,int rt)
{
  int l = tree[rt].l,r = tree[rt].r;
  stree ans;
  ans.sum = 0;
  ans.maxn = 0;
  ans.minn = INF;
  if(L <= l && r <= R)
  {
    ans.sum = tree[rt].sum;
    ans.minn = tree[rt].minn;
    ans.maxn = tree[rt].maxn;
    return ans;
  }
  int mid = (l+r)>>1;
  pushdown(rt);
  if(L <= mid)
  {
    stree tmp = query(L,R,rt<<1);
    ans.sum += tmp.sum;
    ans.maxn = max(ans.maxn,tmp.maxn);
    ans.minn = min(ans.minn,tmp.minn);
  }
  if(R > mid)
  {
    stree tmp = query(L,R,rt<<1|1);
    ans.sum += tmp.sum;
    ans.maxn = max(ans.maxn,tmp.maxn);
    ans.minn = min(ans.minn,tmp.minn);
  }
  return ans;
}
int r,c,m;
int main ()
{
  while(~scanf("%d %d %d",&r,&c,&m))
  {
    build(1,r*c,1);
    int q,x1,y1,x2,y2,val;
    while(m--)
    {
    scanf("%d",&q);
    if(q == 3)
    {
      scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
      int Sum = 0,Maxn = 0,Minn = INF;
      for(int i = x1;i <= x2;i++)
      {
        stree ans = query((i-1)*c + y1,(i-1)*c + y2,1);
        Sum += ans.sum;
        Maxn = max(Maxn,ans.maxn);
        Minn = min(Minn,ans.minn);
    }
      printf("%d %d %d\n",Sum,Minn,Maxn);
  }
    else
    {
      scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&val);
      for(int i = x1 ; i <= x2 ; i++)
      {
        if(q == 1) update_add((i-1)*c+y1,(i-1)*c+y2,1,val);
        else update_set((i-1)*c + y1,(i-1)*c + y2,1,val);
        }
    }
  }
}
  return 0 ;
}
