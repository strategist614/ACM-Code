#include <bits/stdc++.h>
using namespace std;
const int SIZE = 4e5 + 5;
int head[SIZE], ver[SIZE * 2], Next[SIZE * 2];
int vis[SIZE], a[SIZE];
int fa[SIZE];
pair<int, int> p[SIZE];
int tot, n, m;
int c[SIZE];
void add(int x, int y)
{
    ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

int get(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = get(fa[x]);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &p[i].first, &p[i].second);
        add(p[i].first, p[i].second);
        add(p[i].second, p[i].first);
    }
    int k;
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &a[i]);
        vis[a[i]]++;
    }
    for (int i = 1; i <= m; i++)
    {
        int x = p[i].first;
        int y = p[i].second;
        if (!vis[x] && !vis[y] && get(x) != get(y))
            fa[get(x)] = y;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (get(i) == i && !vis[i])
            ans++;

    for (int i = k; i >= 0; i--)
    {
        c[i] = ans;
        int x = a[i];
        vis[x] = 0;
        for (int j = head[x]; j; j = Next[j])
        {
            int y = ver[j];
            if (!vis[y])
            {
                if (get(y) != get(x))
                    fa[get(x)] = get(y), ans--;
            }
        }
        ans++;
    }
    for (int i = 0; i <= k; i++)
        printf("%d\n", c[i]);
    return 0;
}