#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
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
const int N = 1e6 + 5, M = 1e6 + 5;
const ll INF= 0x7ffffffff;
ll head[N], ver[M], edge[M], Next[M], d[N];
int n, m, tot;
queue<int> q;
bool v[N];
struct node
{
    int x;
    int y;
    int z;
} e[N];

void add(int x, int y, int z) {
    ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}
void init()
{
	tot = 0;
    memset(ver, 0, sizeof(ver));
    memset(edge, 0, sizeof(edge));
    memset(Next, 0, sizeof(Next));
    memset(head, 0, sizeof(head));
    while (q.size()) q.pop();

}
void spfa() {
	for(int i= 1;i<=n;i++) 
	{
		v[i] = 0;
		d[i] = INF;
	}
    d[1] = 0; v[1] = 1;
    q.push(1);
    while (q.size()) {
        int x = q.front(); q.pop();
        v[x] = 0;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                if (!v[y]) q.push(y), v[y] = 1;
            }
        }
    }
}

int main() {
    int t;
    read(t);
    while (t--)
    {
        init();
        read(n);
        read(m);
        for (int i = 1; i <= m; i++) {
            read(e[i].x);
            read(e[i].y);
            read(e[i].z);
            add(e[i].x, e[i].y, e[i].z);
        }
        spfa();
        ll ans = 0;
        for (int i = 1; i <= n; i++) ans += d[i];
        init();
        for (int i = 1; i <= m; i++) add(e[i].y, e[i].x, e[i].z);
        spfa();
        for (int i = 1; i <= n; i++) ans += d[i];
        out(ans);
        puts("");
    }
    return 0;
}
