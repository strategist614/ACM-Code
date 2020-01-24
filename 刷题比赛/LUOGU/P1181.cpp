#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main ()
{
  int n,m;
  scanf("%d %d",&n,&m);
  for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
  int cnt = 1;
  int sum = 0;
  for(int i = 1;i<=n;i++)
  {
    sum += a[i];
    if(sum > m)
    {
      cnt++;
      sum = a[i];
    }
  }
  cout<<cnt<<endl;
  return 0 ;
}
