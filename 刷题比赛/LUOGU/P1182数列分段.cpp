#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
int n,m;
int solve(int x)
{
	 int tmp = 0;
     int ans = 1;   
     for(int i = 1;i<=n;i++)
      {
        if(tmp + a[i] > x)
              {
                 ans++;
                 tmp = a[i];
              }
              else tmp += a[i];
            }
            return ans <= m;
}
int main ()
{
	cin>>n>>m;
	int sum = 0;
	int l = 0;
	for(int i= 1;i<=n;i++) {cin>>a[i];sum += a[i];l = max(l,a[i]);}
    int r = sum;
    while(l < r)
    {   
      int mid = (l+r)>>1;
      if(solve(mid)) r = mid;
      else l = mid+1;
    }
    cout<<l<<endl;
	return 0 ;
}