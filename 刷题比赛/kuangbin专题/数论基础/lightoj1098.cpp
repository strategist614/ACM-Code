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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 205;
const double eps = 1e-8;
double a[N][N];
double del = 0.0;
int n;
int guess()
{
    for (int i = 1; i <= n; i++) {
        int k = i;
        for (int j = i + 1; j <= n; j++)if (fabs(a[j][i]) > fabs(a[k][i]))k = j;
        if (fabs(del = a[k][i]) < eps)return 0; //列全为0，无解
        for (int j = i; j <= n + 1; j++)swap(a[i][j], a[k][j]);
        for (int j = i; j <= n + 1; j++) a[i][j] /= del; //把选出来的第一个系数变为1
        for (k = 1; k <= n; k++)if (k != i) {
                del = a[k][i];
                for (int j = i; j <= n + 1; j++)a[k][j] -= a[i][j] * del;//选出来的系数是1所以只用乘上想消去的值相减即可
            }
    }
    return 1;
}
int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
            scanf("%lf", &a[i][j]);
    }
    int flag = guess();
    if (flag) for (int i = 1; i <= n; i++) printf("%.2f\n", a[i][n + 1]);
    else printf("No Solution\n");
    return 0 ;
}