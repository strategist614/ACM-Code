  #include<bits/stdc++.h>
  using namespace std;
  typedef long long ll;
  ll n,k;
  ll a[100][100];
  ll c[100][100];
  ll b[100][100];
  int main ()
  {
    cin>>n>>k;
   for(ll i = 1;i <= n;i++)
     for(ll j = 1;j <= n;j++)
        {
          scanf("%lld",&a[i][j]);
          b[i][j] = a[i][j];
        }
  for(ll p = 1;p < k;p++)
   {
     for(ll i = 1;i<=n;i++)
      {
        for(ll j = 1;j<=n;j++)
          {
            ll ans = 0;
             for(ll t = 1;t<=n;t++)
                 ans += a[i][t]*b[t][j];
            c[i][j] = ans;
          }
      }
    for(int i = 1;i <= n;i++)
      for(int j = 1;j <= n;j++)
        b[i][j] = c[i][j];
    }
    cout<<b[1][n]<<endl;
    return  0;
  }
