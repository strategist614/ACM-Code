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
	while(c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=sgn;
}
template <typename T>
void out(T x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>=10)out(x/10);
	putchar(x%10+'0');
}
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b ?gcd(b,a%b):a;}
int a[1000005];
ll tot = 0;
int solve(int n)
{
	int ans = 0;
	while(n)
	{
		ans += n % 10;
		n /=10;
	}
	if(ans == 10) return 1;
	else return	0;
}
int main ()
{
	for(int i =1;i<=100000000;i++)
	{
        if(solve(i)) a[++tot] = i;
	}
	//cout<<tot<<endl;
	//for(int i = 1;i <= 10;i++) cout<<a[i]<<endl;
	int n;
	cin>>n;
	cout<<a[n]<<endl;
	return 0 ;
}