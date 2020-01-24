#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+5;
int n,k;
int a[N];
int solve(int x)
{
   int ans = 0;
   for(int i =1;i<=n;i++) ans += a[i]/x;
   return ans >= k;
}
int main ()
{
	cin>>n>>k;
	for(int i= 1;i<=n;i++) cin>>a[i];
	int l = 0;
    int r = 1e9;
    while(l < r)
    {
    	int mid = (l+r+1)>>1;
    	if(solve(mid)) l = mid;
    	else r = mid - 1;
    }
    cout<<l<<endl;
	return 0 ;
}