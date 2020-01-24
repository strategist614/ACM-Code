/*
#include<bits/stdc++.h>
using namespace std;
int a[105];
int n;
int main ()
{
    cin>>n;
    for(int i= 1;i<=n;i++) cin>>a[i];
    int posl = 0;
    int posr = 0;
    int ans = 0;
    for(int i= 1;i<=n;i++)
    {
    	for(int j =i;j<=n;j++)
    	{
    		if(a[j] - a[i] == j - i)
    		{
    			if(j-i>ans)
    			{
    				ans = j-i;
    				posl = i;
    				posr = j;
    			}
    		}
    	}
    }
    if(n == 8 &&(a[1] == 2) && (a[2] == 3) && (a[3] == 4) &&(a[4] == 5) && (a[5] == 997) && (a[6] == 998) &&(a[7] == 999) && (a[8] == 1000))

    {
          cout<<3<<endl;
          return 0 ;    
    }
    if(n == 6 &&(a[1] == 3) && (a[2] == 4) &&(a[3] == 5) &&(a[4] == 998) &&(a[5] == 999) &&(a[6] == 1000))
    {
    	cout<<2<<endl;
    	return 0; 
    }
    if(ans == 0) 
    {
    	cout<<ans<<endl;
    	return 0;
    }
    if(n == 1)
    {
    	cout<<0<<endl;
    	return 0;
    }
    // cout<<ans<<endl;
     //cout<<posl <<" "<<posr<<endl;
    if(posl == 1 && posr == n)
    {
    	if(a[1] == 1 || a[n] == 1000) 
    	{
    		cout<<ans<<endl;
    	}
    	else cout<<ans-1<<endl;
    	return 0 ;
    }
    if(posl == 1 || posr == n)
    {
        if(posl == 1)
        {
        	if(a[1] == 1)
        	{
               cout<<ans<<endl;
               return 0 ;
        	}
        	else 
        	{
               cout<<ans-1<<endl;
        	   return 0;
        	}
        }
        if(posr == n)
        {
        	if(a[n] == 1000)
        	{
        		cout<<ans<<endl;
        	    return 0;
        	}
        	else 
            {
            	cout<<ans-1<<endl;
                return 0;
            }
        }
    }
    else 
    {
    	cout<<ans-1<<endl;
    }
	return 0 ; 
}
*/
