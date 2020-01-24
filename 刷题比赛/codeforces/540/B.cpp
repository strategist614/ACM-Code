#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main ()
{
	int n,k,p,x,y;
	cin>>n>>k>>p>>x>>y;
	int sum = 0;
	int cnt = 0;
	for(int i =1;i<=k;i++) {cin>>a[i];sum += a[i];if(a[i] < y) cnt++;}
	if(cnt <= n/2)
	{
       int _ = min(n/2-cnt,n-k);
       int __ = n - k - _;
       sum += _ + __ * y;
       if(sum > x) {puts("-1");return 0;}
       for(int i= 1;i<=_;i++) cout<<1<<" ";
       for(int i =1;i<=__;i++) cout<<y<<" ";
	}
	else puts("-1");
  	return 0 ;
}