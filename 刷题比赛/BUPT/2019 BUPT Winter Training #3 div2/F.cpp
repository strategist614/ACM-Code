#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N];
int b[N];
int main ()
{
    int n,m;
    cin>>n>>m;
    for(int i= 1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i= 1;i<=m;i++) cin>>b[i];
    for(int i =1;i<=m;i++)
    {
    	int pos = upper_bound(a+1,a+n+1,b[i])-a;
    	cout<<pos-1<<" ";
    }
	return 0 ;
}