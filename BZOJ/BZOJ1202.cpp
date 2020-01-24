#include <bits/stdc++.h>
using namespace std;
const int SIZE = 50010;

int T, n, m, tot, t;
int fa[SIZE];
int d[SIZE];
void init()
{
    for (int i = 0; i <= n; i++)
        fa[i] = i;
    memset(d, 0, sizeof(d));
}

int get(int x)
{
    if (x == fa[x])
        return x;
    int root = get(fa[x]);
    d[x] += d[fa[x]];
    return fa[x] = root;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &m);
        init();
        int flag = 0;
        while (m--)
        {
            int l, r, sum;
            scanf("%d %d %d", &l, &r, &sum);
            int x = get(l - 1);
            int y = get(r);
            if (x == y)
            {
                if (d[r] - d[l - 1] != sum)
                {
                    flag = 1;
                }
            }
            else
            {
                fa[x] = y;
                d[x] = d[r] - d[l - 1] - sum;
            }
        }
        if (!flag)
            printf("true\n");
        else
            printf("false\n");
    }
    return 0;
}