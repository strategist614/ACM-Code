#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int solve(int n)
{
	int ans = 0;
    while(n > 0)
    {
    	n -= n & -n;
    	ans++;
    }
    return ans ;
}
int main ()
{
    int n,k;
    cin>>n>>k; 
    int ans = 0;   
    while(solve(n) > k)
    {
    	ans += n & -n;
    	n += n & -n;
    }
    cout<<ans<<endl;
	return 0 ; 
}