#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int s(int x) {
    int ans = 0;
    while (x)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
ll ksm(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1) ans = ans * a;
        b >>= 1;
        a = a * a;
    }
    return ans;
}

vector<ll> v;
int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    for (int i = 1; i <= 81; i++) {
        ll x = b * ksm(i, a) + c;
        if (x >= 1e9 || x < 0) continue;
        if (i == s(x)) v.push_back(x);
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    return 0 ;
}