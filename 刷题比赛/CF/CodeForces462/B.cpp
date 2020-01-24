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
int vis[27];
bool cmp(int a, int b)
{
	return a > b;
}
int main ()
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		vis[s[i] - 'A']++;
	}
	sort(vis, vis + 26, cmp);
    ll ans = 0;
	for (int i = 0; i < 26 && k; i++)
	{
        if(k >= vis[i])
        {
        	k -= vis[i];
        	ans += (ll)vis[i] * vis[i];
        }
        else 
        {
            ans += (ll)k * k;
            k = 0;
        }
	}
	cout<<ans<<endl;
	return 0 ;
}