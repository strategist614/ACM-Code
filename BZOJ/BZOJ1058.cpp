#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf (1e9 + 10)
int read()
{
    int x = 0;
    bool m = 0;
    char c = getchar();
    while (!isdigit(c) && c != '-')
        c = getchar();
    if (c == '-')
        m = 1, c = getchar();
    while (isdigit(c))
        x = x * 10 + c - '0', c = getchar();
    if (m)
        return -x;
    else
        return x;
}
const int N = 5e5 + 5;
int ax[N];
multiset<int> a, b;
int n, m;
int st[N], ed[N];
int ansMG = inf, ansMSG = inf;
void insert(int pos, int val)
{
    a.insert(abs(val - ed[pos]));
    if (pos != n)
    {
        a.erase(a.find(abs(st[pos + 1] - ed[pos])));
        a.insert(abs(st[pos + 1] - val));
    }
    ed[pos] = val;
}
void push(int x)
{
    int l = *--b.lower_bound(x), r = *b.lower_bound(x);
    ansMSG = min(ansMSG, abs(l - x));
    ansMSG = min(ansMSG, abs(r - x));
    b.insert(x);
}
int main()
{
    scanf("%d %d", &n, &m);
    b.insert(inf);
    b.insert(-inf);
    for (int i = 1; i <= n; i++)
    {
        ax[i] = read();
        st[i] = ed[i] = ax[i];
        push(ax[i]);
    }
    for (int i = 2; i <= n; i++)
        a.insert(abs(ax[i] - ax[i - 1]));
    while (m--)
    {
        char s[20];
        scanf("%s", s);
        if (s[0] == 'I')
        {
            int pos, val;
            pos = read();
            val = read();
            insert(pos, val);
            push(val);
        }
        else if (s[4] == 'S')
        {
            printf("%d\n", ansMSG);
        }
        else
            printf("%d\n", *a.begin());
    }
    return 0;
}