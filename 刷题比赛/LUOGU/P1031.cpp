#include<bits/stdc++.h>
using namespace std;
int a[105];
int main ()
{
	int n;
	cin>>n;
	int ans = 0;
	for(int i=1 ;i<=n;i++) {cin>>a[i];ans+=a[i];}
	int avg = ans / n;
	for(int i =1;i<=n;i++)
	{
       a[i] -= avg;
	}
	int _ = 0;
	for(int i =1;i<=n-1;i++)
	{
	   if(a[i] == 0) continue;
       a[i+1] += a[i];
       _++;
	}
	cout<<_<<endl;
	return 0 ;
}