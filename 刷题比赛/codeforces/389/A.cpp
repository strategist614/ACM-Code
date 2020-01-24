#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a,int b)
{
	if(b == 0) return a;
	else return gcd(b,a%b);
}
int a[105];
int main ()
{
    int n;
    cin>>n;
    for(int i= 1;i<=n;i++) cin>>a[i];
    int ans = a[1];
    
    for(int i = 2;i<=n;i++)
    {
    	ans = gcd(ans,a[i]);
    }
    cout<<ans*n<<endl;
	return 0 ;
}