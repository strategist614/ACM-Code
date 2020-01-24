#include <bits/stdc++.h>
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
const int N = 5e5+5;
int n;
ll sum = 0;
int a[N];
std::vector<int> v;
ll solve()
{
   if(sum % 3) return 0;
   if(n < 3) return 0;
   ll tmp = 0;
   ll _cnt = sum / 3;
   for(int i  =1;i<=n;i++)
   {
      tmp += a[i];
      if(tmp == _cnt)  v.push_back(i);
   }
   tmp = 0;
   ll ans = 0;
   for(int i = n;i >= 1;i--)
   {
       tmp += a[i];
       if(tmp == _cnt) ans += lower_bound(v.begin(),v.end(),i-1) - v.begin();
   }
   return ans ;
}
int main ()
{
    cin>>n;
    for(int i = 1;i<=n;i++) {
        cin>>a[i];
        sum += a[i];
    }
    cout<<solve()<<endl;
	return 0;
}

