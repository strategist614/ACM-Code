#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct rec { int x, y, z; } edge[500010];
int fa[100010], n, m, ans;
bool operator <(rec a, rec b) {
    return a.z < b.z;
}
int get(int x) {
    if (x == fa[x]) return x;
    return fa[x] = get(fa[x]);
}
int main() {
    while (cin >> n && n)
    {
        ans = 0;
        int tot = 0;
        int m =  n * (n - 1) / 2;
        for (int i = 1; i <= m; i++)  scanf("%d %d %d", &edge[i].x, &edge[i].y, &edge[i].z);
        sort(edge + 1, edge + m + 1);
        for (int i = 1; i <= n; i++) fa[i] = i;
        for (int i = 1; i <= m; i++) {
            int x = get(edge[i].x);
            int y = get(edge[i].y);
            if (x == y) continue;
            fa[x] = y;
            ans += edge[i].z;
        }
        cout << ans << endl;
    }
    return 0;
}