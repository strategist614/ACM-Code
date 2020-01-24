#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
struct LCT
{
    int ch[N][2], fa[N], tag[N];
    inline void clear(int x)
    {
        ch[x][0] = fa[x] = tag[x] = 0;
    }
    int getch(int x)
    {
        return ch[fa[x]][1] == x;
    }
    int isroot(int x)
    {
        return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
    }
    void pushdown(int x)
    {
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
            splay(x), ch[x][1] = f;
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
    void link(int x, int y)
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
        return;
    }
}st;
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    while(m--)
    {
        char s[20];
        int x,y;
        scanf("%s %d %d",s,&x,&y);
        if(s[0] == 'C')
        {
            st.link(x,y); 
        }
        else if(s[0] == 'D')
        {
            st.Cut(x,y);
        }
        else
        {
            if(st.find(x) == st.find(y)) printf("Yes\n");
            else printf("No\n");
        }
        
    }
    return 0;
} 