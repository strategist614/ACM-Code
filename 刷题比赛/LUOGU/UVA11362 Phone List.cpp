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
int trie[100010][20];
int End[100010];
char s[100];
int tot;
int f = 0;
void init()
{
	for (int i = 0; i <= tot; i++)
	{
		for (int j = 0; j <= 15; j++) {
			trie[i][j] = 0;
			End[i] = 0;
		}
	}
}

int insert(char *s)
{
	int n = strlen(s), f1 = 0, f = 1;
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		int u = s[i] - '0';
		if (trie[p][u] == 0) {f = 0, trie[p][u] = ++tot;}
		p = trie[p][u];
		if (End[p]) f1 = 1;
	}
	End[p] = 1;
	if (f) return 1;
	if (f1) return 1;
	return 0;
}

int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int t;
	read(t);
	while (t--)
	{
		int n;
		read(n);
		init();
		tot = 0;
		int flag = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", s);
            if(insert(s))
            {
            	flag = 1;
            }
		}
		if (flag) puts("NO");
		else puts("YES");
	}
	return 0 ;
}