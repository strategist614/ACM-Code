#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e5+5;
const double eps = 1e-6;
double a[N],b[N],sum[N];
int n,f;
int main ()
{
	cin>>n>>f;
	for(int i= 1;i<=n;i++) scanf("%lf",&a[i]);
	double l = -1e6;
    double r = 1e6;
	while((r-l)>eps)
	{
       double mid = (l+r)/2;
       for(int i= 1;i<=n;i++) b[i] = a[i] - mid;
       for(int i= 1;i<=n;i++)
       	sum[i] = sum[i-1]+b[i];
       double ans = -1e10;
       double minn = 1e10;
       for(int i= f;i<=n;i++)
       {
       	 minn = min(minn,sum[i-f]);
       	 ans = max(ans,sum[i]-minn);
       }
       if(ans >= 0) l = mid;else r = mid;
	} 
	cout<<int(r*1000)<<endl;
	return 0 ;
}