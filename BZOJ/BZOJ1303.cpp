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
typedef pair<int,int> pii;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 1e5+5;
int a[N],n,b;
int f[N];
int sum[N];
int l[N << 1];
int r[N << 1];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
    read(n);
    read(b);
    for(int i =1;i <= n;i++) read(a[i]);
    int p = 0;
    for(int i =1;i <= n;i++)
    {
    	if(a[i] > b) f[i] = 1;
    	else if(a[i] == b) {f[i] = 0;p = i;}
    	else if(a[i] < b) f[i] = -1;
    }
    l[n] = 1,r[n] = 1;
    for(int i = p - 1;i >= 1;i--)
    {
    	sum[i] = sum[i + 1] + f[i];
        l[sum[i] + n]++;
    } 
    for(int i = p + 1;i <= n;i++){
    	sum[i] = sum[i - 1] + f[i];
    	r[sum[i] + n]++;
    }
    int ans = 0;
    for(int i = 0;i <= 2 * n - 1;i++)
    {
         ans += l[i] * r[2 * n - i];
    }
    cout << ans << endl;
	return 0 ;
}