/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
/*
#include<bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
    x = 0;
    char c = getchar();
    int sgn = 1;
    while (c < '0' || c > '9') {if (c == '-')sgn = -1; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    x *= sgn;
}
template <typename T>
void out(T x)
{
    if (x < 0) {putchar('-'); x = -x;}
    if (x >= 10)out(x / 10);
    putchar(x % 10 + '0');
}
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 505;
const int M = 40000;
struct edge
{
    int u;
    int v;
    int w;
} e[M];
int d[M];
int tot = 0;

int main ()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, w;
        cin >> n >> m >> w;
        tot = 0 ;
        memset(d, 0x3f, sizeof(d));
        d[1] = 0;
        for (int i = 1; i <= m; i++)
        {
            int x, y, z;
            read(x);
            read(y);
            read(z);
            e[tot].u = x;
            e[tot].v = y;
            e[tot++].w = z;
            e[tot].u = y;
            e[tot].v = x;
            e[tot++].w = z;
        }
        for (int i = 1; i <= w; i++)
        {
            int x, y, z;
            read(x);
            read(y);
            read(z);
            e[tot].u = x;
            e[tot].v = y;
            e[tot++].w = -z;
        }
        int flag = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = 0; j < tot; j++)
            {
                int x = e[j].u;
                int y = e[j].v;
                int z = e[j].w;
                if (d[y] > d[ x] + z) d[y] = d[x] + z;
            }
        }
        for (int j = 0; j < tot; j++)
        {
            int x = e[j].u;
            int y = e[j].v;
            int z = e[j].w;
            if (d[y] > d[x] + z) {
                flag = 1;
                break;
            }
        }

        if (flag)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
    x = 0;
    char c = getchar();
    int sgn = 1;
    while (c < '0' || c > '9') {if (c == '-')sgn = -1; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    x *= sgn;
}
template <typename T>
void out(T x)
{
    if (x < 0) {putchar('-'); x = -x;}
    if (x >= 10)out(x / 10);
    putchar(x % 10 + '0');
}
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 505;
const int M = 40000;
struct edge
{
    int u;
    int v;
    int w;
} e[M];
int d[M];
int tot = 0;
int main ()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        e[++tot].u = x;
        e[tot].v = y;
        e[tot].w = z;
    }
    cout << tot << endl;
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= tot; j++)
        {
            int x = e[j].u;
            int y = e[j].v;
            int z = e[j].w;
            if (d[y] > d[x] + z)
            {
                d[y] = d[x] + z ;
                cout << i << " " << j << " " << d[y] << " " << d[x] << endl;
            }
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 1; i <= tot; i++)
    {
        int x = e[i].u;
        int y = e[i].v;
        int z = e[i].w;
        if (d[y] > d[x] + z)
        {
            d[y] = d[x] + z ;
            cout << i << " " << d[y] << " " << d[x] << endl;
        }
    }
    return 0 ;
}
/*
4 6
1 2 1
1 4 4
2 3 3
2 4 2
3 1 1
4 3 -5
*/