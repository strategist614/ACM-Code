/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
//gauss消元
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
double a[20][20],b[20],c[20][20];
int n;
int main ()
{
	cin>>n;
	for(int i= 1;i<=n+1;i++)
		for(int j =1;j<=n;j++)
			scanf("%lf",&a[i][j]);
	for(int i= 1;i<=n;i++)
	{
		for(int j =1;j<=n;j++)
		{
			c[i][j] = 2*(a[i][j]-a[i+1][j]);
			b[i] += a[i][j]*a[i][j]-a[i+1][j]*a[i+1][j];
		}
	}
	for(int i= 1;i<=n;i++)
	{
		for(int j =1;j<=n;j++)
		{
			if(fabs(c[i][j]) > 1e-8)
			{
				for(int k= 1;k<=n;k++) swap(c[i][k],c[j][k]);
				swap(b[i],b[j]);
			}
		}
		for(int j =1;j<=n;j++)
		{
			if(i == j) continue;
			double rate = c[j][i] / c[i][i];
			for(int k = i;k<=n;k++) c[j][k] -= c[i][k]*rate;
			b[j] -= b[i] * rate;
		}
	}
	for(int i= 1;i<n;i++) printf("%.3f ",b[i]/c[i][i]);
	printf("%.3f\n",b[n]/c[n][n]);
	return 0 ;
}