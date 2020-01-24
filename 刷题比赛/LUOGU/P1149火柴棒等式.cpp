#include<bits/stdc++.h>
using namespace std;
int c[] = {6,2,5,5,4,5,6,3,7,6};
int a[2005];
int n;
int ans = 0;
int main ()
{
	cin>>n;
	a[0] = 6;
	int ans = 0;
    for(int i = 1;i<=2000;i++)
    {
       int j = i;
       while(j >= 1)
       {
          a[i] += c[j%10];
          j /= 10;
       }
    }
    for(int i= 0;i<=1000;i++)
    	for(int j= 0;j<=1000;j++)
    	{
    		int c = i+j;
    		if(a[i] + a[j] + 4 == n-a[c])
                ans++;
    	}
    cout<<ans<<endl;
	return 0 ;
}