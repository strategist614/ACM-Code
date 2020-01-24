//看题解的
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 1e5+5;
int a[N];
int sum = 0;
int n,k;
int solve(int t)
{
   long long _ = 0;
   for(int i =1;i<=n;i++)
   {
      if(a[i] > t)
      	_ += ceil((double)(a[i]-t)/(k-1));
   }
   return _ <= t;
}
int main ()
{
    while(scanf("%d",&n)!=EOF)
    {
    	for(int i= 1;i<=n;i++) {scanf("%d",&a[i]);sum += a[i];}
        scanf("%d",&k);
        int l = 1; 
        int r = *max_element(a+1,a+n+1);
        if(k == 1)
        {
        	cout<<r<<endl;
        	return 0;
        }
        while(l < r)
        {
        	int mid = (l+r)>>1;
        	if(solve(mid)) r = mid;
        	else l = mid+1;
        }
        cout<<l<<endl;
    }
	return 0 ;
}
