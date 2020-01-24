#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[1000];
int main()
{
    int n, s;
    cin >> n >> s;
    int _ = s * 100;
    for (int i = 1; i <= n; i++)
        cin >> p[i].first >> p[i].second;
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        if (p[i].first < s || (p[i].first == s && p[i].second == 0))
        {
            ans = max(ans, p[i].second == 0 ? 0 : 100 - p[i].second);
        }
    }
    cout << ans << endl;
    return 0;
}