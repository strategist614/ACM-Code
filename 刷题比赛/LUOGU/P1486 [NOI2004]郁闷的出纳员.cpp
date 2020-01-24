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
const int INF = 1547483647;
int n,m,tot = 0,ans = 0,root = 0;

struct splay
{
	int ch[2];
	int size;
	int cnt;
	int p;
    int val;
}tree[N];

int chk(int x)
{
	return tree[tree[x].p].ch[1] == x;
}

void pushup(int x)
{
	tree[x].size = tree[tree[x].ch[0]].size + tree[tree[x].ch[1]].size + tree[x].cnt;
}

void rotate(int x)
{
	int y = tree[x].p;
	int z = tree[y].p;
	int k = chk(x);
	tree[z].ch[chk(y)] = x;
	tree[x].p = z;
	tree[y].ch[k] = tree[x].ch[k ^ 1];
	tree[tree[x].ch[k ^ 1]].p = y;
	tree[x].ch[k ^ 1] = y;
	tree[y].p = x;
	pushup(y);
	pushup(x);
}

void splay(int x,int goal = 0)
{
    while(tree[x].p != goal)
    {
        int y = tree[x].p ;int z = tree[y].p;
        if(z != goal)
        {
            if(chk(x) == chk(y)) rotate(y);
            else rotate(x);
        }
        rotate(x);
    }
    if(!goal) root = x;
}

void insert(int x)
{
	//cout<<1;
    if(x < m) return ;
    int rt = root, p = 0;
    while(tree[rt].val != x && rt) p = rt , rt = tree[rt].ch[x > tree[rt].val];
    //cout<<1;
    if(rt) tree[rt].cnt++;
    else
    {
        rt = ++ tot;
        if(p) tree[p].ch[x > tree[p].val] = rt;
        tree[rt].p = p;
        tree[rt].ch[0] = tree[rt].ch[1] = 0;
        tree[rt].size = tree[rt].cnt = 1;
        tree[rt].val = x; 
    }
   //cout<<1;
    splay(rt);
}


void add(int x)
{
	for(int i =1;i<=tot;i++) tree[i].val += x;
}

void sub(int x)
{
	for(int i= 1;i<=tot;i++) tree[i].val -= x;
}

void find(int x)
{
   int cur = root;
   while(tree[cur].ch[x > tree[cur].val] && x != tree[cur].val)
   	  cur = tree[cur].ch[x > tree[cur].val];
   splay(cur);
} 

int kth(int k)
{
    if(k >= tree[root].size) return -1;
    k++;
    int rt = root;
    while(1)
    {
        if(tree[rt].ch[1] && k <= tree[tree[rt].ch[1]].size) rt = tree[rt].ch[1];
        else if(k > tree[tree[rt].ch[1]].size + tree[rt].cnt)
        {
            k = k - tree[tree[rt].ch[1]].size - tree[rt].cnt;
            rt = tree[rt].ch[0];
        }
        else return tree[rt].val;
    }
}

int succ(int x)
{
	find(x);
	if(tree[root].val >= x) return root;
	int cur = tree[root].ch[1];
	while(tree[cur].ch[0]) cur = tree[cur].ch[0];
	return cur;
}

void remove(int x)
{
	int rt = succ(x+m);
	splay(rt);
	ans += tree[tree[rt].ch[0]].size;
	tree[rt].ch[0] = 0;
	pushup(rt);
	sub(x);
}

int main ()
{
    read(n);
    read(m);
  //  cout<<1;
    insert(INF);
   // cout<<1;
    while(n--)
    {
        char opt[20];
        cin>>opt;
        int x;
        read(x);
        if(opt[0] == 'I') insert(x);
        if(opt[0] == 'A') add(x);
        if(opt[0] == 'S') remove(x);
        if(opt[0] == 'F') printf("%d\n",kth(x));
    }
    cout << ans << endl;
	return 0 ;
}
