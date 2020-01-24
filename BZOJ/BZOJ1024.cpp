#include <bits/stdc++.h>
using namespace std;

double dfs(double x, double y, int n)
{
    if (n == 1)
        return max(x, y) / min(x, y);
    double ans = 1e9;
    for (int i = 1; i < n; i++)
    {
        ans = min(ans, max(dfs(x * i / n, y, i), dfs(x * (n - i) / n, y, n - i)));
    }
    for (int i = 1; i < n; i++)
    {
        ans = min(ans, max(dfs(x, y * i / n, i), dfs(x, y * (n - i) / n, n - i)));
    }
    return ans;
}
int main()
{
    double x, y;
    int n;
    scanf("%lf %lf %d", &x, &y, &n);
    printf("%.6f\n", dfs(x, y, n));
    return 0;
}