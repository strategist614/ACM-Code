#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
const double eps = 1e-8;
struct node
{
    double k, b;
    int id;
} a[N], st[N];
int ans[N];
int tot;
bool cmp(node a, node b)
{
    if (fabs(a.k - b.k) < eps)
        return a.b < b.b;
    return a.k < b.k;
}
double s(node a, node b)
{
    return (a.b - b.b) / (b.k - a.k);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf %lf", &a[i].k, &a[i].b);
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        while (tot)
        {
            if (fabs(st[tot].k - a[i].k) < eps)
                tot--;
            if (tot > 1 && s(a[i], st[tot - 1]) <= s(st[tot], st[tot - 1]))
                tot--;
            else
                break;
        }
        st[++tot] = a[i];
    }
    for (int i = 1; i <= tot; i++)
        ans[st[i].id] = 1;
    for (int i = 1; i <= n; i++)
        if (ans[i])
            printf("%d ", i);
    return 0;
}