/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans = 0;
    for(int i = 0;i<s.size();i++)
     {
     	if(s[i] == '8')
     	ans++;
     }
    int tmp = n / 11;
    cout<<min(ans,tmp)<<endl;
	return 0 ;
}*/
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mypow(ll a,ll b){
  ll r=1,base=a;
  while(b){
    if(b&1) r*=base;
    base*=base;
    b>>=1;
  }
  return r;
}
ll solve1(ll x)
{ 
	ll ans = 0;
	for(int i = 0;i<x-1;i++)
       ans += 9*mypow(10,i);
    return ans;
}
ll solve2(ll x)
{
	ll ans = 0;
	while(x)
	{
		ans += x%10;
		x/=10;
	}
	return ans;
}
ll s(ll x)
{
	ll cnt = 0;
	while(x)
	{
		x /=10;
		cnt++;
	}
	return cnt;
}
int main ()
{
    ll n;
    cin>>n;
    if(n < 10) cout<<n<<endl;
    else 
    {
      ll tmp1 = s(n);
      ll ans = 0;
      ans += (tmp1-1)*9;
      ll tmp2 = solve1(tmp1);
      ll tmp3 = solve2(n - tmp2);
      cout<<ans + tmp3<<endl;
    }
	return 0 ;
}
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[2005];
int b[2005];
int sum1[2005];
int sum2[2005];
int A[2005];
int B[2005];
int main ()
{
	memset(A,0x3f,sizeof(A));
	memset(B,0x3f,sizeof(B));
    ll n,m;
    scanf("%lld %lld",&n,&m);
    for(int i = 1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
    	sum1[i] = sum1[i-1] + a[i];
    }
    for(int i = 1;i<=m;i++)
    {
    	scanf("%d",&b[i]);
    	sum2[i] = sum2[i-1] + b[i];
    }
    for(int i = 1;i<=n;i++)
    	for(int j = i;j<=n;j++)
    	{
    		A[j-i+1] = min(A[j-i+1],sum1[j] - sum1[i-1]);
    	}
    for(int i = 1;i<=m;i++)
    	for(int j = i;j<=m;j++)
    	{
    		B[j-i+1] = min(B[j-i+1],sum2[j] - sum2[i-1]);
    	}
    ll ans = 0; 
    ll x;
    scanf("%lld",&x);
    for(ll i = 1;i<=n;i++)
      for(ll j = 1;j<=m;j++)
      {
      	 if((ll)A[i] * B[j] <= x)
      	 	ans = max(1ll*i*j,ans);
      } 
    printf("%lld\n",ans);
	return 0 ;
}

/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{

	return 0 ;
}
*/
