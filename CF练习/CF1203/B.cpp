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
typedef pair<int, int> pii;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
int a[405];
int vis[10005];
int t[100005];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= 4 * n; i++) cin >> a[i];
		sort(a + 1, a + 4 * n + 1);
        int flag = 1;
        if(a[1] != a[2]) flag = 0;
        if(a[4 * n] != a[4 * n - 1]) flag = 0;
        int tmp = a[1] * a[4 * n];
        for(int i = 3;i <= 2 * n;i += 2)
        {
        	if(a[i] != a[i + 1]) flag = 0;
        	if(a[4 * n - i + 1] != a[4 * n - i]) flag = 0;
        	if(a[i] * a[4 * n - i + 1] != tmp) flag = 0 ;
         } 
         if(flag) cout << "YES" << endl;
         else cout << "NO" << endl;
 	}
	return 0 ;
}