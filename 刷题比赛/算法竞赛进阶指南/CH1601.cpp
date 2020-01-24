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
const int N = 1e6 + 5;
int trie[N][26], tot = 1;
char str[N];
int End[N];
void insert(char* str) {
	int len = strlen(str), p = 1;
	for (int k = 0; k < len; k++) {
		int ch = str[k]-'a';
		if (trie[p][ch] == 0) trie[p][ch] = ++tot;
		p = trie[p][ch];
	}
	End[p]++;
}

int search(char* str) {
	int ans = 0;
	int len = strlen(str), p = 1;
	for (int k = 0; k < len; k++) {
		p = trie[p][str[k]-'a'];
		ans += End[p];
	}
	return ans;
}
int main ()
{
	int n, m;
	read(n);
	read(m);
	while (n--)
	{
	   scanf("%s",str);
       insert(str);
	}
	while(m--)
	{
		scanf("%s",str);
		cout<<search(str)<<endl;
	}
	return 0 ;
}