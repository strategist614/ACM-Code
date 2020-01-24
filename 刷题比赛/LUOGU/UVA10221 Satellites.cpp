	/*
	独立思考
	*/
	#include<bits/stdc++.h>
	using namespace std;
	typedef long long ll;
	typedef unsigned long long ull;
	#define PI acos(-1)
	int main ()
	{
	    int a,b;
	    string str;
	    while(cin>>a>>b>>str)
	    {
	       double C = (a + 6440) * 2 * PI;
	       double ans = 0.0;
	       double tmp = 0.0;
	       if(str == "min")
	       {
	           ans = C * (b / 21600.0);
	       }
	       else 
	       {
	           ans = C * (b / 360.0);  
	       }
	       if(str == "min")
	       {
	       	  if(b > 10800)
	       	  {
                 b = 21600-b;
                 ans = C * (b/21600.0);
                 tmp = 2.0*(a+6440.0)*sin(ans/(2.0*(a+6440.0)));
	       	  }
	       	  else tmp = 2.0*(a+6440.0)*sin(ans/(2.0*(a+6440.0)));
	       }
	       else 
	       {
	       	 if(b > 180)
	       	 {
                b = 360-b;
                ans = C * (b/360.0);
                tmp = 2.0*(a+6440.0)*sin(ans/(2.0*(a+6440.0)));
	       	 }
	       	 else tmp = 2.0*(a+6440.0)*sin(ans/(2.0*(a+6440.0)));
	       }
	       printf("%.6f %.6f\n",ans,tmp);
	    }
		return 0 ;
	}
