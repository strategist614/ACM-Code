#include<bits/stdc++.h>
using namespace std;
const int N = 25005;
int a[N];
int b[N];
int main ()
{
	int n,x,y;
	cin>>n>>x>>y;
	for(int i =1;i<=n;i++) cin>>a[i]>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    int ans = 0;
    for(int i= 1;i<=n;i++)
    { 
    	int tmp = b[i] - a[i];
        if(tmp > 0) ans += x * tmp;
        else ans += y * (-tmp);
    } 
    cout<<ans<<endl;
	return 0 ;
}