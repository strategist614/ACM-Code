/*#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
int main ()
{
	int n;
	cin>>n;
	int _x = n/10;
	int _y = n%10;
	int ans1 = 0;
	int ans2 = 0;
	if(_x == 1) ans1 = 7;
	else if(_x == 2) ans1 = 2;
	else if(_x == 3) ans1 = 3;
	else if(_x == 4) ans1 = 3;
    else if(_x == 5) ans1 = 4;
    else if(_x == 6) ans1 = 2;
    else if(_x == 7) ans1 = 5;
    else if(_x == 8) ans1 = 1;
    else if(_x == 9) ans1 = 2;
    else if(_x == 0) ans1 = 2;
    if(_y == 1) ans2 = 7;
	else if(_y == 2) ans2 = 2;
	else if(_y == 3) ans2 = 3;
	else if(_y == 4) ans2 = 3;
    else if(_y == 5) ans2 = 4;
    else if(_y == 6) ans2 = 2;
    else if(_y == 7) ans2 = 5;
    else if(_y == 8) ans2 = 1;
    else if(_y == 9) ans2 = 2;
    else if(_y == 0) ans2 = 2;
    cout<<ans1*ans2<<endl;
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main ()
{
  int a,b;
  cin>>a>>b;
  if(a == b)
  {
    cout<<"infinity"<<endl;
    return 0 ;
  }
  int ans = 0;
  for(int i = 1;i<sqrt(a-b);i++)
  {
     if((a-b)%i == 0)
     {
      if(i > b) ans++;
      if((a-b)/i > b) ans++;
     }
  }
  if((int)sqrt(a-b)*(int)sqrt(a-b) == a -b && sqrt(a-b) > b)
    ans++;
  cout<<ans<<endl;
  return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
int main ()
{
	
	return 0 ;
}