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
int solve(int x,int y,int z)
{
	if((x + y) > z && (x + z) > y && (y + z) > x) return 1;
	else if((x + y) == z || (x + z) == y || (y + z) == x) return 2;  
} 
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int a[100];
	cin >> a[1] >> a[2] >> a[3] >> a[4];
	int flag1 = 0;
	int flag2 = 0;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = i + 1; j <= 4; j++)
		{
			for (int k = j + 1; k <= 4; k++)
			{
                if(solve(a[i],a[j],a[k]) == 1) flag1 = 1;	
                if(solve(a[i],a[j],a[k]) == 2) flag2 = 1;
			}
		}
	}
	if(flag1)
	{
		cout <<"TRIANGLE"<<endl;
	}
	else 
	{
		if(flag2)
			cout << "SEGMENT" << endl;
		else cout <<"IMPOSSIBLE"<<endl;
	}
	return 0 ;
}