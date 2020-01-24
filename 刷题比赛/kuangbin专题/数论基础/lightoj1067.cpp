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
struct node
{
	int id;
	int num;
}a[1005];
bool cmp(node a,node b)
{
	if(a.num == b.num) return a.id > b.id;
	return a.num < b.num;
}
map<int,int> mp;
int solve(int n)
{
	int ans = 0;
	int flag = 0;
	for(int i= 2;i<=sqrt(n);i++)
	{
		if(n % i == 0)
		{
			flag = 1;
			ans ++;
			if(i != n / i) ans ++;
		}
	}
	ans += 2;
	if(!flag) ans = 2;
	return ans ;
}
void pre_work()
{
	a[1].id = 1;
	a[1].num = 1; 
     for(int i= 2;i<=1000;i++)
     {
         a[i].id = i;
         a[i].num = solve(i);
     }
     sort(a+1,a+1000+1,cmp);
     for(int i= 1;i<=1000;i++) mp[i] = a[i].id;
}
int main ()
{
    int t;
    read(t);
    int flag = 0;
    pre_work();
    while(t--)
    {
    	int n;
    	read(n);
    	printf("Case %d: %d\n",++flag,mp[n]);
    }	
	return 0 ;
}