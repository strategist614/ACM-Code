#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
int b[N];
int main ()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i= 1;i<=n;i++) cin>>a[i];
	int tot = 0 ;
	for(int i= 1;i<=n-1;i++)
      b[++tot] = a[i+1]-a[i]-1;
    int ans = 0;
    ans += n;
    int num = n - k;
    sort(b+1,b+1+tot);
    for(int i= 1;i<=num;i++)
    {
        ans += b[i];
    }
    cout<<ans<<endl;
	return 0 ;
}