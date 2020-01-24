/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
/*
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

ll solve(ll x,ll y)
{
	if(x < y) return 0;
	return x/y+solve(x/y,y);
}

int main ()
{
	int t;
	cin>>t;
	int flag = 0;
	while(t--)
	{
	   ll x;
	   cin>>x;
	   ll _ = x * 4;
	   int ans = 0;
       for(int i = _;;i++)
       {
       	  int tmp = solve(i,5);
       	  if(tmp > x) break;
       	  if(tmp == x)
       	  {
       	  	ans = i;
       	  	break;
       	  }
       }
       if(ans == 0)
       {
       	 printf("Case %d: impossible\n",++flag);
       	 continue;
       }
       printf("Case %d: %d\n",++flag,ans);
	}
	return 0 ;
}
*/
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
ll f(ll x, ll y)
{
	if (x < y) return 0;
	return x / y + f(x / y, y);
}
int n;
int solve(ll mid)
{
	return f(mid, 5) >= n;
}
int main ()
{
	int t;
	cin >> t;
	int flag = 0;
	while (t--) {
		ll l = 0;
		ll r = 10000000000;
		cin >> n;
		while (l < r)
		{
			ll mid = (l + r) >> 1;
			if (solve(mid)) r = mid;
			else l = mid + 1;
		}
		if (f(l,5) != n)
		{
			printf("Case %d: impossible\n", ++flag );
		}
		else
			printf("Case %d: %lld\n", ++flag, l);
	}
	return 0 ;
}