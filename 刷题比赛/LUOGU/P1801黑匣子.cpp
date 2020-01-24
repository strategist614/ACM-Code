#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
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
const int maxn = 200010;
int n, opt;

struct Splay {
    #define root (e[0].ch[1])
    #define inf (1e9 + 10)
    struct node {
        ll cnt, siz, val;
        ll father, ch[2];
    } e[maxn];
    ll pos, points;
    void update(int x) {
        e[x].siz = e[e[x].ch[0]].siz + e[e[x].ch[1]].siz + e[x].cnt;
    }
    void connect(int x, int f, int son) {
        e[x].father = f;
        e[f].ch[son] = x;
    }
    int identify(ll x) {
        return x == e[e[x].father].ch[0] ? 0 : 1;
    }
    void rotate(ll x) {
        ll f = e[x].father, fson = identify(x);
        ll ff = e[f].father, ffson = identify(f);
        ll y = e[x].ch[fson ^ 1];
        connect(y, f, fson);
        connect(f, x, fson ^ 1);
        connect(x, ff, ffson);
        update(f);
        update(x);
    }
    void splay(ll at, ll to) {
        if (!at) return;
        to = e[to].father;
        while (e[at].father != to) {
            ll up = e[at].father;
            if (e[up].father == to) rotate(at);
			else if (identify(at) == identify(up)) rotate(up), rotate(at);
			else rotate(at), rotate(at);
        }
    }
    void crepoint(ll val, ll father) {
        ll x = ++pos;
        e[x].val = val;
        e[x].father = father;
        e[x].cnt = e[x].siz = 1;
        e[x].ch[0] = e[x].ch[1] = 0;
    }
    void delpoint(ll x) {
        e[x].val = 0;
        e[x].father = 0;
        e[x].cnt = e[x].siz = 0;
        e[x].ch[0] = e[x].ch[1] = 0;
    }
    ll find(ll val) {
        ll u = root;
        while (u) {
            if (val == e[u].val) {
            	splay(u, root);
				return u;
			} 
            u = e[u].ch[val < e[u].val ? 0 : 1];
        }
    }
    void insert(ll val) {
        ll u = root;
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
            ll son = val < e[u].val ? 0 : 1;
            if (!e[u].ch[son]) {
                crepoint(val, u);
                e[u].ch[son] = pos;
                splay(pos, root);
                return;
            }
            u =  e[u].ch[son];
        }
    }
    void erase(ll val) {
        ll u = find(val);
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
            ll lft = e[u].ch[0], rit = e[u].ch[1];
            while (e[lft].ch[1]) lft = e[lft].ch[1];
            splay(lft, e[u].ch[0]);
            connect(rit, lft, 1);
            connect(lft, 0, 1);
            update(lft);
        }
        delpoint(u);
    }
    ll rank(ll val) {
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
    ll atrank(ll x) {
        ll u = root;
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
ll a[maxn];
//ll b[maxn];
int j = 1;
int main ()
{
	int n,m;
    read(n);
    read(m);
    for(int i= 1;i<=n;i++) read(a[i]);
    for(int i= 1;i<=m;i++)
    {
    	int u;
    	read(u);
    	for(;j<=u;j++) SY.insert(a[j]);
    	printf("%lld\n",SY.atrank(i));
    }
	return 0 ;
}