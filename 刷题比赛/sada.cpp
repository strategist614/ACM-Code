/*
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
double map[111][111];
double ans[111];
double eps=1e-7;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n+1;j++)
            scanf("%lf",&map[i][j]);
    for(int i=1;i<=n;i++){
        int r=i;
        for(int j=i+1;j<=n;j++)
            if(fabs(map[r][i])<fabs(map[j][i]))
                r=j;//find_the_biggest_number_of_the_first_column（at present)
        if(fabs(map[r][i])<eps){
            printf("No Solution");
            return 0;
        }
        if(i!=r)swap(map[i],map[r]);//对换一行或一列,属于找最大当前系数的其中一步。（这样就可以只处理当前行的系数啦！）
        double div=map[i][i];
        for(int j=i;j<=n+1;j++)
            map[i][j]/=div;
        for(int j=i+1;j<=n;j++){
            div=map[j][i];
            for(int k=i;k<=n+1;k++)
                map[j][k]-=map[i][k]*div;
        }
    }
    ans[n]=map[n][n+1];
    for(int i=n-1;i>=1;i--){
        ans[i]=map[i][n+1];
        for(int j=i+1;j<=n;j++)
            ans[i]-=(map[i][j]*ans[j]);
    }//回带操作
    for(int i=1;i<=n;i++)
        printf("%.2lf\n",ans[i]);
}
*/
//Author:XuHt
/*
#include <iostream>
#define ll long long
using namespace std;
const ll P = 999911659;
ll p[5] = {0,2,3,4679,35617}, m[5] = {0}, t[5];
ll pn[5][35617][2] = {{},{{1,1},{1,1}},{{1,1},{1,1},{2,2}},{{1,1},{1,1}},{{1,1},{1,1}}};
ll x, y;

ll ksm(ll a, ll b, ll c) {
    ll ans = 1;
    a %= c;
    b %= (c - 1);
    while (b) {
        if (b & 1) ans = ans * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return ans;
}

void exgcd(ll a, ll b) {
    if (!b) {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b);
    ll z = x;
    x = y;
    y = z - (a / b) * y;
}

ll C(ll d, ll n, ll i) {
    if (d < p[i] && n < p[i])
        return pn[i][n][0] * pn[i][d][1] % p[i] * pn[i][n-d][1] % p[i];
    return C(d % p[i], n % p[i], i) * C(d / p[i], n / p[i], i) % p[i];
}

int main() {
    ll n, q;
    cin >> n >> q;
    q %= P;
    if (!q) {
        cout << "0" << endl;
        return 0;
    }
    for (int i = 2; i < 4679; i++) {
        pn[3][i][0] = pn[3][i-1][0] * i % 4679;
        pn[3][i][1] = ksm(pn[3][i][0], 4677, 4679);
    }
    for (int i = 2; i < 35617; i++) {
        pn[4][i][0] = pn[4][i-1][0] * i % 35617;
        pn[4][i][1] = ksm(pn[4][i][0], 35615, 35617);
    }
    for (int i = 1; i <= 4; i++) {
        m[i] = (P - 1) / p[i];
        exgcd(m[i], p[i]);
        t[i] = x;
    }
    ll a[5] = {0,0,0,0,0};
    for (int d = 1; d * d <= n; d++)
        if (n % d == 0)
            for (int i = 1; i <= 4; i++) {
                a[i] = (a[i] + C(d, n, i)) % p[i];
                if (d * d != n) a[i] = (a[i] + C(n/d, n, i)) % p[i];
            }

    ll ans = 0;
    for (int i = 1; i <= 4; i++)
        ans = (a[i] * m[i] % (P - 1) * t[i] % (P - 1) + ans) % (P - 1);
    ans = (ans + P - 1) % (P - 1);
    cout << ksm(q, ans, P) << endl;
    return 0;
}
*/
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
const int N = 2005;
int n, m, p;
int a[N][N];
int ans[N][N];
ll comb[N][N];

void pre_work()
{
    for (int i = 0; i <= 2000; i++)comb[i][0] = comb[i][i] = 1;
    for (int i = 1; i <= 2000; i++)
        for (int j = 1; j <= i; j++) {
            comb[i][j] = ((comb[i - 1][j - 1] % p) + (comb[i - 1][j] % p)) % p;
        }
    for(int i= 0;i <= 2000;i++)
        for(int j = 0;j <= 2000;j++)
        {
            ans[i][j] = ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1];
            if(!comb[i][j] && i >= j) ans[i][j]++;
        }
}
int main ()
{
    int t;
    read(t);
    read(p);
    pre_work();
    while (t--)
    {
        int n, m;
        read(n);
        read(m);
        if (m > n) m = n;
        cout<<ans[n][m]<<endl;
    }
    return 0;
}