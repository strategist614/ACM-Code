#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 100010;
int n, opt;
int a[maxn];

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
            else if(e[u].val == val) result = e[u].val,cho = u;
            u = e[u].ch[val <= e[u].val ? 0 : 1];
        }
        splay(cho, root);
        return result;
    }
    int upper(int val) {
        int u = root, result = inf, cho = 0;
        while (u) {
            if (e[u].val > val && e[u].val < result) result = e[u].val, cho = u;
            else if(e[u].val == val) result = e[u].val,cho = u;
            u = e[u].ch[val >= e[u].val ? 1 : 0];
        }
        splay(cho, root);
        return result;
    }
  //  #undef root
  //  #undef inf
} s;
int main()
{
    int n;
    scanf("%d",&n);
    int x;
    x = read();
    ll ans = x;
    s.insert(x);
    for(int i =2;i <= n;i++)
    {
        scanf("%d",&a[i]);
        int pre = s.lower(a[i]);
        int succ = s.upper(a[i]);
        if(pre != -inf && succ != inf)
        ans = ans + (ll)min(abs(a[i] - pre),abs(a[i] - succ));
        else if(pre == -inf && succ != inf)
        ans = ans + (ll)abs(a[i] - succ);
        else if(pre != -inf && succ == inf)
        ans = ans + (ll)abs(a[i] - pre);
        s.insert(a[i]);   
    }
    printf("%lld\n",ans);
    return 0;
}