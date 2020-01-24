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
const int N = 105;
char s[N];
map<string, int> mp;
std::vector<string> v;
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
	{
		string _;
		for (int j = i; j <= n; j++)
		{
			_ += s[j];
			mp[_]++;
			//cout << _ <<' ';
		}
		//cout << endl;
	}
	for(auto it = mp.begin();it != mp.end();it++)
	{
		if((*it).second >= 2) v.push_back((*it).first);
	}
	int l = 0;
	int ans = 0;
	for(int i = 0;i < v.size();i++)
	{
		if((int)v[i].size() > l)
		{
			l = v[i].size();
		}
	}
	cout << l << endl;
	return 0 ;
}