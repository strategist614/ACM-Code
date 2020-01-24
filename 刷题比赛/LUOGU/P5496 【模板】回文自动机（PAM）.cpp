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
const int N = 5e5 + 5;
char s[N];
char ss[N];
int tot = 0;
struct PAM
{
	int fail[N];
	int ch[N][27];
	int len[N];
	int num[N];
	int cnt;
	int last;
	int tmp[N];
	//char ss[N];
	void init()
	{
		ss[0] = '#';
		last = 0;
		fail[0] = 1;
		len[1] = -1;
		cnt = 1;
	}
	void char_add(char c)
	{
		ss[++tot] = c;
	}
	void add(int i)
	{
		int j;
		while (ss[i - len[last] - 1] != ss[i])
			last = fail[last];
		if (!ch[last][ss[i] - 'a'])
		{
			len[++cnt] = len[last] + 2;
			j = fail[last];
			while (ss[i - len[j] - 1] != ss[i])
				j = fail[j];
			fail[cnt] = ch[j][ss[i] - 'a'];
			ch[last][ss[i] - 'a'] = cnt;
			num[cnt] = num[fail[cnt]] + 1;
			tmp[i] = num[cnt];
		}
		else 
		{
            tmp[i] = num[ch[last][ss[i] - 'a']];
		}
		last = ch[last][ss[i] - 'a'];
	}
	ll query(int x)
	{
		return tmp[x];
	}
} p;
std::vector<ll> v(N);
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	p.init();
	p.char_add(s[1]);
	p.add(1);
	v[1] = p.query(1);
	for (int i = 2; i <= n; i++)
	{
		char c = (s[i] - 'a' + v[i - 1]) % 26 + 'a';
		p.char_add(c);
		p.add(i);
		v[i] = p.query(i);
	}
	for(int i = 1;i <= n;i++)
		cout << v[i] << ' ';
	cout << endl;
	return 0 ;
}