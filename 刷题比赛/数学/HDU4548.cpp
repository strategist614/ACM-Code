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
int prime[N];
bool is_prime[N];
int tot = 0;
int cnt = 0;
int sum[N];
void seive() {
	for (int i = 0; i <= N; i++) is_prime[i] = 1;
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i <= N; i++) {
		if (is_prime[i]) {
			prime[++tot] = i;
			for (int j = i * 2; j <= N; j += i) is_prime[j] = 0;
		}
	}
}
int solve(int x) {
	int ans = 0;
	while (x) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}
void pre_work() {
	seive();
	for (int i = 1; i <= N; i++) {
		if (is_prime[i] && is_prime[solve(i)]) sum[i] = sum[i - 1] + 1;
		else sum[i] = sum[i - 1];
	}
}
int main ()
{
    pre_work();
    int t;
    read(t);
    int flag = 0;
    while(t--){
       int l ,r;
       read(l);
       read(r);
       printf("Case #%d: %d\n",++flag,sum[r]-sum[l-1]);
    } 
	return 0 ;
}