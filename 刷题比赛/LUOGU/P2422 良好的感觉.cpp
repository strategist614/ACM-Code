/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
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
typedef pair<int, int> pii;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 1e5 + 5;
int a[N];
int le[N], ri[N];
ll sum[N];
int main ()
{
    //freopen("input.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    int n;
    read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    stack<int> s;
    for (int i = 1; i <= n; i++)
    {
        while (!s.empty() && a[s.top()] > a[i]) {
            ri[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (s.size()) s.pop();
    for (int i = n; i >= 1; i--)
    {
        while (!s.empty() && a[s.top()] > a[i]) {
            le[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    ll ans = 0;
    ll _ = 0;
    for(int i = 1;i <= n;i++) if(!ri[i]) ri[i] = n + 1;
    for (int i = 1; i <= n; i++)
    {
        _ = (ll)a[i] * (sum[ri[i] - 1] - sum[le[i]]) ;
        ans = max(ans, _);
    }
    cout << ans << endl;
    return 0 ;
}