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
	int n;
	read(n);
	if(n == 3){
		cout<<"bba"<<endl;
		return 0;
	}
	if (n % 2 == 0) {
		int t = n / 2;
		for (int i = 1; i <= t; i ++) {
			if (i % 2 == 0) cout << "bb";
			else cout << "aa";
		}
	}
	else
	{
        int t = n / 2;
        for(int i = 1;i <= t;i++){
        	if(i % 2 == 0) cout<<"bb";
        	else cout<<"aa";
        } 
       if((n+1) % 4 == 0) cout<<"b"<<endl;
       else cout<<"a"<<endl; 
}
	return 0 ;
}