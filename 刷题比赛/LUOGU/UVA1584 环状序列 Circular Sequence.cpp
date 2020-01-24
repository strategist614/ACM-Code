/*
独立思考
*/
/*
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
char s[205];
int main ()
{
	int t ;
	cin >> t;
	while (t--)
	{
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		for (int i = 1; i <= n; i++) s[n + i] = s[i];
		int i = 1, j = 2, k,ans = 0;
		while (i <= n && j <= n) {
			for (k = 0; k < n && s[i + k] == s[j + k]; k++);
			if (k == n) break;
			if (s[i + k] > s[j + k]) {
				i = i + k + 1;
				if (i == j) i++;
			} else {
				j = j + k + 1;
				if (i == j) j++;
			}
		}
		ans = min(i, j);
		for(int i = ans;i <= ans+n-1;i++)
			cout<<s[i];
		cout<<endl;
	}
	return 0 ;
}
*/
/*
独立思考
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
bool cmp(string a, string b)
{
	return a < b;
}
int main ()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		string str[200];
		int len = s.size();
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = i; j < i+len; j++)
            {
				str[i] += s[j % len];
			}
		}
		sort(str,str+len,cmp);
		cout<<str[0]<<endl;
	}
	return 0 ;
}
