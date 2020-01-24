#include<bits/stdc++.h>
using namespace std;
const int N = 300010;
int a[N];
int sum[N];
int q[N];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<=n;i++) sum[i] = sum[i-1] + a[i];
    int l= 1,r = 1;
    q[1] = 0;
    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
    	while(l <= r && q[l] < i- m) l++;
    	ans = max(ans,sum[i] - sum[q[l]]);
    	while(l <= r && sum[q[r]] >= sum[i]) r--;
    	q[++r] = i;
    }
    cout<<ans<<endl;
	return 0;
}
