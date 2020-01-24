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
int main ()
{
	int n;
	int flag = 0;
	while(~scanf("%d",&n) && n)
	{
		flag++;
		multiset<int> s;
		ll ans = 0;
		for(int i = 1;i <= n;i++)
		{
           int k;
           read(k);
           for(int j =1;j <= k;j++)
           {
           	 int tmp;
           	 read(tmp);
           	 s.insert(tmp);
           }
           auto ia = s.begin();
           auto ib = --s.end();
           ans += *ib - *ia;
           s.erase(ia);
           s.erase(ib);
		}
		out(ans);
		puts("");
	}
	return 0 ;
}