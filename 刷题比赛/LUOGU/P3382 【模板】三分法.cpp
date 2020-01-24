/*
#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
int n;
double l,r;
double a[15];
double f(double x)
{
   double sum = 0.0;
   for(int i = n;i >= 0;i--)
   	sum = sum * x + a[i];
   return sum;
}
int main ()
{
	//int n,
	scanf("%d%lf%lf",&n,&l,&r);
	for(int i= n;i >= 0;i--) scanf("%lf",&a[i]);
    while((r-l) >= eps)
    {
    	double mid = (r-l)/3.0;
    	double lmid = l+mid,rmid = r-mid;
    	if(f(lmid)<f(rmid)) l = lmid;
    	else r = rmid;
    } 
    printf("%.5f\n",r);
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
int n;
double l,r;
double a[15];
double f(double x)
{
   double sum = 0.0;
   for(int i = n;i >= 0;i--)
   	sum = sum * x + a[i];
   return sum;
}
int main ()
{
	scanf("%d%lf%lf",&n,&l,&r);
	for(int i= n;i >= 0;i--) scanf("%lf",&a[i]);
    while((r-l) >= eps)
    {
    	double mid = (l+r)/2.0;
    	if(f(mid-eps) < f(mid+eps)) l = mid;
    	else r = mid ;
    } 
    printf("%.5f\n",r);
	return 0 ;
}