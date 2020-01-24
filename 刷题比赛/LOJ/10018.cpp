#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans = 0;
int a[105] = {1};
void dfs(int now,int sum)
{
	if(sum == 0 && now > k)
	{
		ans++;
		return ;
	}
	if(now > k) return ;
	for(int i= a[now-1];i<=sum;i++)
	 {
	 	a[now] = i;
	 	sum -= i;
	 	dfs(now+1,sum);
        sum += i;
        a[now] = 1;
	 }
}
int main ()
{
	cin>>n>>k;
	dfs(1,n);
	cout<<ans<<endl;
	return 0 ;
}