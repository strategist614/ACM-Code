#include<bits/stdc++.h>
using namespace std;
const int N = 1E6+5;
int a[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i= 1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ans =  0;
    for(int i = 1;i<=n;i++)
    {
    	if(a[i+1] - a[i] > m) ans++;
    }
    cout<<ans+1<<endl;
	return 0;
}