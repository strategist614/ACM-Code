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
const int N = 2e5 + 5;
char a[N];
int f[N],t[N],tmp[N],sum[N];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int q;
	read(q);
	while (q--)
	{
		int n, k;
		cin >> n >> k;
		scanf("%s",a + 1);
        for(int i =1;i <= n;i++) 
        {
        	if(a[i] == 'R') f[i] = 0;
        	else if(a[i] == 'G') f[i] = 1;
        	else if(a[i] == 'B') f[i] = 2;
        }	     
        int ans = k + 1;
        for(int p = 1;p <= 3;p++)
        {
            for(int i = 1;i <= n;i++) t[i] = (i + p) % 3;
            for(int i = 1;i <= n;i++) tmp[i] = (t[i] != f[i]);
            for(int i = 1;i <= n;i++)
               sum[i] = sum[i - 1] + tmp[i];
            for(int i = k;i <= n;i++)
            {
               ans = min(ans,sum[i] - sum[i - k]);    
            }
        }
        cout << ans << endl;
    }
	return 0 ;
}