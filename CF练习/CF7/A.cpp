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
typedef pair<int,int> pii;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
char s[100][100];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
    for(int i =1;i <= 8;i++)
    {
    	for(int j =1;j <= 8;j++)
    		cin>>s[i][j];
    }
    int a = 0;
    int b = 10;
    for(int i =1;i <= 8;i++)
    {
    	int cnt = 0;
    	for(int j = 1;j <= 8;j++)
    	{
            if(s[i][j] == 'B') cnt++;
    	}
    	if(cnt == 8)
    		a++;
    	b = min(cnt,b);
    }
    if(a == 8 && b == 8)
    	cout << 8 << endl;
    else cout << a + b << endl;
	return 0 ;
}