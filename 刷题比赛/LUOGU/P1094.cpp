#include<bits/stdc++.h>
using namespace std;
int a[30005];
int main ()
{
  int n;
  scanf("%d",&n);
  int m;
  scanf("%d",&m);
  for(int i = 1;i<=m;i++) scanf("%d",&a[i]);
  sort(a+1,a+m+1);
  int ans =  0;
  for(int i = 1,j = m;i<=m/2 && j>=m/2;)
  {
    cout<<1;
    if(a[i] + a[j] <= n){
      ans++;
      i++;
      j--;
    }
    else
    {
      ans++;
      j--;
    }
  }
  cout<<ans<<endl;
  return 0 ;
}
