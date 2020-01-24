#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 1000010;
int ver[M], Next[M], head[N], dfn[N], low[N];
int Stack[N], ins[N], c[N];
int vc[M], nc[M], hc[N], tc;
vector<int> scc[N];
int n, m, tot, num, top, cnt;
int ot[N];
void add(int x, int y)
{
    ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

void add_c(int x, int y)
{
    vc[++tc] = y, nc[tc] = hc[x], hc[x] = tc;
}

void tarjan(int x)
{
    dfn[x] = low[x] = ++num;
    Stack[++top] = x, ins[x] = 1;
    for (int i = head[x]; i; i = Next[i])
        if (!dfn[ver[i]])
        {
            tarjan(ver[i]);
            low[x] = min(low[x], low[ver[i]]);
        }
        else if (ins[ver[i]])
            low[x] = min(low[x], dfn[ver[i]]);
    if (dfn[x] == low[x])
    {
        cnt++;
        int y;
        do
        {
            y = Stack[top--], ins[y] = 0;
            c[y] = cnt, scc[cnt].push_back(y);
        } while (x != y);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    int ans = 0;
    int k = 0;
    for (int x = 1; x <= n; x++)
        for (int i = head[x]; i; i = Next[i])
        {
            int y = ver[i];
            if (c[x] == c[y])
                continue;
            add_c(c[x], c[y]);
            ot[c[x]]++;
        }
    for (int i = 1; i <= cnt; i++)
    {
        if (ot[i] == 0)
        {
            k++;
            ans = scc[i].size();
        }
    }
    if (k == 1)
    {
        printf("%d\n", ans);
    }
    else
        printf("0\n");
    return 0;
}