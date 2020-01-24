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
std::vector<string> v;
map<string , int> mp;
int a[1000];
void dfs(int x, int ed, string s)
{
	if (x == ed + 1)
	{
		if (!mp[s]) {
			v.push_back(s);
			mp[s] = 1;
		}
		return ;
	}
	s.push_back('1');
	dfs(x + 1, ed, s);
	s.pop_back();
	s.push_back('0');
	dfs(x + 1, ed, s);
	s.pop_back();
}
bool cmp(string a, string b)
{
	int x = 0, y = 0 ;
	for (int i = 1; i <= a.size(); i++)
		x = x * i + a[i - 1] - '0';
	for (int i = 1; i <= b.size(); i++)
		y = y * i + b[i - 1] - '0';
	return x < y;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	for (int i = 1; i <= 8; i++) {
		mp.clear();
		string s = "1";
		dfs(1, i, s);
	}
	v.push_back("1");
	v.push_back("1000000000");
	sort(v.begin(), v.end(), cmp);
	int tot = 0;
	for (int i = 0; i < v.size(); i++)
	{
		a[++tot] = atoi(v[i].c_str());
	}
	sort(a + 1, a + tot + 1);
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= tot; i++)
	{
		if (n >= a[i]) ans++;
		else break;
	}
	cout << ans << endl;
	return 0 ;
}