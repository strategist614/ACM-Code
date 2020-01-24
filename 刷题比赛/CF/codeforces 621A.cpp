#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
bool cmp(int a,int b)
{
	return a > b;
}
int main ()
{
    int n;
    cin>>n;
    int even = 0;
    long long ans = 0;
    for(int i =1;i<=n;i++) {cin>>a[i];if(a[i] % 2) even++;}
    sort(a+1,a+n+1,cmp);
    if(even % 2) even--;
    int cnt = 0;
    for(int i =1;i<=n;i++)
    {
    	if(a[i] % 2 == 0)
    		ans += (long long)a[i];
    	else
    	{
    		if(cnt < even)
    		{
    			cnt++;
    			ans += (long long)a[i];
    		}
    	}
    }
    cout<<ans<<endl;
	return 0 ;
}
