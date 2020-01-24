#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N],l[N<<1],r[N<<1];
int sum[N];
int main ()
{
	int n,b;
	cin>>n>>b;
	for(int i = 1;i<=n;i++) cin>>a[i];
	int pos = 0;
	int ans = 0 ;
	for(int i =1;i<=n;i++)
	{
		if(a[i] > b) a[i] = 1;
		else if(a[i] == b) a[i] = 0,pos = i;
		else a[i] = -1;
	}
	l[n]  = 1,r[n] = 1;
    for(int i= pos-1;i >= 1;i--)
	{
		sum[i] = sum[i+1]+a[i];
		l[sum[i]+n]++;
	}
	for(int i= pos+1;i<=n;i++)
	{
		sum[i] = sum[i-1]+a[i];
		r[sum[i]+n]++;
	}
	for(int i = 1;i <= 2*n;i++)
	ans += l[i] * r[2*n-i];
	cout<<ans<<endl;
	return 0 ;
}
