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
const int mod = 998244353;
const int G = 3;
const int maxn = 1000500;
int n, m, r[maxn << 2];
ll f[maxn << 2], g[maxn << 2], invn, invG;
ll powM(ll a, ll t)
{
    ll ans = 1, buf = a;
    while (t)
    {
        if (t & 1) ans = (ans * buf) % mod;
        buf = (buf * buf) % mod;
        t >>= 1;
    }
    return ans ;
}
ll inv(ll x)
{
    return powM(x, mod - 2);
}
void NTT(ll *f, int op)
{
    for (int i = 0; i < n; i++)
        if (i < r[i])swap(f[i], f[r[i]]);
    for (int p = 2; p <= n; p <<= 1) {
        int len = p / 2;
        long long tmp = powM(op == 1 ? G : invG, (mod - 1) / p);
        for (int k = 0; k < n; k += p) {
            long long buf = 1;
            for (int l = k; l < k + len; l++) {
                long long tt = (buf * f[len + l]) % mod;
                f[len + l] = (f[l] - tt + mod) % mod;
                f[l] = (f[l] + tt) % mod;
                buf = (buf * tmp) % mod;
            }
        }
    }
}
int main ()
{
    scanf("%d", &n);
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    m = n;
    for (int i = 0; i < a.size(); i++) {
        int x = a[i] - '0';
        f[i] = x;
    }
    for (int i = 0; i < b.size(); i++) {
        int x = b[i] - '0';
        g[i] = x;
    }
    for (m += n, n = 1; n <= m; n <<= 1);
    invn = inv(n); invG = inv(G);
    for (int i = 0; i < n; i++)
        r[i] = (r[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
    NTT(f, 1);
    NTT(g, 1);
    for (int i = 0; i < n; ++i) f[i] = (f[i] * g[i]) % mod;
    NTT(f, -1);
    for (int i = 0; i <= m; ++i)
      f[i] = (f[i]*invn) % mod;
    for (int i = 0; i <= m; i++) {
        if (f[i] >= 10) {
            f[i + 1] += f[i] / 10;
            f[i] %= 10;
        }
    }
    while (f[m] == 0) m--;
    for (int i = m; i >= 0; i--) {
        printf("%lld", f[i]);
    }
    return 0 ;
}