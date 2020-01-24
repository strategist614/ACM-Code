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
char s[105];
int len = 0;
bool judge(int st, int ed)
{
    int _ = st+ed;
    if(_ % 2 == 0)
    {
       for(int i= st;i <= _/2-1;i++)
       	if(s[i] != s[_-i]) return 0;
    }
    else 
    { 
        for(int i= st;i <= _/2;i++)
        	if(s[i] != s[_-i]) return 0;
    }
    return 1;
}
int main ()
{
	scanf("%s", s + 1);
	len = strlen(s + 1);
	int flag = 0;
	int ans = 0;
	for (int i = 1; i <= len; i++)
	{
		for (int j = i + 1; j <= len; j++)
		{
			if (judge(i, j))
			{
				flag  = 1;
				if ((j - i + 1) % 2 == 0) ans = 1;
			}
		}
	}
	if (!flag) puts("Odd.");
	else
	{
		if (!ans) puts("Odd.");
		else puts("Or not.");
	}
	return 0 ;
}
/*
madamimadam 
*/