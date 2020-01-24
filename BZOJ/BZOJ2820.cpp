#include <bits/stdc++.h>
using namespace std;
int tn, p[1000500], mu[10000500], g[10000500];
bool e[10000500];
typedef long long ll;
void getmu()
{
    e[1] = 1;
    mu[1] = 1;
    for (int i = 2; i <= 10000100; i++)
    {
        if (!e[i])
        {
            p[++tn] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= tn; j++)
        {
            if (1ll * i * p[j] > 10000100)
                break;
            e[i * p[j]] = 1;
            mu[i * p[j]] = i % p[j] ? -mu[i] : 0;
            if (!i % p[j])
                break;
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    getmu();
    for (int i = 1; i <= tn; i++)
    {
        for (int j = p[i]; j <= 10000100; j += p[i])
            g[j] += mu[j / p[i]];
    }
    for(int i = 2;i <= 10000100;i++) g[i] += g[i - 1];
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        ll ans = 0;
        int l = 1, r;
        for (; l <= min(n, m); l = r + 1)
        {
            r = min(n / (n / l), m / (m / l));
            ans = ans + 1ll * (n / l) * (m / l) * (g[r] - g[l - 1]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}