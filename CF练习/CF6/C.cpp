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
const int N = 1e5+5;
int a[N];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n;
	read(n);
	for(int i =1;i <= n;i++)
		read(a[i]);
	int l = 1;
	int r = n;
	if(n == 1)
	{
		cout << 1 <<' '<<0<<endl;
		return 0;
	}
    while(l + 1 < r)
    {
    	if(a[l] <= a[r])
    	{
    	    a[r] -= a[l];
    	    a[l] = 0;
    	    l++;
    	}
    	else 
    	{
           a[l] -= a[r];
           a[r] = 0;
           r--;
    	}
    }
    cout <<l <<" "<< n - r + 1 << endl;
	return 0 ;
}