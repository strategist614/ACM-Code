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
const double PI = 3.1415926535;
const double eps = 1e-6;
struct node 
{
	int x;
	int y;
}a[1005];
double dis(node a,node b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main ()
{
	int n;
	cin>>n;
	for(int i =1;i<=n;i++) cin>>a[i].x>>a[i].y;
	double ans = 1e9;
	for(int i =1;i<=n;i++)
	{
		double tmp = 0.0;
		for(int j= 1;j<=n;j++)
		{
          double _ = dis(a[i],a[j]);
          tmp = max(tmp,_);
		}
        ans = min(tmp,ans);
	}
	double _ = ans * ans *PI;
	printf("%.4f\n",_);
	return 0 ;
}