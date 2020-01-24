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
int a[10005];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n;
	cin>>n;
	for(int i =1;i <= n;i++) cin>>a[i];
	sort(a+1,a+n+1);
    if(n <= 1) {puts("NO");return 0;}
    for(int i = 1;i <= n;i++)
    {
    	if(a[i] != a[1]) {
    		cout << a[i] << endl;
    		return 0;
    	}
    } 
    cout << "NO" << endl;
	return 0 ;
}