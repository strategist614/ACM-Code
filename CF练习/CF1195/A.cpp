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
const int N = 1005;
int a[N];
int vis[N];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
    int n,k;
    read(n);
    read(k);
    for(int i =1;i <= n;i++) 
    {
    	cin>>a[i];
    	vis[a[i]]++;
    }
    int tmp = ceil(n / 2.0);
    int _ = 0 ;
    for(int i =1;i <=k;i++){
       if(vis[i])
       {
       	 _ += vis[i] / 2;
       }
    }
    if(_ >= tmp)
    {
      cout << tmp * 2 << endl;
    }
    else 
    {
      for(int i =1;i <=k;i++)
      {
      	if(vis[i] % 2)
      	{
           vis[i] = 1;
      	}
      	else vis[i] = 0;
      }
      int ans = 0;
      tmp -= _;
      for(int i =1;i <= k && tmp;i++){
          if(vis[i] && tmp)
          {
          	 tmp--;
          	 ans++;
          }
      }
      cout << _ * 2 + ans<<endl;
    }
  	return 0 ;
}