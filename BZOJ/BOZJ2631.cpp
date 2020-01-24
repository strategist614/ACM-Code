#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int mod = 51061;
#define int long long

int sum[N], val[N], mul[N], add[N], siz[N], ch[N][2], fa[N], tag[N];
struct LCT
{
    int getch(int x)
    {
        return (ch[fa[x]][1] == x);
    }
    int isroot(int x)
    {
        return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
    }
    void pushup(int x)
    {
        siz[x] = siz[ch[x][0]] + 1 + siz[ch[x][1]];
        sum[x] = (sum[ch[x][0]] + val[x] + sum[ch[x][1]]) % mod;
    }
    void pushdown(int x)
    {
        if (mul[x] != 1)
        {
            if (ch[x][0]) 
            {
                mul[ch[x][0]] = (mul[ch[x][0]] * mul[x]) % mod;
                val[ch[x][0]] = (val[ch[x][0]] * mul[x]) % mod;
                sum[ch[x][0]] = (sum[ch[x][0]] * mul[x]) % mod;
                add[ch[x][0]] = (add[ch[x][0]] * mul[x]) % mod;
            }
            if (ch[x][1])
            {
                mul[ch[x][1]] = (mul[ch[x][1]] * mul[x]) % mod;
                val[ch[x][1]] = (val[ch[x][1]] * mul[x]) % mod;
                sum[ch[x][1]] = (sum[ch[x][1]] * mul[x]) % mod;
                add[ch[x][1]] = (add[ch[x][1]] * mul[x]) % mod;
            }
            mul[x] = 1;
        }
        if (add[x])
        {
            if (ch[x][0])
            {
                add[ch[x][0]] = (add[ch[x][0]] + add[x]) % mod;
                sum[ch[x][0]] = (sum[ch[x][0]] + add[x] * siz[ch[x][0]] % mod) % mod;
                val[ch[x][0]] = (val[ch[x][0]] + add[x]) % mod;
            }
            if (ch[x][1])
            {
                add[ch[x][1]] = (add[ch[x][1]] + add[x]) % mod;
                sum[ch[x][1]] = (sum[ch[x][1]] + add[x] * siz[ch[x][1]] % mod) % mod;
                val[ch[x][1]] = (val[ch[x][1]] + add[x]) % mod;
            }
            add[x] = 0;
        }
        if (tag[x])
        {
            if (ch[x][0])
                swap(ch[ch[x][0]][0], ch[ch[x][0]][1]), tag[ch[x][0]] ^= 1;
            if (ch[x][1])
                swap(ch[ch[x][1]][0], ch[ch[x][1]][1]), tag[ch[x][1]] ^= 1;
            tag[x] = 0;
        }
    }
    void update(int x)
    {
        if (!isroot(x))
            update(fa[x]);
        pushdown(x);
    }
    inline void rotate(int x)
    {
        int y = fa[x], z = fa[y], chx = getch(x), chy = getch(y);
        fa[x] = z;
        if (!isroot(y))
            ch[z][chy] = x;
        ch[y][chx] = ch[x][chx ^ 1];
        fa[ch[x][chx ^ 1]] = y;
        ch[x][chx ^ 1] = y;
        fa[y] = x;
        pushup(y);
        pushup(x);
    }
    void splay(int x)
    {
        update(x);
        for (int f = fa[x]; f = fa[x], !isroot(x); rotate(x))
            if (!isroot(f))
                rotate(getch(x) == getch(f) ? f : x);
    }
    void access(int x)
    {
        for (int f = 0; x; f = x, x = fa[x])
            splay(x), ch[x][1] = f, pushup(x);
    }
    void makeroot(int x)
    {
        access(x);
        splay(x);
        swap(ch[x][0], ch[x][1]);
        tag[x] ^= 1;
    }
    int find(int x)
    {
        access(x);
        splay(x);
        while (ch[x][0])
            x = ch[x][0];
        return x;
    }
    inline void link(int x, int y)
    {
        makeroot(x);
        if (find(y) != x)
            fa[x] = y;
    }
    inline void Cut(int x, int y)
    {
        makeroot(x);
        if (find(y) == x && fa[x] == y && !ch[x][1])
        {
            fa[x] = ch[y][0] = 0;
        }
        pushup(y);
    }
    void split(int x, int y)
    {
        makeroot(x);
        access(y);
        splay(y);
    }
} st;
main()
{
    int n, m;
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        siz[i] = val[i] = mul[i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%lld %lld", &u, &v);
        st.link(u, v);
    }
    while (m--)
    {
        char s[20];
        scanf("%s", &s);
        if (s[0] == '+')
        {
            int u, v, c;
            scanf("%lld %lld %lld", &u, &v, &c);
            st.split(u, v);
            val[v] = (val[v] + c) % mod;
            sum[v] = (sum[v] + c) % mod;
            add[v] = (add[v] + c) % mod;
        }
        else if (s[0] == '-')
        {
            int x, y, u, v;
            scanf("%lld %lld %lld %lld", &x, &y, &u, &v);
            st.Cut(x, y);
            st.link(u, v);
        }
        else if (s[0] == '*')
        {
            int u, v, c;
            scanf("%lld %lld %lld", &u, &v, &c);
            st.split(u, v); 
            val[v] = val[v] * c % mod;
            sum[v] = sum[v] * c % mod;
            mul[v] = mul[v] * c % mod;
        }
        else
        {
            int u, v;
            scanf("%lld %lld", &u, &v);
            st.split(u, v);
            printf("%lld\n", sum[v]);
        }
    }
    return 0;
}