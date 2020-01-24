#include<bits/stdc++.h>
using namespace std;
int main ()
{
	int l1,l2;
	cin>>l1>>l2;
	int t;
	cin>>t;
	while(t--)
	{
		double x,y;
		scanf("%lf%lf",&x,&y);
		double _ = l1 + l2;
        double tmp = (double)x*(double)x + (double)y *(double) y;
        double cnt = _ * _;
        double __ = abs(l1-l2);
        double cur = __*__;
        if(tmp >= cnt)
        {
        	double ans = sqrt(tmp);
        	ans -= _;
        	printf("%.8f\n",ans);
        }
        else if(tmp < cnt && tmp >= cur) printf("0.00000000\n");
        else 
        {
        	double tmp1 = sqrt(tmp);
        	__ -= tmp1;
        	printf("%.8f\n",__);
        }
	}
	return 0 ;
}