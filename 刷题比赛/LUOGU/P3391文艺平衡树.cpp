#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
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
int n,m,tot = 0,root = 0;

struct splay
{
	int size;
	int ch[2];
	int rev;
	int p; 
	int val;
	int cnt;
}tree[N];

void pushup(int x)
{
	tree[x].size = tree[tree[x].ch[0]].size + tree[tree[x].ch[1]].size+tree[x].cnt;
}

void pushdown(int x)
{
	if(tree[x].rev)
	{
		tree[tree[x].ch[0]].rev ^= 1;
		tree[tree[x].ch[1]].rev ^= 1;
		swap(tree[x].ch[0],tree[x].ch[1]);
		tree[x].rev = 0;
 	}
}

bool chk(int x)
{
  return tree[tree[x].p].ch[1] == x;
}

void rotate(int x)
{
    int y = tree[x].p;
    int z = tree[y].p;
    int k = chk(x);
    tree[z].ch[chk(y)] = x;
    tree[x].p = z;
    tree[y].ch[k] = tree[x].ch[k ^ 1];
    tree[tree[x].ch[k^1]].p = y;
    tree[x].ch[k ^ 1] = y;
    tree[y].p = x;
    pushup(y);
    pushup(x);
}

void splay(int x,int aim)
{
   while(tree[x].p != aim)
   {
      int y = tree[x].p;
      int z = tree[y].p;
      if(z != aim)
      {
         if(chk(x) == chk(y)) rotate(y);
         else rotate(x);
      }
      rotate(x);
   }
   if(aim == 0) root = x;
}

void insert(int x)
{
    int cur = root,p = 0;
    while(cur && x != tree[cur].val)
    {
        p = cur;
        cur = tree[cur].ch[x > tree[cur].val];
    }
    if(cur)
    tree[cur].cnt++;
    else 
    {
        cur = ++tot;
        if(p)
        tree[p].ch[x > tree[p].val] = cur;
        tree[cur].ch[0] = tree[cur].ch[1] = 0;
        tree[cur].p = p;
        tree[cur].val = x;
        tree[cur].cnt = 1;
        tree[cur].size = 1;
    }
    splay(cur,0);
}


int kth(int k){
    int cur = root;
    while(1)
    {
      pushdown(cur);
      if(tree[cur].ch[0] && k <= tree[tree[cur].ch[0]].size)
      {
         cur = tree[cur].ch[0];
      }
      else if(k > tree[tree[cur].ch[0]].size + tree[cur].cnt)
      {
         k -= tree[tree[cur].ch[0]].size+tree[cur].cnt;
         cur = tree[cur].ch[1];
      }
      else return cur;
    }
}

void reverse(int l,int r)
{
	int x = kth(l-1);
	int y = kth(r+1);
	splay(x,0);
	splay(y,x);
	tree[tree[y].ch[0]].rev ^= 1;
}

void output(int x)
{
	pushdown(x);
	if(tree[x].ch[0]) output(tree[x].ch[0]);
    if(tree[x].val >= 1 && tree[x].val <= n) printf("%d ",tree[x].val);
    if(tree[x].ch[1]) output(tree[x].ch[1]);
}

int main ()
{
    read(n);
    read(m);
    for(int i = 0;i<=n+1;i++) insert(i);
    while(m--)
    {
    	int l,r;
    	read(l);
    	read(r);
    	reverse(l+1,r+1);
    }
    output(root);
	return 0 ;
}