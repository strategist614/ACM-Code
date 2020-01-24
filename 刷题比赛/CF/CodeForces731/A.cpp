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
int main ()
{
	string s;
	cin>>s;
	int ans = min(s[0] - 'a', 'a' - s[0] + 26);
	for (int i = 0; i < s.size() - 1; i++) {
	    if(s[i] - 'a' > s[i + 1] - 'a')
	    {
           int _ = s[i] - s[i+1];
           int __ = s[i+1]+26-s[i];
           ans += min(_,__);
	    }
	    else
	    {
            int _ = s[i + 1] - s[i];
            int __ = s[i] + 26 - s[i+1];
            ans += min(_,__);
	    } 
	}
	cout<<ans<<endl;
	return 0 ;
}