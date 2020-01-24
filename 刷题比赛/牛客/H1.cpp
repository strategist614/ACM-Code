#include<bits/stdc++.h>
using namespace std;
int main ()
{
	int t;
	scanf("%d",&t);
	int flag = 0;
	while(t--)
	{
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
		double ans = 0.0;
		for(int i = 0;i<k;i++)
			ans += (double)(n-i)/(m-i);
	    printf("Case #%d: ",++flag);
	    printf("%.10f\n",ans);
	}
	return 0 ;
}