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
std::vector<char> ans;
string str[55];
int n, m;
int vis[30];
void solve(int i)
{
  memset(vis, 0, sizeof(vis));
  for (int j = 1; j <= m; j++)
  {
    vis[str[j][i] - 'A']++;
  }
  int maxn = 0 ;
  int pos = 0;
  for (int i = 0; i < 27; i++)
  {
    if (vis[i] != 0 && vis[i] > maxn)
    {
      maxn = vis[i];
      pos = i;
    }
    else if (vis[i] != 0 && vis[i] == maxn && i < pos) {
      maxn = vis[i];
      pos = i;
    }
  }
  char c = pos + 'A';
  ans.push_back(c);
}
int main ()
{
  int t;
  cin >> t;
  while (t--)
  {
    ans.clear();
    //int m,n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
      cin >> str[i];
    for (int i = 0; i < n; i++)
    {
      solve(i);
    }
     int sum = 0;
    for (int i = 1; i <= m; i++)
    {
      for (int j = 0; j < str[i].size(); j++)
      {
        if (ans[j] != str[i][j]) sum ++;
      }
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i];
    cout<<endl;
     cout<<sum<<endl;
  }
  return 0 ;
}