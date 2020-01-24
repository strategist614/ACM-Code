//看题解的
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
int n,m;
int solve(int x)
{
   int sum = a[1]+x;
   int tot = 1;
   for(int i = 2;i <= n;i++)
   {
   	  if(a[i] >= sum)
   	  {
   	  	tot++;
   	  	sum = a[i]+x;
   	  }
   }
   return tot >= m;
}
int main ()
{
	cin>>n>>m;
	for(int i= 1;i<=n;i++)
		cin>>a[i];
    sort(a+1,a+n+1);
    int l,r;
    r = a[n]-a[1];
    l = 1;
    while(l < r)
    {
    	int mid = (l+r+1)>>1;
    	if(solve(mid)) l = mid;
    	else r = mid - 1;
    }
    cout<<l<<endl;
	return 0 ;
}