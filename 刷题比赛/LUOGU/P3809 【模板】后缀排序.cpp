/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
  去做难度超过自己平时比赛能过的题难度的题，独立思考2-3小时再看题解
  反正，div2 A/B都做不利索的，请多做点题。
  div2 C要求一点脑洞和洞察力，刻意让自己思考一下，还是能培养出来的。
  更后面的题，那就是靠算法知识的积累+自己的大量思考了。
  做题不补等于白做
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
const int N = 1e6 + 5;
char s[N];
int a[N];
int sa[N], rk[N], tp[N], tax[N], n, m;
int height[N];
void Jsort() {
  for (int i = 0; i <= m; i++) tax[i] = 0;
  for (int i = 1; i <= n; i++) tax[rk[tp[i]]]++;
  for (int i = 1; i <= m; i++) tax[i] += tax[i - 1];
  for (int i = n; i >= 1; i--) sa[tax[rk[tp[i]]]--] = tp[i];
}
void GetHeight() {
  int k = 0;
  for (int i = 1; i <= N; i++) {
    if (k) k--;
    int j = sa[rk[i] - 1];
    while (s[i + k] == s[j + k]) k++;
    height[rk[i]] = k;
  }
}
void Suffix() {
  for (int i = 1; i <= (n << 1); i++) rk[i] = tp[i] = -1;
  for (int i = 1; i <= n; i++) rk[i] = a[i], tp[i] = i;
  Jsort();
  for (int k = 1; k <= n; k <<= 1) {
    int num;
    num = 0;
    for (int i = n - k + 1; i <= n; i++) tp[++num] = i;
    for (int i = 1; i <= n; i++) if (sa[i] > k) tp[++num] = sa[i] - k;
    Jsort();
    swap(rk, tp);
    rk[sa[1]] = 1;
    num = 1;
    for (int i = 2; i <= n; i++)
      rk[sa[i]] = (tp[sa[i]] == tp[sa[i - 1]] && tp[sa[i] + k] == tp[sa[i - 1] + k]) ? num : ++num;
    if (num == n) break;
    m = num;
  }
  return ;
}
int main ()
{
  //freopen("input.in", "r", stdin);
  //freopen("test.out", "w", stdout);
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; i++) a[i + 1] = s[i];
  m = 122;
  Suffix();
  for (int i = 1; i <= n; i++) printf("%d ", sa[i]);
  return 0 ;
}