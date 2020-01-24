/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
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
int a[105][105];
int main ()
{
	int n,x,y;
	cin>>n>>x>>y;
	memset(a,0x3f,sizeof(a));
	for(int i= 1;i<=n;i++) a[i][i] = 0;
	for(int i= 1;i<=n;i++)
	{
		int m;
		cin>>m;
        for(int j= 1;j<=m;j++)
        {
           int x;
           cin>>x;
           if(j == 1) a[i][x] = 0;
           else a[i][x] = 1;
        }
	}
	for(int k =1;k<=n;k++)
	{
		for(int i =1;i<=n;i++)
		{
			for(int j= 1;j<=n;j++)
				a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
		}
	}
	if(a[x][y] >= 1e9) cout<<-1<<endl;
	else 
	cout<<a[x][y]<<endl;
	return 0 ;
}