#include<bits/stdc++.h>
using namespace std;
struct node
{
  int P;
  int A;
}a[2000005];
bool cmp(const node &a,const node &b)
{
  return a.P < b.P;
}
int main ()
{
  int n,m;
  scanf("%d %d",&n,&m);
  for(int i = 1;i<=m;i++) scanf("%d %d",&a[i].P,&a[i].A);
  sort(a+1,a+m+1,cmp);
  int ans = 0;
  for(int i = 1;i <= m;i++)
  {
    if(n <= a[i].A) ans += n*a[i].P;
    else ans += a[i].P*a[i].A;
    n -= a[i].A;
    if(n < 0)break;
  }
  cout<<ans<<endl;
  return 0 ;
}
