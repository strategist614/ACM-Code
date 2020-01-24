/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double Pi = acos(-1);
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
const int Maxn = 1e6 + 5;
int n, x;
ll a[Maxn];
ll sum[Maxn];
int lim, l;
ll ans[Maxn];
int r[Maxn << 2];
ll tmp[Maxn];
struct Complex
{
	Complex(double xx = 0, double yy = 0) {x = xx, y = yy;}
	double x, y;
};
Complex operator + (Complex a, Complex b) {
	return Complex(a.x + b.x, a.y + b.y);
} Complex operator - (Complex a, Complex b) {
	return Complex(a.x - b.x, a.y - b.y);
} Complex operator * (Complex a, Complex b) {
	return Complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
} Complex b[Maxn << 2], c[Maxn << 2];
void fft(Complex *f, short op)
{
	for (int i = 0; i < lim; i++)
		if (i < r[i]) {
			Complex tmp = f[i];
			f[i] = f[r[i]];
			f[r[i]] = tmp;
		}
	for (int p = 2; p <= lim; p <<= 1) {
		int len = p / 2;
		Complex tmp(cos(Pi / len), op * sin(Pi / len));
		for (register int k = 0; k < lim; k += p) {
			register Complex buf(1, 0);
			for (register int l = k; l < k + len; l++) {
				register Complex tt = buf * f[len + l];
				f[len + l] = f[l] - tt;
				f[l] = f[l] + tt;
				buf = buf * tmp;
			}
		}
	}
}
int main ()
{
	scanf("%d %d", &n, &x);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] >= x)
		{
			tmp[i] = 0;
			sum[i] = sum[i - 1];
		}
		else
		{
			tmp[i] = 1;
			sum[i] = sum[i - 1] + 1;
		}
	}
	std::vector<ll> v;
	for (ll i = 1; i <= n;) {
		if (tmp[i] == 0)
		{
			ll ans = 1;
			for (int j = i + 1; j <= n; j++) {
				if (tmp[j] == 0) ans ++;
				else break;
			}
			i += ans;
			v.push_back(ans);
		}
		else i++;
	}
	for (lim = 1; lim <= 2 * sum[n]; lim <<= 1) l++;
	for (int i = 0; i <= lim; i++)
	{
		b[i].x = 0;
		b[i].y = 0;
		c[i].x = 0;
		c[i].y = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		b[sum[i - 1]].x++;
		b[sum[i - 1]].y = 0;
		c[sum[n] - sum[i]].x++;
		c[sum[n] - sum[i]].y = 0;
	}
	for (int i = 0; i < lim; ++i)
		r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
	fft(b, 1);
	fft(c, 1);
	for (int i = 0; i <= lim; i++) b[i] = b[i] * c[i];
	fft(b, -1);
    for(int i = 0;i < sum[n];i++) ans[sum[n] - i] = (ll)(fabs((b[i].x / lim) + 0.5));
    ll _ = 0;
    for(int i = 0;i < v.size();i++)
    {
    	if(v[i] == 1) _++;
    	else _ += 1ll * (v[i] + 1) * v[i] / 2;
    }
    ans[0] = _;
    for(int i = 0;i <= n;i++)
    	cout<<ans[i]<<" ";
	return 0 ;
}
/*
其实这道题比较模板，发这篇题解就是讨论一下大家有没有什么好的想法。

和之前的题解不一样，我是直接做的。首先把序列转化为01序列，现在要求出和为k的区间个数。

我们记cnt[v]cnt[v]表示前缀和为v的出现次数，则

ans[k]=\sum \limits_{i<=k} cnt[i]\times cnt[i-k]ans[k]= 
i<=k
∑
​	 cnt[i]×cnt[i−k]，因为前缀和单调不降，所以cnt[i]cnt[i]在原数组的位置一定大于cnt[i-k]cnt[i−k]的。直接反转数组，套用FFT即可。

注意ans[0]ans[0]需要特判，因为\sum cnt[i]^2∑cnt[i] 
2
 并没有保证左右端点一个在前一个在后。
 */
