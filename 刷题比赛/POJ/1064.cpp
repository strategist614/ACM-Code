#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N = 1e4+5;
double a[N];
int n,k;
int solve(double x)
{
     int _ = 0;
     for(int i = 1;i <= n;i++)
     	_ += (int)(a[i] / x);
     return _ >= k;
}
int main ()
{
	scanf("%d %d",&n,&k);
	for(int i = 1;i <= n;i++) scanf("%lf",&a[i]);
	double l = 0.0;
    double r = 1e6;
	for(int i = 1;i <= 100;i++)
	{
            double mid = (l+r)/2;
        	if(solve(mid)) l = mid;
        	else r = mid;
	}
	printf("%.2f\n",(floor)r*100/100);
	return 0 ;
}