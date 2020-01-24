  #include<bits/stdc++.h>
  using namespace std;
  typedef long long ll;
  int a[1005];
  int main ()
  {
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ans = 0 ;
    for(int i = 1;i<=n;i++)
    {
      if(a[i+1] - a[i] > 1)
      {
        ans += a[i+1] - a[i] -1;
      }
    }
    cout<<ans<<endl;
    return 0 ;
  }
