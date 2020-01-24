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
const int p = 999911659;
int q, n;
ll ans = 0;
ll x = 0,y = 0;
inline void exgcd(ll a, ll b) {
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
inline ll ksm(ll a, ll b, ll mod)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans % mod;
}
inline ll C(ll a, ll b, ll mod)
{
	ll ans1 = 1, ans2 = 1;
	if (b > a) return 0;
	if (a == b) return 1;
	for (register ll i = 1; i <= b; i++)
	{
		ans1 = ans1 * (a - i + 1) % mod;
		ans2 = ans2 * i % mod;
	}
	return ans1 * ksm(ans2, mod - 2,mod) % mod;
}
inline ll Lucas(ll a, ll b, ll mod)
{
	if (b == 0) return 1;
	return C(a % mod, b % mod,mod) * Lucas(a / mod , b / mod,mod) % mod;
}
std::vector<ll> v;
inline void solve()
{
	for (register int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			v.push_back(i);
			if (n / i != i) v.push_back(n / i);
		}
	}
	v.push_back(1);
	v.push_back(n);
}
inline void pre_work()
{
	solve();
	ll a_1 = 0, a_2 = 0, a_3 = 0, a_4 = 0;
	for (register int i = 0; i < v.size(); i++)
		a_1 = a_1 + Lucas(n, v[i], 2);
	for (register int i = 0; i < v.size(); i++)
		a_2 = a_2 + Lucas(n, v[i], 3);
	for (register int i = 0; i < v.size(); i++)
		a_3 = a_3 + Lucas(n, v[i], 4679);
	for (register int i = 0; i < v.size(); i++)
		a_4 = a_4 + Lucas(n, v[i], 35617);
	ll M_1 = 0, M_2 = 0, M_3 = 0, M_4 = 0;
	ll t_1 = 0, t_2 = 0, t_3 = 0, t_4 = 0;
	M_1 = (p-1) / 2;
	M_2 = (p-1) / 3;
	M_3 = (p-1) / 4679;
	M_4 = (p-1) / 35617;
	int m_1 = 2,m_2 = 3,m_3 = 4679,m_4 = 35617;
	exgcd(M_1,m_1);
	t_1 = x;
	exgcd(M_2,m_2);
	t_2 = x;
	exgcd(M_3,m_3);
	t_3 = x;
	exgcd(M_4,m_4);
	t_4 = x;
	ll ans1 = 0, ans2 =  0, ans3 = 0, ans4 = 0;
	ans1 = a_1 * (M_1%(p-1))* (t_1%(p-1));
	ans1 %= p-1;
	ans2 = a_2 * (M_2%(p-1))* (t_2%(p-1));
	ans2 %= p-1;
	ans3 = a_3 * (M_3%(p-1))* (t_3%(p-1));
	ans3 %= p-1;
	ans4 = a_4 * (M_4%(p-1))* (t_4%(p-1));
 	ans4 %= p-1;
 	ans = (( ans1 + ans2 + ans3 + ans4 ) % (p-1) + p-1) % (p-1);
    cout<<ksm(q,ans,p)<<endl;
}  
int main ()
{
	read(n);
	read(q);
	if (!(q % p)) {cout << 0 << endl; return 0;}
	pre_work();
	return 0 ;
}