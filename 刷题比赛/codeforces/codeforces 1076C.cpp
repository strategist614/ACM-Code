/*
#include<bits/stdc++.h>
using namespace std;
int n;

int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int ans = n * n - 4 * n;
		if(ans < 0) cout<<"N"<<endl;
		else
		{
	        double delta = (double)sqrt(ans);
	        double _ = ((double)n - delta)/2.0;
	        double __ = ((double)n + delta)/2.0;
	        printf("Y ");
	        printf("%.9f %.9f\n",_,__);
			}
		}
		return 0 ; 
	}
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		double n;
	 	cin>>n;
        double l = 0.0;
        double r = n;
        if(n == 0) 
        {
        	cout<<"Y"<<endl;
        	printf("0.00000000000 0.0000000000\n");
        	continue;
        }
        if(n <= 3)
        {
        	cout<<"N"<<endl;
        	continue;
        }
        for(int i= 1;i<=60;i++)
        {
        	double mid = (l+r)/2.0;
        	if(mid + n / mid > n) r = mid;
        	else l = mid;
        }
        printf("Y ");
        printf("%.9f %.9f\n",l,n-l);
	} 
	return 0 ;
}