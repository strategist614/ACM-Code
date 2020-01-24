#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int fa[N];
int d[N];
int sz[N];
int get(int x)
{
    if (x == fa[x])
        return x;
    int root = get(fa[x]);
    d[x] += d[fa[x]];
    return fa[x] = root;
}

void merge(int x, int y)
{
    x = get(x), y = get(y);
    fa[x] = y;
    d[x] = sz[y];
    sz[y] += sz[x];
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i =1;i <= n;i++) {fa[i] = i;sz[i] = 1;}
    for (int i = 1; i <= n; i++)
    {
        char s[20];
        scanf("%s", s);
        if (s[0] == 'M')
        {
            int x, y;
            scanf("%d %d", &x, &y);
            merge(x, y);
        }
        else
        {
            int x, y;
            scanf("%d %d", &x, &y);
            if (get(x) == get(y))
            {
                printf("%d\n", abs(d[y] - d[x]) - 1);
            }
            else printf("-1\n");
        }
    }
    return 0;
}