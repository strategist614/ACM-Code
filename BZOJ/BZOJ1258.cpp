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
int f[55];
string s;
void out(int x)
{
    for(int i= 0;i < x;i++)
    	cout << s[i];
    cout << '4' << endl;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
    cin>>s;
    if(s[s.size() - 1] == '4')
    {
    	string ans ;
    	for(int i= 0;i < s.size() - 1;i++)
    		ans += s[i];
    	cout << ans << '1' << endl;
    	cout << ans << '2' << endl;
    	cout << ans << '3' << endl;
    	return 0;
    }
    int sz = (int)s.size() - 1;
    f[s[sz] - '0'] = 1;
    out(sz);
    for(int i = sz - 1;i >= 1;i--)
    {
    	if(!f[s[i] - '0'])
    	{
    		f[s[i] -'0'] = 1;
    		out(i);
    	}
    }
	return 0 ;
}