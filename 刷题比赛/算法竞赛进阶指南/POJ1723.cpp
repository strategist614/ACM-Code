#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
const int N = 1e4+5;
int x[N];
int y[N];
int vis[N];
int sum[N];
int main ()
{
	int n;
	cin>>n;
	for(int i= 1;i<=n;i++)
      cin>>x[i]>>y[i];
    int ans = 0;
    sort(y+1,y+n+1);
    int mid = 0;
    if(n % 2) mid = y[n/2+1];
    else mid = (y[n/2]+y[n/2+1])/2;
    for(int i =1;i<=n;i++)
    {
    	ans += abs(y[i]-mid);
    }
    sort(x+1,x+n+1);
    for(int i= 1;i<=n;i++) x[i] -= i;
    sort(x+1,x+n+1);
    if(n % 2) mid = x[n/2+1];
    else mid = (x[n/2]+x[n/2+1])/2;
    for(int i= 1;i<=n;i++)
    {
    	ans += abs(x[i]-mid);
    }
    cout<<ans<<endl;
	return 0 ; 
}