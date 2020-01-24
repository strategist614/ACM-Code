/*
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b ?gcd(b,a%b):a;}
int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

template <typename T>
void out(T x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>=10)out(x/10);
	putchar(x%10+'0');
}

const int maxn = 100010;
int n, opt;

struct Splay {
    #define root (e[0].ch[1])
    #define inf (1e9 + 10)
    struct node {
        int cnt, siz, val;
        int father, ch[2];
    } e[maxn];
    int pos, points;
    void update(int x) {
        e[x].siz = e[e[x].ch[0]].siz + e[e[x].ch[1]].siz + e[x].cnt;
    }
    void connect(int x, int f, int son) {
        e[x].father = f;
        e[f].ch[son] = x;
    }
    int identify(int x) {
        return x == e[e[x].father].ch[0] ? 0 : 1;
    }
    void rotate(int x) {
        int f = e[x].father, fson = identify(x);
        int ff = e[f].father, ffson = identify(f);
        int y = e[x].ch[fson ^ 1];
        connect(y, f, fson);
        connect(f, x, fson ^ 1);
        connect(x, ff, ffson);
        update(f);
        update(x);
    }
    void splay(int at, int to) {
        if (!at) return;
        to = e[to].father;
        while (e[at].father != to) {
            int up = e[at].father;
            if (e[up].father == to) rotate(at);
			else if (identify(at) == identify(up)) rotate(up), rotate(at);
			else rotate(at), rotate(at);
        }
    }
    void crepoint(int val, int father) {
        int x = ++pos;
        e[x].val = val;
        e[x].father = father;
        e[x].cnt = e[x].siz = 1;
        e[x].ch[0] = e[x].ch[1] = 0;
    }
    void delpoint(int x) {
        e[x].val = 0;
        e[x].father = 0;
        e[x].cnt = e[x].siz = 0;
        e[x].ch[0] = e[x].ch[1] = 0;
    }
    int find(int val) {
        int u = root;
        while (u) {
            if (val == e[u].val) {
            	splay(u, root);
				return u;
			} 
            u = e[u].ch[val < e[u].val ? 0 : 1];
        }
    }
    void insert(int val) {
        int u = root;
        points++;
        if (points == 1) {
            crepoint(val, 0);
            root = pos;
            return;
        }
        while (u) {
            e[u].siz++;
            if (e[u].val == val) {
                e[u].cnt++;
                splay(u, root);
                return;
            }
            int son = val < e[u].val ? 0 : 1;
            if (!e[u].ch[son]) {
                crepoint(val, u);
                e[u].ch[son] = pos;
                splay(pos, root);
                return;
            }
            u =  e[u].ch[son];
        }
    }
    void erase(int val) {
        int u = find(val);
        points--;
        if (e[u].cnt > 1)  {
            e[u].cnt--;
            e[u].siz--;
            return;
        }
        if (!e[u].ch[0]) {
            connect(e[u].ch[1], 0, 1);
            root = e[u].ch[1];
        } else {
            int lft = e[u].ch[0], rit = e[u].ch[1];
            while (e[lft].ch[1]) lft = e[lft].ch[1];
            splay(lft, e[u].ch[0]);
            connect(rit, lft, 1);
            connect(lft, 0, 1);
            update(lft);
        }
        delpoint(u);
    }
    int rank(int val) {
        int u = root, ans = 0;
        while (u) {
            if (val == e[u].val) {
                ans += e[e[u].ch[0]].siz + 1;
                splay(u, root);
                return ans;
            }
            if (val < e[u].val) u = e[u].ch[0];
            else ans += e[e[u].ch[0]].siz + e[u].cnt, u = e[u].ch[1];
        }
    }
    int atrank(int x) {
        int u = root;
        while (u) {
        	if (x <= e[e[u].ch[0]].siz) u = e[u].ch[0];
        	else if (x <= e[e[u].ch[0]].siz + e[u].cnt) {
        		splay(u, root);
				return e[u].val;
			} else x -= e[e[u].ch[0]].siz + e[u].cnt, u = e[u].ch[1];
        }
    }
    int lower(int val) {
        int u = root, result = -inf, cho = 0;
        while (u) {
            if (e[u].val < val && e[u].val > result) result = e[u].val, cho = u;
            u = e[u].ch[val <= e[u].val ? 0 : 1];
        }
        splay(cho, root);
        return result;
    }
    int upper(int val) {
        int u = root, result = inf, cho = 0;
        while (u) {
            if (e[u].val > val && e[u].val < result) result = e[u].val, cho = u;
            u = e[u].ch[val >= e[u].val ? 1 : 0];
        }
        splay(cho, root);
        return result;
    }
    #undef root
    #undef inf
} SY;

int main() {
    
    n = read();
    while (n--) {
        opt = read();
        switch(opt) {
            case 1:
                SY.insert(read());
                break;
            case 2:
                SY.erase(read());
                break;
            case 3:
                printf("%d\n", SY.rank(read()));
                break;
            case 4:
                printf("%d\n", SY.atrank(read()));
                break;
            case 5:
                printf("%d\n", SY.lower(read()));
                break;
            case 6:
                printf("%d\n", SY.upper(read()));
                break;
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
const int N = 1e5+5;

struct splay
{
   int ch[2];
   int cnt;
   int val;
   int size;
   int p;    
}tree[N];

int tot,root,n;

bool chk(int x)
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

void find(int x)
{
    int cur = root;
    while(tree[cur].ch[x > tree[cur].val] && x != tree[cur].val)
        cur = tree[cur].ch[x > tree[cur].val];
    splay(cur,0);
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

int succ(int x){
    find(x);
    if(tree[root].val > x) return root;
    int cur = tree[root].ch[1];
    while(tree[cur].ch[0])
       cur = tree[cur].ch[0];
    return cur;
}

int pre(int x){
    find(x);
    if(tree[root].val < x) return root;
    int cur = tree[root].ch[0];
    while(tree[cur].ch[1])
      cur = tree[cur].ch[1];
    return cur;
}

void remove(int x){
    int last = pre(x);
    int next = succ(x); 
    splay(last,0);
    splay(next,last);
    int del = tree[next].ch[0];
    if(tree[del].cnt > 1)
    {
        tree[del].cnt--;
        splay(del,0);
    }
    else tree[next].ch[0] = 0;
}

int kth(int k){
    int cur = root;
    while(1)
    {
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

int main ()
{
    read(n);
    insert(0x3f3f3f3f);
    insert(0xcfcfcfcf);
    while(n--)
    {
        int opt,x;
        read(opt);
        read(x);
        if(opt == 1)
        {
           insert(x);
        }
        else if(opt == 2)
        {
           remove(x);
        }
        else if(opt == 4)
        {
           int ans = kth(x+1);
           out(tree[ans].val);
           puts("");
        }
        else if(opt == 3)
        {
           find(x);
           int ans = tree[tree[root].ch[0]].size;
           out(ans);
           puts("");
        }
        else if(opt == 5)
        {
           int ans = pre(x);
           out(tree[ans].val);
           puts("");
        }
        else 
        {
          int ans = succ(x);
          out(tree[ans].val);
          puts("");
        }
    }
    return 0 ;
}